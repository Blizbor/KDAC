#ifndef _GDISP_LLD_BOARD_H
#define _GDISP_LLD_BOARD_H

#define SSD1306_I2C_ADDRESS   	0x3C
#define SSD1306_PAGE_PREFIX	0x40
#define SSD1306_SH1106          TRUE

static inline void init_board(GDisplay *g)
{
}

static inline void post_init_board(GDisplay *g)
{
    (void) g;
}

static inline void setpin_reset(GDisplay *g, bool_t state)
{
    (void) g;
    (void) state;
}

static inline void acquire_bus(GDisplay *g)
{
    (void) g;
    i2cAcquireBus(&I2CD1);
}

static inline void release_bus(GDisplay *g)
{
    (void) g;
    i2cReleaseBus(&I2CD1);
}

static inline void write_cmd(GDisplay *g, uint8_t cmd)
{
    uint8_t command[2];
    (void) g;

    command[0] = 0x00;		// Co = 0, D/C = 0
    command[1] = cmd;

    i2cMasterTransmitTimeout(&I2CD1, SSD1306_I2C_ADDRESS, command, 2, 0, 0, MS2ST(10));
}

static inline void write_data(GDisplay *g, uint8_t* data, uint16_t length)
{
    (void) g;

    i2cMasterTransmitTimeout(&I2CD1, SSD1306_I2C_ADDRESS, data, length, 0, 0, MS2ST(10));
}

#endif /* _GDISP_LLD_BOARD_H */


