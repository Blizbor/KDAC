#ifndef WIDGET_H
#define WIDGET_H

#include <stdint.h>

struct Manager;
struct Widget;

enum ActionType {ACTION_UP, ACTION_DOWN, ACTION_ENTER};

struct Action
{
    enum ActionType type;
    uint16_t param;
};

struct WidgetVMT
{
    void (*draw)(struct Widget *self, struct Manager *manager);
    void (*action)(struct Widget *self, struct Manager *manager, struct Action action);
    void (*update)(struct Widget *self, struct Manager *manager, int dt);
    int (*needRedraw)(const struct Widget *self);
};

struct Widget
{
    struct WidgetVMT *vmt;
};

#endif
