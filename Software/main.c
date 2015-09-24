#include "hal.h"
#include "usbcfg.h"

#include "gui/gui.h"
#include "system.h"

SerialUSBDriver SDU1;

static const I2CConfig i2cfg =
{
    OPMODE_I2C,
    400000,
    FAST_DUTY_CYCLE_2,
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

    palSetPad(GPIOC, GPIOC_MCK_EN);

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
}
