#ifndef LABEL_H
#define LABEL_H

#include "widget.h"
#include "gfx.h"

#define LABEL_MAX_CHARS     32

struct Label
{
    struct WidgetVMT *vmt;

    font_t font;
    char text[LABEL_MAX_CHARS];
    int needRedraw;
    uint8_t x, y;
};

void labelInit(struct Label *self, font_t font);

void labelSetText(struct Label *self, const char *text);
void labelSetFont(struct Label *self, font_t font);
void labelSetPosition(struct Label *self, uint8_t x, uint8_t y);

const char *labelText(const struct Label *self);
font_t labelFont(const struct Label *self);

#endif
