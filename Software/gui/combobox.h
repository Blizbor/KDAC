#ifndef COMBOBOX_H
#define COMBOBOX_H

#include "menu.h"

struct ComboBoxItem
{
    const char *name;
    int value;
};

struct ComboBox
{
    struct WidgetVMT *vmt;

    const struct ComboBoxItem *items;
    int count;
    int offset;
    int selected;
    font_t font;
    int needRedraw;
    int index;

    void (*update)(struct ComboBox* box);
    void (*callback)(struct ComboBox* box, int value);
};

void comboBoxInit(struct ComboBox *self, const struct ComboBoxItem *items, int count, font_t font,
                  void (*update)(struct ComboBox* box), void (*callback)(struct ComboBox* box, int value));

void comboBoxSelect(struct ComboBox *self, int index);

#endif
