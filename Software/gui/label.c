#include "label.h"
#include "gfx.h"

#include <string.h>

void labelDraw(struct Widget *self, struct Manager *manager)
{
    struct Label *label = (struct Label*)self;
    gdispDrawString(label->x, label->y, label->text, label->font, White);
    label->needRedraw = false;
}

int labelNeedRedraw(const struct Widget *self)
{
    const struct Label *label = (const struct Label*)self;
    return label->needRedraw;
}

struct WidgetVMT labelVMT = {labelDraw, NULL, NULL, labelNeedRedraw};

void labelInit(struct Label *self, font_t font)
{
    self->vmt = &labelVMT;
    self->font = font;
    self->needRedraw = true;
    self->x = 0;
    self->y = 0;
}

void labelSetText(struct Label *self, const char *text)
{
    int len = strlen(text);
    if (len > LABEL_MAX_CHARS - 1)
        len = LABEL_MAX_CHARS - 1;

    memcpy(self->text, text, len);
    self->text[len] = '\0';
    self->needRedraw = true;
}

void labelSetFont(struct Label *self, font_t font)
{
    self->font = font;
    self->needRedraw = true;
}

void labelSetPosition(struct Label *self, uint8_t x, uint8_t y)
{
    self->x = x;
    self->y = y;
    self->needRedraw = true;
}

