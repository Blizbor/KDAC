#include "menu.h"
#include "manager.h"
#include "gfx.h"

void menuDraw(struct Widget *self, struct Manager *manager)
{
    struct Menu *menu = (struct Menu*)self;

    for (int i = menu->offset; (i < menu->count) && (i < menu->offset + 4); i++)
    {
        gdispDrawString(2, (i - menu->offset) * 16 + 1, menu->items[i].title, menu->font, White);
        if (i == menu->selected)
            gdispDrawBox(0, (i - menu->offset) * 16, 128, 14, White);
    }
    if (menu->offset >= menu->count - 3)
    {
        gdispDrawString(2, 3 * 16 + 1, "< Back", menu->font, White);
        if (menu->selected == menu->count)
            gdispDrawBox(0, 48, 128, 14, White);
    }
    menu->needRedraw = false;
}

void menuAction(struct Widget *self, struct Manager *manager, struct Action action)
{
    struct Menu *menu = (struct Menu*)self;
    if (action.type == ACTION_UP)
    {
        menu->selected -= action.param;
        menu->selected = (menu->selected < 0) ? 0 : menu->selected;
        menu->needRedraw = true;
    }
    else if (action.type == ACTION_DOWN)
    {
        menu->selected += action.param;
        menu->selected = (menu->selected > menu->count) ? menu->count : menu->selected;
        menu->needRedraw = true;
    }
    else if (action.type == ACTION_ENTER)
    {
        if (menu->selected == menu->count)
            managerPopWidget(manager);
        else if (menu->items[menu->selected].widget)
            managerPushWidget(manager, menu->items[menu->selected].widget);
    }

    if (menu->selected - menu->offset > 3)
        menu->offset += (menu->selected - menu->offset) - 3;
    if (menu->selected - menu->offset < 0)
        menu->offset += (menu->selected - menu->offset);
}

int menuNeedRedraw(const struct Widget *self)
{
    const struct Menu *menu = (const struct Menu*)self;
    return menu->needRedraw;
}

struct WidgetVMT menuVMT = {menuDraw, menuAction, NULL, menuNeedRedraw};

void menuInit(struct Menu *self, const struct MenuItem *items, int count, font_t font)
{
    self->vmt = &menuVMT;
    self->items = items;
    self->count = count;
    self->offset = 0;
    self->selected = 0;
    self->font = font;
    self->needRedraw = true;
}
