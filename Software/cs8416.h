#ifndef CS8416_H
#define CS8416_H

#include "hal.h"

#define CS8416_I2C_BASE_ADDRESS     0x10
#define CS8416_I2C_ADDRESS(x)       (CS8416_I2C_BASE_ADDRESS | (x & 0x7))

#define CS8416_REG_CONTROL0         0x00
#define CS8416_REG_CONTROL1         0x01
#define CS8416_REG_CONTROL2         0x02
#define CS8416_REG_CONTROL3         0x03
#define CS8416_REG_CONTROL4         0x04

#define CS8416_CONTROL0_TRUNC       (1 << 2)
#define CS8416_CONTROL0_PDUR        (1 << 3)
#define CS8416_CONTROL0_FSWCLK      (1 << 6)

#define CS8416_CONTROL1_CHS         (1 << 0)
#define CS8416_CONTROL1_RMCKF       (1 << 1)
#define CS8416_CONTROL1_HOLD(x)     (((x) & 0x3) << 2)
#define CS8416_CONTROL1_INT(x)      (((x) & 0x3) << 4)
#define CS8416_CONTROL1_MUTESAO     (1 << 6)
#define CS8416_CONTROL1_SWCLK       (1 << 7)

#define CS8416_CONTROL2_GPO0SEL(x)  (((x) & 0xF) << 0)
#define CS8416_CONTROL2_EMPH_CTL(x) (((x) & 0x7) << 4)
#define CS8416_CONTROL2_DETCI       (1 << 7)

#define CS8416_CONTROL3_GPO2SEL(x)  (((x) & 0xF) << 0)
#define CS8416_CONTROL3_GPO1SEL(x)  (((x) & 0xF) << 4)

#define CS8416_CONTROL4_TXSEL(x)    (((x) & 0x7) << 0)
#define CS8416_CONTROL4_RXSEL(x)    (((x) & 0x7) << 3)
#define CS8416_CONTROL4_RXD         (1 << 6)
#define CS8416_CONTROL4_RUN         (1 << 7)

typedef struct
{
    I2CDriver *i2cp;
    uint8_t address;
    systime_t timeout;
} CS8416Config;

typedef struct
{
    const CS8416Config *cfg;
} CS8416Driver;

void cs8416Init(CS8416Driver *csp);
void cs8416Start(CS8416Driver *csp, const CS8416Config *cfg);

msg_t cs8416WriteReg(CS8416Driver *csp, uint8_t address, uint8_t reg);
msg_t cs8416ReadReg(CS8416Driver *csp, uint8_t address, uint8_t *reg);
msg_t cs8416UpdateReg(CS8416Driver *csp, uint8_t address, uint8_t mask, uint8_t reg);

msg_t cs8416PowerUp(CS8416Driver *csp);
msg_t cs8416PowerDown(CS8416Driver *csp);

msg_t cs8416SelectInput(CS8416Driver *csp, uint8_t input);

#endif // CS8416_H
