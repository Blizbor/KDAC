#ifndef SYSTEM_H
#define SYSTEM_H

#include "hal.h"
#include "pcm1792a.h"
#include "cs8416.h"

#define SPDIF_COAXIAL_INPUT     0
#define SPDIF_OPTICAL_INPUT     1

#define DEFAULT_VOLUME          192

typedef enum {DAC_SOURCE_NONE = 0, DAC_SOURCE_SPDIF, DAC_SOURCE_MCU} DACSource;
typedef enum {AUDIO_SOURCE_NONE = 0, AUDIO_SOURCE_USB, AUDIO_SOURCE_COAXIAL, AUDIO_SOURCE_OPTICAL} AudioSource;

typedef struct
{
    CS8416Driver *spdifp;
    PCM1792ADriver *dacp;
} SystemConfig;

typedef struct
{
    const SystemConfig *config;
    DACSource dac_source;
    AudioSource audio_source;
    uint32_t sof_feedback;
    uint8_t volume;
} SystemState;

void systemInit(SystemState *sysp);
void systemStart(SystemState *sysp, const SystemConfig *cfg);

void systemStartMCKCapture(SystemState *sysp);
void systemStopMCKCapture(SystemState *sysp);

int systemMCKValueKHz(SystemState *sysp);

void systemSwitchDACSource(SystemState *sysp, DACSource source);
void systemSwitchAudioSource(SystemState *sysp, AudioSource source);

void systemSetVolume(SystemState *sysp, uint8_t volume);

#endif
