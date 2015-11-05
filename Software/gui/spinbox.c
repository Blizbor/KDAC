#include "spinbox.h"
#include "manager.h"
#include "gfx.h"

#include "chprintf.h"
#include <string.h>

void spinboxDraw(struct Widget *self, struct Manager *manager)
{
    struct SpinBox *box = (struct SpinBox*)self;
    box->titleLabel.vmt->draw((struct Widget*)&box->titleLabel, manager);
    box->valueLabel.vmt->draw((struct Widget*)&box->valueLabel, manager);
}

void spinboxAction(struct Widget *self, struct Manager *manager, struct Action action)
{
    struct SpinBox *box = (struct SpinBox*)self;

    if (box->editable)
    {
        if (action.type == ACTION_DOWN)
            spinBoxSetValue(box, box->value - action.param * box->step);
        else if (action.type == ACTION_UP)
            spinBoxSetValue(box, box->value + action.param * box->step);

        if (box->callback)
            box->callback(box, box->value);
    }

    if (action.type == ACTION_ENTER)
        managerPopWidget(manager);
}

void spinboxUpdate(struct Widget *self, struct Manager *manager, int dt)
{
    struct SpinBox *box = (struct SpinBox*)self;
    if (box->update)
        box->update(box);
}

int spinboxNeedRedraw(const struct Widget *self)
{
    const struct SpinBox *box = (const struct SpinBox*)self;
    return box->titleLabel.vmt->needRedraw((struct Widget*)&box->titleLabel) ||
           box->valueLabel.vmt->needRedraw((struct Widget*)&box->valueLabel);
}

struct WidgetVMT spinboxVMT = {spinboxDraw, spinboxAction, spinboxUpdate, spinboxNeedRedraw};

void spinBoxInit(struct SpinBox *self, font_t titleFont, font_t valueFont, bool editable,
                 void (*update)(struct SpinBox* box), void (*callback)(struct SpinBox* box, int value))
{
    self->editable = editable;
    self->min = INT32_MIN;
    self->max = INT32_MAX;
    self->step = 1;
    self->vmt = &spinboxVMT;
    self->update = update;
    self->callback = callback;
    self->value = -1;

    labelInit(&self->titleLabel, titleFont);
    labelInit(&self->valueLabel, valueFont);
    spinBoxSetTitle(self, "");
    spinBoxSetValue(self, 0);
}

void spinBoxSetTitle(struct SpinBox *self, const char *text)
{
    labelSetText(&self->titleLabel, text);
    int w = gdispGetStringWidth(labelText(&self->titleLabel), labelFont(&self->titleLabel));
    labelSetPosition(&self->titleLabel, (128 - w) / 2, 2);
}

void spinBoxSetValue(struct SpinBox *self, int value)
{
    if (self->value != value)
    {
        self->value = value > self->max ? self->max : (value < self->min ? self->min : value);
        char str[LABEL_MAX_CHARS];
        chsnprintf(str, LABEL_MAX_CHARS, "%d", self->value);
        labelSetText(&self->valueLabel, str);
        int w = gdispGetStringWidth(labelText(&self->valueLabel), labelFont(&self->valueLabel));
        labelSetPosition(&self->valueLabel, (128 - w) / 2, 27);
    }
}

void spinBoxSetRange(struct SpinBox *self, int min, int max, int step)
{
    if (min > max)
        return;

    self->min = min;
    self->max = max;
    self->step = step;
}
