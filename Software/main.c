#include "hal.h"
#include "usb_audio.h"

#include "gui/gui.h"
#include "system.h"

#include "drivers.h"

CS8416Driver spdif;
PCM1792ADriver dac;

static const I2CConfig i2cfg =
{
    OPMODE_I2C,
    400000,
    FAST_DUTY_CYCLE_2,
};

static const CS8416Config spdifcfg =
{
    &I2CD1,
    CS8416_I2C_ADDRESS(0x0),
    100,
    // Master mode, 24 bit I2S, 64 x Fs
    CS8416_AFMT_SOMS | CS8416_AFMT_SODEL
};

static const PCM1792AConfig daccfg =
{
    &I2CD1,
    PCM1792A_I2C_ADDRESS(0x0),
    100,
    // Volume control, 24 bit I2S,
    PCM1792_REG12_ATLD | PCM1792_REG12_FMT(0x5)
};

static const SystemConfig syscfg =
{
    &spdif,
    &dac
};

int main(void)
{
    halInit();
    chSysInit();

    i2cStart(&I2CD1, &i2cfg);

    cs8416Init(&spdif);
    cs8416Start(&spdif, &spdifcfg);

    cs8416PowerUp(&spdif);

    pcm1792aInit(&dac);
    pcm1792aStart(&dac, &daccfg);

    systemInit(&system);
    systemStart(&system, &syscfg);

    systemSwitchAudioSource(&system, AUDIO_SOURCE_USB);
    //systemSwitchDACSource(&system, DAC_SOURCE_SPDIF);

    startGUI();

    usbAudio();
}
