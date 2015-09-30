#include "system.h"
#include "hal.h"

#define MCK_FB_INTEG    256
#define MCK_FB_DIV      4

static volatile uint32_t sofFeedback = 0;
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
                sofFeedback = sofDelta;
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

void startMCKCapture()
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
}

void stopMCKCapture()
{
    chSysLock();
    nvicDisableVector(STM32_TIM11_NUMBER);
    TIM1->CR1 = 0;
    TIM2->CR1 = 0;
    chSysUnlock();
    sofFeedback = 0;
}

int mckValueKHz()
{
    return sofFeedback * MCK_FB_DIV / MCK_FB_INTEG;
}