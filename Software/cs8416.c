#include "cs8416.h"


void cs8416Init(CS8416Driver *csp)
{
    csp->cfg = NULL;
}

void cs8416Start(CS8416Driver *csp, const CS8416Config *cfg)
{
    csp->cfg = cfg;
}

msg_t cs8416WriteReg(CS8416Driver *csp, uint8_t address, uint8_t reg)
{
    uint8_t data[2] = {address, reg};

    i2cAcquireBus(csp->cfg->i2cp);
    msg_t result = i2cMasterTransmitTimeout(csp->cfg->i2cp, csp->cfg->address, data, 2, NULL, 0, csp->cfg->timeout);
    i2cReleaseBus(csp->cfg->i2cp);

    return result;
}

msg_t cs8416ReadReg(CS8416Driver *csp, uint8_t address, uint8_t *reg)
{
    i2cAcquireBus(csp->cfg->i2cp);
    msg_t result = i2cMasterTransmitTimeout(csp->cfg->i2cp, csp->cfg->address, &address, 1, reg, 1, csp->cfg->timeout);
    i2cReleaseBus(csp->cfg->i2cp);

    return result;
}

msg_t cs8416UpdateReg(CS8416Driver *csp, uint8_t address, uint8_t mask, uint8_t reg)
{
    uint8_t regData;
    msg_t res;

    res = cs8416ReadReg(csp, address, &regData);
    if (res)
        return res;

    regData = ((regData) & ~(mask)) | reg;

    return cs8416WriteReg(csp, address, regData);
}

msg_t cs8416PowerUp(CS8416Driver *csp)
{
    return cs8416UpdateReg(csp, CS8416_REG_CONTROL4, CS8416_CONTROL4_RUN, CS8416_CONTROL4_RUN);
}

msg_t cs8416PowerDown(CS8416Driver *csp)
{
    return cs8416UpdateReg(csp, CS8416_REG_CONTROL4, CS8416_CONTROL4_RUN, 0);
}

msg_t cs8416SelectInput(CS8416Driver *csp, uint8_t input)
{
    if (input > 7)
        return -1;

    return cs8416UpdateReg(csp, CS8416_REG_CONTROL4, CS8416_CONTROL4_RXSEL(0xFF), CS8416_CONTROL4_RXSEL(input));
}
