#include "manager.h"
#include "widget.h"
#include "gfx.h"
#include "hal.h"

void managerInit(struct Manager* m, TIM_TypeDef *tim)
{
    m->top = 0;
    m->tim = tim;
    m->wasPressed = 0;
}

void managerStart(struct Manager* m)
{
    chSysLock();
    m->tim->CR1 = TIM_CR1_CEN;
    // Encoder mode
    m->tim->SMCR = TIM_SMCR_SMS_1 | TIM_SMCR_SMS_0;
    // CH1, CH2 - input capture, max prescale, max filtering
    m->tim->CCMR1 = TIM_CCMR1_CC1S_0 | TIM_CCMR1_IC1PSC_0 | TIM_CCMR1_IC1PSC_1 | TIM_CCMR1_IC1F_0 | TIM_CCMR1_IC1F_1 | TIM_CCMR1_IC1F_2 |
                    TIM_CCMR1_CC2S_0 | TIM_CCMR1_IC2PSC_0 | TIM_CCMR1_IC2PSC_1 | TIM_CCMR1_IC2F_0 | TIM_CCMR1_IC2F_1 | TIM_CCMR1_IC2F_2;
    // CH1, CH2 inverted
    m->tim->CCER = TIM_CCER_CC2E | TIM_CCER_CC2P | TIM_CCER_CC1E | TIM_CCER_CC1P;
    m->lastTimCounter = (int16_t)m->tim->CNT;
    chSysUnlock();
}

void managerPushWidget(struct Manager* m, struct Widget *w)
{
    if (m->top > MAX_WIDGET_STACK - 1)
        return;

    m->stack[m->top] = w;
    m->top++;
}

void managerPopWidget(struct Manager* m)
{
    if (m->top == 0)
        return;

    m->top--;
}

void managerUpdate(struct Manager* m, int dt)
{
    int16_t d = ((int16_t)m->tim->CNT - m->lastTimCounter) / 4;

    struct Widget *current = 0;

    if (m->top > 0)
        current = m->stack[m->top - 1];

    char pressed = !palReadPad(GPIOD, GPIOD_ENCODER_CLICK);

    if (pressed && pressed != m->wasPressed)
    {
        struct Action a;
        a.type = ACTION_ENTER;
        if (current && (current->vmt->action))
            current->vmt->action(current, m, a);
    }

    if (d)
    {
        struct Action a;
        a.type = (d > 0) ? ACTION_UP : ACTION_DOWN;
        a.param = (d > 0) ? d : -d;
        m->lastTimCounter = m->tim->CNT;
        if (current && (current->vmt->action))
            current->vmt->action(current, m, a);
    }

    if (current && (current->vmt->update))
        current->vmt->update(current, m, dt);

    if (current && (current->vmt->draw) && (current->vmt->needRedraw) &&
            (current->vmt->needRedraw(current)))
    {
        gdispClear(Black);
        current->vmt->draw(current, m);
        gdispFlush();
    }

    m->wasPressed = pressed;
}
