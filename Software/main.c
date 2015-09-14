#include "hal.h"

int main(void)
{
    halInit();
    chSysInit();

    palSetPad(GPIOC, GPIOC_MCK_EN);

    for (;;)
    {
        chThdSleepMilliseconds(1000);
    }
}
