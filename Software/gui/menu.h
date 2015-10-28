#ifndef MENU_H
#define MENU_H

#include "widget.h"
#include "gfx.h"

struct MenuItem
{
    const char *title;
    struct Widget *widget;
};

struct Menu
{
    struct WidgetVMT *vmt;

    const struct MenuItem *items;
    int count;
    int offset;
    int selected;
    font_t font;
    int needRedraw;
};

void menuInit(struct Menu *self, const struct MenuItem *items, int count, font_t font);

#endif
