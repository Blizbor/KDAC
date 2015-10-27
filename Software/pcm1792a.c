#include "pcm1792a.h"

void pcm1792aInit(PCM1792ADriver *pcmp)
{
    pcmp->cfg = NULL;
}

void pcm1792aStart(PCM1792ADriver *pcmp, const PCM1792AConfig *cfg)
{
    pcmp->cfg = cfg;
}

msg_t pcm1792aWriteReg(PCM1792ADriver *pcmp, uint8_t address, uint8_t reg)
{
    uint8_t data[2] = {address & 0x7F, reg};

    i2cAcquireBus(pcmp->cfg->i2cp);
    msg_t result = i2cMasterTransmitTimeout(pcmp->cfg->i2cp, pcmp->cfg->address, data, 2, NULL, 0, pcmp->cfg->timeout);
    i2cReleaseBus(pcmp->cfg->i2cp);

    return result;
}

msg_t pcm1792aReadReg(PCM1792ADriver *pcmp, uint8_t address, uint8_t *reg)
{
    uint8_t txdata = address | 0x80;
    i2cAcquireBus(pcmp->cfg->i2cp);
    msg_t result = i2cMasterTransmitTimeout(pcmp->cfg->i2cp, pcmp->cfg->address, &txdata, 1, reg, 1, pcmp->cfg->timeout);
    i2cReleaseBus(pcmp->cfg->i2cp);

    return result;
}

msg_t pcm1792aUpdateReg(PCM1792ADriver *pcmp, uint8_t address, uint8_t mask, uint8_t reg)
{
    uint8_t regData;
    msg_t res;

    res = pcm1792aReadReg(pcmp, address, &regData);
    if (res)
        return res;

    regData = ((regData) & ~(mask)) | reg;

    return pcm1792aWriteReg(pcmp, address, regData);
}

msg_t pcm1792aPowerUp(PCM1792ADriver *pcmp)
{
    msg_t res = pcm1792aUpdateReg(pcmp, 0x13, PCM1792_REG13_INZD, 0);
    if (res)
        return res;
    res = pcm1792aUpdateReg(pcmp, 0x13, PCM1792_REG13_OPE, 0);
    if (res)
        return res;
    res = pcm1792aWriteReg(pcmp, 0x12, pcmp->cfg->audiofmt);
    return res;
}

msg_t pcm1792aPowerDown(PCM1792ADriver *pcmp)
{
    msg_t res = pcm1792aUpdateReg(pcmp, 0x13, PCM1792_REG13_INZD, PCM1792_REG13_INZD);
    if (res)
        return res;
    res = pcm1792aUpdateReg(pcmp, 0x13, PCM1792_REG13_OPE, PCM1792_REG13_OPE);
    return res;
}

msg_t pcm1792aSetAttenuation(PCM1792ADriver *pcmp, uint8_t mdb, bool right)
{
    return pcm1792aWriteReg(pcmp, right ? 0x11 : 0x10, mdb);
}

msg_t pcm1792aSetMute(PCM1792ADriver *pcmp, bool mute)
{
    return pcm1792aUpdateReg(pcmp, 0x12, PCM1792_REG12_MUTE, mute ? PCM1792_REG12_MUTE : 0);
}
