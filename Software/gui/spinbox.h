#ifndef SPINBOX_H
#define SPINBOX_H

#include "widget.h"
#include "label.h"
#include "gfx.h"

struct SpinBox
{
    struct WidgetVMT *vmt;

    struct Label titleLabel;
    struct Label valueLabel;
    bool editable;
    int min, max, step;
    int value;

    void (*update)(struct SpinBox* box);
    void (*callback)(struct SpinBox* box, int value);
};

void spinBoxInit(struct SpinBox *self, font_t titleFont, font_t valueFont, bool editable,
                 void (*update)(struct SpinBox* box), void (*callback)(struct SpinBox* box, int value));

void spinBoxSetTitle(struct SpinBox *self, const char *text);
void spinBoxSetValue(struct SpinBox *self, int value);
void spinBoxSetRange(struct SpinBox *self, int min, int max, int step);

#endif
