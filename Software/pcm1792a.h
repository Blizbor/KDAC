#ifndef PCM1792A_H
#define PCM1792A_H

#include "hal.h"

#define PCM1792A_I2C_BASE_ADDRESS   0x4C
#define PCM1792A_I2C_ADDRESS(x)     (PCM1792A_I2C_BASE_ADDRESS | (x & 0x3))

#define PCM1792_REG12_ATLD          (1 << 7)
#define PCM1792_REG12_FMT(x)        ((x & 0x7) << 4)
#define PCM1792_REG12_DMF(x)        ((x & 0x3) << 2)
#define PCM1792_REG12_DME           (1 << 1)
#define PCM1792_REG12_MUTE          (1 << 0)

#define PCM1792_REG13_REV           (1 << 7)
#define PCM1792_REG13_ATS(x)        ((x & 0x3) << 5)
#define PCM1792_REG13_OPE           (1 << 4)
#define PCM1792_REG13_RSV           (1 << 3)
#define PCM1792_REG13_DFMS          (1 << 2)
#define PCM1792_REG13_FLT           (1 << 1)
#define PCM1792_REG13_INZD          (1 << 0)

typedef struct
{
    I2CDriver *i2cp;
    uint8_t address;
    systime_t timeout;
    //! Contents of reg 0x18
    uint8_t audiofmt;
} PCM1792AConfig;

typedef struct
{
    const PCM1792AConfig *cfg;
} PCM1792ADriver;

void pcm1792aInit(PCM1792ADriver *pcmp);
void pcm1792aStart(PCM1792ADriver *pcmp, const PCM1792AConfig *cfg);

msg_t pcm1792aWriteReg(PCM1792ADriver *pcmp, uint8_t address, uint8_t reg);
msg_t pcm1792aReadReg(PCM1792ADriver *pcmp, uint8_t address, uint8_t *reg);
msg_t pcm1792aUpdateReg(PCM1792ADriver *pcmp, uint8_t address, uint8_t mask, uint8_t reg);

msg_t pcm1792aPowerUp(PCM1792ADriver *pcmp);
msg_t pcm1792aPowerDown(PCM1792ADriver *pcmp);

//! db - db (in 0.5 db units) 0(14) = -120 db, 255 = 0 db
msg_t pcm1792aSetAttenuation(PCM1792ADriver *pcmp, uint8_t db, bool right);

msg_t pcm1792aSetMute(PCM1792ADriver *pcmp, bool mute);


#endif // PCM1792A_H
