#include "gui.h"

#include "gfx.h"
#include "gui/menu.h"
#include "gui/label.h"
#include "gui/spinbox.h"
#include "gui/manager.h"

#include "system.h"

static struct Menu mainMenu;
static struct Manager guiManager;
static struct SpinBox mckView;
static struct SpinBox volumeEdit;
static font_t mainFont;
static font_t numberFont;

const struct MenuItem mainMenuItems[10] =
{
    {"MCK Frequency", (struct Widget*)&mckView}, {"Volume", (struct Widget*)&volumeEdit}, {"Item 3", NULL}, {"Item 4", NULL}, {"Item 5", NULL},
    {"Item 6", NULL}, {"Item 7", NULL}, {"Item 8", NULL}, {"Item 9", NULL}, {"Item 10", NULL}
};

void mckViewUpdate(struct SpinBox *view)
{
    spinBoxSetValue(view, mckValueKHz());
}

void volumeUpdate(struct SpinBox *view, int value)
{
}

static THD_WORKING_AREA(waGui, 256);
static THD_FUNCTION(guiThread, arg)
{
    rccEnableTIM4(FALSE);
    rccResetTIM4();

    managerInit(&guiManager, TIM4);
    managerStart(&guiManager);

    menuInit(&mainMenu, mainMenuItems, 10, mainFont);

    spinBoxInit(&mckView, mainFont, numberFont, false, mckViewUpdate, NULL);
    spinBoxSetTitle(&mckView, "MCK Frequency");

    spinBoxInit(&volumeEdit, mainFont, numberFont, true, NULL, volumeUpdate);
    spinBoxSetTitle(&volumeEdit, "Volume");
    spinBoxSetRange(&volumeEdit, 0, 100, 1);

    managerPushWidget(&guiManager, (struct Widget*)&mainMenu);

    for (;;)
    {
        managerUpdate(&guiManager, 100);
        chThdSleepMilliseconds(100);
    }
}

void startGUI()
{
    gfxInit();
    mainFont = gdispOpenFont("terminus_12");
    numberFont = gdispOpenFont("LargeNumbers");

    chThdCreateStatic(waGui, sizeof(waGui), NORMALPRIO, guiThread, NULL);
}
