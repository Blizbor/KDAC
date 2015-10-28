#include "system.h"
#include "hal.h"
#include "drivers.h"

#define MCK_FB_INTEG    256
#define MCK_FB_DIV      4

static SystemState *fbSysp = 0;
static volatile uint16_t sofLastCounter = 0;
static volatile uint32_t sofDelta = 0;
static volatile bool sofFirst = true;
static volatile int sofDeltaCount = 0;

OSAL_IRQ_HANDLER(STM32_TIM11_HANDLER)
{
    OSAL_IRQ_PROLOGUE();

    uint16_t value = TIM1->CNT;
    uint32_t sr = TIM1->SR;
    TIM1->SR = 0;

    if (sr & TIM_SR_TIF)
    {
        chSysLockFromISR();
        if (!sofFirst)
        {
            if (sofLastCounter < value)
                sofDelta += value - sofLastCounter;
            else
                sofDelta += UINT16_MAX - sofLastCounter + value;

            if (sofDeltaCount == MCK_FB_INTEG - 1)
            {
                fbSysp->sof_feedback = sofDelta;
                sofDelta = 0;
                sofDeltaCount = 0;
            }
            else
            {
                sofDeltaCount++;
            }
        }
        sofFirst = false;
        sofLastCounter = value;
        chSysUnlockFromISR();
    }

    OSAL_IRQ_EPILOGUE();
}

void systemInit(SystemState *sysp)
{
    sysp->audio_source = AUDIO_SOURCE_USB + 1;
    sysp->config = 0;
    sysp->dac_source = DAC_SOURCE_MCU + 1;
    sysp->sof_feedback = 0;
    sysp->volume = 0;
}

void systemStart(SystemState *sysp, const SystemConfig *cfg)
{
    sysp->config = cfg;
    systemSwitchAudioSource(sysp, AUDIO_SOURCE_NONE);
    systemSetVolume(sysp, DEFAULT_VOLUME);
}

void systemStartMCKCapture(SystemState *sysp)
{
    rccEnableTIM1(FALSE);
    rccEnableTIM2(FALSE);

    rccResetTIM2();
    rccResetTIM1();
    nvicEnableVector(STM32_TIM11_NUMBER, STM32_GPT_TIM1_IRQ_PRIORITY);

    chSysLock();
    // TIM2 reset on TI1 (= OTG2 SOF), and generate TRGO
    TIM2->CR1 = TIM_CR1_CEN;
    TIM2->SMCR = TIM_SMCR_TS_0 | TIM_SMCR_MSM | TIM_SMCR_SMS_2;
    TIM2->OR = TIM_OR_ITR1_RMP_1 | TIM_OR_ITR1_RMP_0;

    // TIM1 - count on MCK / 4 (12.288 MHz), trigger on TI1 (= TIM2 event = SOF)
    TIM1->CR1 = TIM_CR1_CEN;
    TIM1->SMCR = TIM_SMCR_ECE | TIM_SMCR_ETPS_1 | TIM_SMCR_TS_0 | TIM_SMCR_SMS_2 | TIM_SMCR_SMS_1;
    TIM1->DIER = TIM_DIER_TIE;
    chSysUnlock();

    fbSysp = sysp;
    sysp->sof_feedback = 0;
}

void systemStopMCKCapture(SystemState *sysp)
{
    chSysLock();
    nvicDisableVector(STM32_TIM11_NUMBER);
    TIM1->CR1 = 0;
    TIM2->CR1 = 0;
    chSysUnlock();

    sysp->sof_feedback = 0;
}

int systemMCKValueKHz(SystemState *sysp)
{
    return sysp->sof_feedback * MCK_FB_DIV / MCK_FB_INTEG;
}

void systemSwitchDACSource(SystemState *sysp, DACSource source)
{
    if (sysp->dac_source == source)
        return;

    pcm1792aPowerDown(sysp->config->dacp);

    if (source != DAC_SOURCE_SPDIF)
    {
        // Disable MCK from S/PDIF receiver
        cs8416ToggleMCK(sysp->config->spdifp, false);
        // Switch I2S mux to MCU's I2S
        palSetPad(GPIOC, GPIOC_I2S_SEL);
        // Enable MCK from external XCO
        palSetPad(GPIOC, GPIOC_MCK_EN);
    }
    else
    {
        // Disable MCK from external XCO
        palClearPad(GPIOC, GPIOC_MCK_EN);
        // Switch I2S mux to S/PDIF receiver I2S
        palClearPad(GPIOC, GPIOC_I2S_SEL);
        // Enable MCK from S/PDIF receiver
        cs8416ToggleMCK(sysp->config->spdifp, true);
    }

    osalThreadSleepMilliseconds(1000);

    if (source != DAC_SOURCE_NONE)
    {
        // status != 0 => PLL isn't locked yet
        // FIXME: GUI will freeze on that
        msg_t status;
        do
        {
            osalThreadSleepMilliseconds(100);
            status = pcm1792aPowerUp(sysp->config->dacp);
        }
        while (status);
    }

    sysp->dac_source = source;
}

void systemSwitchAudioSource(SystemState *sysp, AudioSource source)
{
    if (sysp->audio_source == source)
        return;

    switch (source)
    {
    case AUDIO_SOURCE_NONE:
        systemSwitchDACSource(sysp, DAC_SOURCE_NONE);
        break;

    case AUDIO_SOURCE_OPTICAL:
        cs8416SelectInput(sysp->config->spdifp, SPDIF_OPTICAL_INPUT);
        systemSwitchDACSource(sysp, DAC_SOURCE_SPDIF);
        break;

    case AUDIO_SOURCE_COAXIAL:
        cs8416SelectInput(sysp->config->spdifp, SPDIF_COAXIAL_INPUT);
        systemSwitchDACSource(sysp, DAC_SOURCE_SPDIF);
        break;

    case AUDIO_SOURCE_USB:
        systemSwitchDACSource(sysp, DAC_SOURCE_MCU);
        break;
    }

    sysp->audio_source = source;
}

void systemSetVolume(SystemState *sysp, uint8_t volume)
{
    if (volume == sysp->volume)
        return;

    pcm1792aSetAttenuation(sysp->config->dacp, volume, false);
    pcm1792aSetAttenuation(sysp->config->dacp, volume, true);

    sysp->volume = volume;
}
