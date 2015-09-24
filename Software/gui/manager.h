#ifndef MANAGER_H
#define MANAGER_H

#include "hal.h"

#define MAX_WIDGET_STACK    8

struct Widget;

struct Manager
{
    struct Widget* stack[MAX_WIDGET_STACK];
    uint8_t top;
    TIM_TypeDef *tim;
    int16_t lastTimCounter;
    char wasPressed;
    bool pushPopped;
};

void managerInit(struct Manager* m, TIM_TypeDef *tim);
void managerStart(struct Manager* m);
void managerPushWidget(struct Manager* m, struct Widget *w);
void managerPopWidget(struct Manager* m);

void managerUpdate(struct Manager* m, int dt);

#endif
