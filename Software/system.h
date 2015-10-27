#ifndef SYSTEM_H
#define SYSTEM_H

#define SPDIF_COAXIAL_INPUT     0
#define SPDIF_OPTICAL_INPUT     1

typedef enum {DAC_SOURCE_NONE, DAC_SOURCE_SPDIF, DAC_SOURCE_MCU} DACSource;
typedef enum {AUDIO_SOURCE_NONE, AUDIO_SOURCE_OPTICAL, AUDIO_SOURCE_COAXIAL, AUDIO_SOURCE_USB} AudioSource;

void startMCKCapture();
void stopMCKCapture();

int mckValueKHz();

void switchDACSource(DACSource source);
void switchAudioSource(AudioSource source);

#endif
