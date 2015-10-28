#include "gui.h"

#include "gfx.h"
#include "gui/menu.h"
#include "gui/label.h"
#include "gui/spinbox.h"
#include "gui/manager.h"
#include "gui/combobox.h"

#include "system.h"
#include "drivers.h"

static struct Menu mainMenu;
static struct Manager guiManager;
static struct SpinBox mckView;
static struct SpinBox volumeEdit;
static struct ComboBox inputEdit;
static font_t mainFont;
static font_t numberFont;

const struct MenuItem mainMenuItems[3] =
{
    {"MCK Frequency", (struct Widget*)&mckView}, {"Volume", (struct Widget*)&volumeEdit}, {"Input", (struct Widget*)&inputEdit}
};
const struct ComboBoxItem inputEditValues[4] =
{
    {"None", AUDIO_SOURCE_NONE}, {"USB", AUDIO_SOURCE_USB}, {"S/PDIF Coaxial", AUDIO_SOURCE_COAXIAL}, {"S/PDIF Optical", AUDIO_SOURCE_OPTICAL}
};

void mckViewUpdate(struct SpinBox *view)
{
    spinBoxSetValue(view, systemMCKValueKHz(&system));
}

void volumeSet(struct SpinBox *view, int value)
{
    systemSetVolume(&system, value);
}

void volumeUpdate(struct SpinBox *view)
{
    spinBoxSetValue(view, system.volume);
}

void inputSet(struct ComboBox *view, int value)
{
    systemSwitchAudioSource(&system, (AudioSource)value);
}

void inputUpdate(struct ComboBox *view)
{
    comboBoxSelect(view, (int)system.audio_source);
}

static THD_WORKING_AREA(waGui, 256);
static THD_FUNCTION(guiThread, arg)
{
    rccEnableTIM4(FALSE);
    rccResetTIM4();

    managerInit(&guiManager, TIM4);
    managerStart(&guiManager);

    menuInit(&mainMenu, mainMenuItems, 3, mainFont);

    spinBoxInit(&mckView, mainFont, numberFont, false, mckViewUpdate, NULL);
    spinBoxSetTitle(&mckView, "MCK Frequency");

    spinBoxInit(&volumeEdit, mainFont, numberFont, true, volumeUpdate, volumeSet);
    spinBoxSetTitle(&volumeEdit, "Volume");
    spinBoxSetRange(&volumeEdit, 0, 255, 1);

    comboBoxInit(&inputEdit, inputEditValues, 4, mainFont, inputUpdate, inputSet);

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
