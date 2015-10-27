#include "hal.h"
#include "usbcfg.h"

#include "gui/gui.h"
#include "system.h"

#include "drivers.h"

static const I2CConfig i2cfg =
{
    OPMODE_I2C,
    400000,
    FAST_DUTY_CYCLE_2,
};

static const CS8416Config spdifcfg =
{
    &I2CD1,
    CS8416_I2C_ADDRESS(0x4),
    100,
    // Master mode, 24 bit I2S, 64 x Fs
    CS8416_AFMT_SOMS | CS8416_AFMT_SODEL
};

int main(void)
{
    halInit();
    chSysInit();

    sduObjectInit(&SDU1);
    sduStart(&SDU1, &serusbcfg);

    i2cStart(&I2CD1, &i2cfg);

    usbDisconnectBus(serusbcfg.usbp);
    chThdSleepMilliseconds(1500);
    usbStart(serusbcfg.usbp, &usbcfg);
    usbConnectBus(serusbcfg.usbp);

    cs8416Init(&spdif);
    cs8416Start(&spdif, &spdifcfg);

    cs8416PowerUp(&spdif);

    switchAudioSource(AUDIO_SOURCE_OPTICAL);

    startGUI();

    bool capture = false;

    for (;;)
    {
        if (SDU1.config->usbp->state == USB_ACTIVE && capture == false)
        {
            startMCKCapture();
            capture = true;
        }
        else if (SDU1.config->usbp->state != USB_ACTIVE && capture == true)
        {
            stopMCKCapture();
            capture = false;
        }
        chThdSleepMilliseconds(1000);
    }
    for (;;);
}
