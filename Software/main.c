#include "hal.h"
#include "usbcfg.h"

#include "gui/gui.h"
#include "system.h"
#include "cs8416.h"

SerialUSBDriver SDU1;

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
    100
};

static CS8416Driver spdif;

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
    cs8416SelectInput(&spdif, 1);

    cs8416UpdateReg(&spdif, CS8416_REG_CONTROL1, CS8416_CONTROL1_RMCKF, CS8416_CONTROL1_RMCKF);

    //palSetPad(GPIOC, GPIOC_MCK_EN);

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
