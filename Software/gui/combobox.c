#include "combobox.h"
#include "gfx.h"
#include "gdisp.h"
#include "manager.h"

void comboboxDraw(struct Widget *self, struct Manager *manager)
{
    struct ComboBox *cb = (struct ComboBox*)self;

    for (int i = cb->offset; (i < cb->count) && (i < cb->offset + 4); i++)
    {
        if (i == cb->index)
            gdispFillCircle(6, (i - cb->offset) * 16 + 6, 4, White);
        else
            gdispDrawCircle(6, (i - cb->offset) * 16 + 6, 4, White);

        gdispDrawString(12, (i - cb->offset) * 16 + 1, cb->items[i].name, cb->font, White);
        if (i == cb->selected)
            gdispDrawBox(0, (i - cb->offset) * 16, 128, 14, White);
    }
    if (cb->offset >= cb->count - 3)
    {
        gdispDrawString(2, 3 * 16 + 1, "< Back", cb->font, White);
        if (cb->selected == cb->count)
            gdispDrawBox(0, 48, 128, 14, White);
    }
    cb->needRedraw = false;
}

void comboboxAction(struct Widget *self, struct Manager *manager, struct Action action)
{
    struct ComboBox *cb = (struct ComboBox*)self;
    if (action.type == ACTION_UP)
    {
        cb->selected -= action.param;
        cb->selected = (cb->selected < 0) ? 0 : cb->selected;
        cb->needRedraw = true;
    }
    else if (action.type == ACTION_DOWN)
    {
        cb->selected += action.param;
        cb->selected = (cb->selected > cb->count) ? cb->count : cb->selected;
        cb->needRedraw = true;
    }
    else if (action.type == ACTION_ENTER)
    {
        if (cb->selected == cb->count)
            managerPopWidget(manager);
        else
        {
            comboBoxSelect(cb, cb->selected);
            if (cb->callback)
                cb->callback(cb, cb->items[cb->index].value);
        }
    }

    if (cb->selected - cb->offset > 3)
        cb->offset += (cb->selected - cb->offset) - 3;
    if (cb->selected - cb->offset < 0)
        cb->offset += (cb->selected - cb->offset);
}

int comboboxNeedRedraw(const struct Widget *self)
{
    struct ComboBox *cb = (struct ComboBox*)self;
    return cb->needRedraw;
}

void comboboxUpdate(struct Widget *self, struct Manager *manager, int dt)
{
    struct ComboBox *cb = (struct ComboBox*)self;
    if (cb->update)
        cb->update(cb);
}

struct WidgetVMT cbVMT = {comboboxDraw, comboboxAction, comboboxUpdate, comboboxNeedRedraw};

void comboBoxInit(struct ComboBox *self, const struct ComboBoxItem *items, int count, font_t font,
                  void (*update)(struct ComboBox* box), void (*callback)(struct ComboBox* box, int value))
{
    self->vmt = &cbVMT;
    self->items = items;
    self->count = count;
    self->offset = 0;
    self->selected = 0;
    self->index = 0;
    self->font = font;
    self->needRedraw = true;
    self->update = update;
    self->callback = callback;
}

void comboBoxSelect(struct ComboBox *self, int index)
{
    if (self->index == index)
        return;

    self->index = index;
    self->needRedraw = true;
}
