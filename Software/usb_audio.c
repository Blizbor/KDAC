#include "hal.h"
#include "usb_audio.h"
#include "drivers.h"

/*
 * USB Device Descriptor (UAC 4.1)
 */
static const uint8_t audio_device_descriptor_data[18] =
{
    USB_DESC_DEVICE(0x0110,               /* bcdUSB (1.1).                    */
    0x00,          /* bDeviceClass (None).             */
    0x00,          /* bDeviceSubClass.                 */
    0x00,          /* bDeviceProtocol.                 */
    0x40,          /* bMaxPacketSize.                  */
    0x0483,        /* idVendor (ST).                   */
    0x5740,        /* idProduct.                       */
    0x0001,        /* bcdDevice.                       */
    1,             /* iManufacturer.                   */
    2,             /* iProduct.                        */
    3,             /* iSerialNumber.                   */
    1)             /* bNumConfigurations.              */
};

/*
 * Device Descriptor wrapper.
 */
static const USBDescriptor audio_device_descriptor =
{
    sizeof audio_device_descriptor_data,
    audio_device_descriptor_data
};

/* Configuration Descriptor tree for a UAC.*/
static const uint8_t audio_configuration_descriptor_data[122] =
{
    /* Configuration Descriptor. (UAC 4.2) */
    USB_DESC_CONFIGURATION(122,             /* wTotalLength.                    */
    0x02,                                   /* bNumInterfaces.                  */
    0x01,                                   /* bConfigurationValue.             */
    0,                                      /* iConfiguration.                  */
    0xC0,                                   /* bmAttributes (self powered).     */
    50),                                    /* bMaxPower (100mA).               */
    /*  Standard Audio Control Interface Descriptor (UAC 4.3.1) */
    USB_DESC_INTERFACE(AUDIO_CONTROL_INTERFACE, /* bInterfaceNumber.            */
    0x00,                                   /* bAlternateSetting.               */
    0x00,                                   /* bNumEndpoints.                   */
    0x01,                                   /* bInterfaceClass (AUDIO).         */
    0x01,                                   /* bInterfaceSubClass
                                               (AUDIO_CONTROL).                 */
    0x00,                                   /* bInterfaceProtocol (none).       */
    0),                                     /* iInterface.                      */
    /*  Class-specific AC Interface Descriptor (UAC 4.3.2) */
    USB_DESC_BYTE(9),                       /* bLength.                         */
    USB_DESC_BYTE(0x24),                    /* bDescriptorType (CS_INTERFACE).  */
    USB_DESC_BYTE(0x01),                    /* bDescriptorSubtype (Header).     */
    USB_DESC_BCD(0x0100),                   /* bcdADC.                          */
    USB_DESC_WORD(43),                      /* wTotalLength.                    */
    USB_DESC_BYTE(0x01),                    /* bInCollection (1 streaming
                                               interfaces).                     */
    USB_DESC_BYTE(AUDIO_STREAMING_INTERFACE),   /* baInterfaceNr.               */
    /* Input Terminal Descriptor (UAC 4.3.2.1) */
    USB_DESC_BYTE(12),                      /* bLength.                         */
    USB_DESC_BYTE(0x24),                    /* bDescriptorType.                 */
    USB_DESC_BYTE(0x02),                    /* bDescriptorSubtype (Input
                                               Terminal).                       */
    USB_DESC_BYTE(AUDIO_INPUT_UNIT_ID),     /* bTerminalID.              */
    USB_DESC_WORD(0x0101),                  /* wTerminalType (USB streaming).   */
    USB_DESC_BYTE(0x00),                    /* bAssocTerminal (none).           */
    USB_DESC_BYTE(2),                       /* bNrChannels (2).                 */
    USB_DESC_WORD(0x0003),                  /* wChannelConfig (left, right).    */
    USB_DESC_BYTE(0x00),                    /* iChannelNames (none).            */
    USB_DESC_BYTE(0x00),                    /* iTerminal (none).                */
    /* Feature Unit Descriptor (UAC 4.3.2.5) */
    USB_DESC_BYTE(13),                      /* bLength.                         */
    USB_DESC_BYTE(0x24),                    /* bDescriptorType.                 */
    USB_DESC_BYTE(0x06),                    /* bDescriptorSubtype (Feature
                                               Unit).                           */
    USB_DESC_BYTE(AUDIO_FUNCTION_UNIT_ID),  /* bUnitID.                         */
    USB_DESC_BYTE(AUDIO_INPUT_UNIT_ID),     /* bSourceID.                       */
    USB_DESC_BYTE(2),                       /* bControlSize (2).                */
    USB_DESC_WORD(0x0000),                  /* Master controls.                 */
    USB_DESC_WORD(0x0003),                  /* Channel 0 controls               */
    USB_DESC_WORD(0x0003),                  /* Channel 1 controls               */
    USB_DESC_BYTE(0x00),                    /* iFeature (none)                  */
    /* Output Terminal Descriptor (UAC 4.3.2.2) */
    USB_DESC_BYTE(9),                       /* bLength.                         */
    USB_DESC_BYTE(0x24),                    /* bDescriptorType.                 */
    USB_DESC_BYTE(0x03),                    /* bDescriptorSubtype (Output
                                                Terminal).                      */
    USB_DESC_BYTE(AUDIO_OUTPUT_UNIT_ID),    /* bTerminalID.                     */
    USB_DESC_WORD(0x0302),                  /* wTerminalType (Headphones).      */
    USB_DESC_BYTE(0x00),                    /* bAssocTerminal (none).           */
    USB_DESC_BYTE(AUDIO_FUNCTION_UNIT_ID),  /* bSourceID.                       */
    USB_DESC_BYTE(0x00),                    /* iTerminal (none).                */
    /* Standard AS Interface Descriptor (empty) (UAC 4.5.1) */
    USB_DESC_INTERFACE(AUDIO_STREAMING_INTERFACE,   /* bInterfaceNumber.        */
    0x00,                                   /* bAlternateSetting.               */
    0x00,                                   /* bNumEndpoints.                   */
    0x01,                                   /* bInterfaceClass (AUDIO).         */
    0x02,                                   /* bInterfaceSubClass
                                                (AUDIO_STREAMING).              */
    0x00,                                   /* bInterfaceProtocol (none).       */
    0),                                     /* iInterface.                      */
    /* Standard AS Interface Descriptor (functional) (UAC 4.5.1) */
    USB_DESC_INTERFACE(AUDIO_STREAMING_INTERFACE,   /* bInterfaceNumber.        */
    0x01,                                   /* bAlternateSetting.               */
    0x02,                                   /* bNumEndpoints.                   */
    0x01,                                   /* bInterfaceClass (AUDIO).         */
    0x02,                                   /* bInterfaceSubClass
                                                (AUDIO_STREAMING).              */
    0x00,                                   /* bInterfaceProtocol (none).       */
    0),                                     /* iInterface.                      */
    /* Class-specific AS Interface Descriptor (UAC 4.5.2) */
    USB_DESC_BYTE(7),                       /* bLength.                         */
    USB_DESC_BYTE(0x24),                    /* bDescriptorType (CS_INTERFACE).  */
    USB_DESC_BYTE(0x01),                    /* bDescriptorSubtype (General).    */
    USB_DESC_BYTE(AUDIO_INPUT_UNIT_ID),     /* bTerminalLink.            */
    USB_DESC_BYTE(0x00),                    /* bDelay (none).                   */
    USB_DESC_WORD(0x0001),                  /* wFormatTag (PCM format).         */
    /* Class-Specific AS Format Type Descriptor (UAC 4.5.3) */
    USB_DESC_BYTE(11),                      /* bLength.                         */
    USB_DESC_BYTE(0x24),                    /* bDescriptorType (CS_INTERFACE).  */
    USB_DESC_BYTE(0x02),                    /* bDescriptorSubtype (Format).     */
    USB_DESC_BYTE(0x01),                    /* bFormatType (Type I).            */
    USB_DESC_BYTE(0x02),                    /* bNrChannels (2).                 */
    USB_DESC_BYTE(0x02),                    /* bSubFrameSize (2).               */
    USB_DESC_BYTE(AUDIO_RESOLUTION),        /* bBitResolution.                  */
    USB_DESC_BYTE(0x01),                    /* bSamFreqType (Type I).           */
    USB_DESC_BYTE(AUDIO_SAMPLING_FREQUENCY & 0xFF),
    USB_DESC_BYTE((AUDIO_SAMPLING_FREQUENCY >> 8) & 0xFF),
    USB_DESC_BYTE((AUDIO_SAMPLING_FREQUENCY >> 16) & 0xFF),
    /* Standard AS Isochronous Audio Data Endpoint Descriptor (UAC 4.6.1.1) */
    USB_DESC_BYTE(9),                       /* bLength (9).                     */
    USB_DESC_BYTE(0x05),                    /* bDescriptorType (Endpoint).      */
    USB_DESC_BYTE(AUDIO_PLAYBACK_ENDPOINT), /* bEndpointAddress.                */
    USB_DESC_BYTE(0x05),                    /* bmAttributes (asynchronous).     */
    USB_DESC_WORD(AUDIO_MAX_PACKET_SIZE),   /* wMaxPacketSize                   */
    USB_DESC_BYTE(0x01),                    /* bInterval (1 ms).                */
    USB_DESC_BYTE(0x00),                    /* bRefresh (0).                    */
    USB_DESC_BYTE(AUDIO_FEEDBACK_ENDPOINT), /* bSynchAddress.                   */
    /* C-S AS Isochronous Audio Data Endpoint Descriptor (UAC 4.6.1.2) */
    USB_DESC_BYTE(7),                       /* bLength.                         */
    USB_DESC_BYTE(0x25),                    /* bDescriptorType (CS_ENDPOINT).   */
    USB_DESC_BYTE(0x01),                    /* bDescriptorSubtype (General).    */
    USB_DESC_BYTE(0x00),                    /* bmAttributes (none).             */
    USB_DESC_BYTE(0x02),                    /* bLockDelayUnits (PCM Samples).   */
    USB_DESC_WORD(0x0000),                  /* bLockDelay (0).                  */
    /* Standard Isochronous Audio Feedback Endpoint Descriptor */
    USB_DESC_BYTE(9),                       /* bLength (9).                     */
    USB_DESC_BYTE(0x05),                    /* bDescriptorType (Endpoint).      */
    USB_DESC_BYTE(AUDIO_FEEDBACK_ENDPOINT), /* bEndpointAddress.                */
    USB_DESC_BYTE(0x11),                    /* bmAttributes (nosync, feedback). */
    USB_DESC_WORD(4),                       /* wMaxPacketSize                   */
    USB_DESC_BYTE(0x01),                    /* bInterval (1 ms).                */
    USB_DESC_BYTE(0x05),                    /* bRefresh (32 ms).                */
    USB_DESC_BYTE(0x00),                    /* bSynchAddress (none).            */
};

/*
 * Configuration Descriptor wrapper.
 */
static const USBDescriptor audio_configuration_descriptor =
{
    sizeof audio_configuration_descriptor_data,
    audio_configuration_descriptor_data
};

/*
 * U.S. English language identifier.
 */
static const uint8_t audio_string0[] =
{
    USB_DESC_BYTE(4),                       /* bLength.                         */
    USB_DESC_BYTE(USB_DESCRIPTOR_STRING),   /* bDescriptorType.                 */
    USB_DESC_WORD(0x0409)                   /* wLANGID (U.S. English).          */
};

/*
 * Vendor string.
 */
static const uint8_t audio_string1[] =
{
    USB_DESC_BYTE(24),                      /* bLength.                         */
    USB_DESC_BYTE(USB_DESCRIPTOR_STRING),   /* bDescriptorType.                 */
    'O', 0, 'p', 0, 'e', 0, 'n', 0, 'H', 0, 'a', 0, 'r', 0, 'd', 0,
    'w', 0, 'a', 0, 'r', 0, 'e'
};

/*
 * Device Description string.
 */
static const uint8_t audio_string2[] =
{
    USB_DESC_BYTE(10),                      /* bLength.                         */
    USB_DESC_BYTE(USB_DESCRIPTOR_STRING),   /* bDescriptorType.                 */
    'K', 0, 'D', 0, 'A', 0, 'C', 0
};

/*
 * Serial Number string.
 */
static const uint8_t audio_string3[] =
{
    USB_DESC_BYTE(8),                       /* bLength.                         */
    USB_DESC_BYTE(USB_DESCRIPTOR_STRING),   /* bDescriptorType.                 */
    '0' + CH_KERNEL_MAJOR, 0,
    '0' + CH_KERNEL_MINOR, 0,
    '0' + CH_KERNEL_PATCH, 0
};

/*
 * Strings wrappers array.
 */
static const USBDescriptor audio_strings[] =
{
    {sizeof audio_string0, audio_string0},
    {sizeof audio_string1, audio_string1},
    {sizeof audio_string2, audio_string2},
    {sizeof audio_string3, audio_string3}
};

/*
 * Handles the GET_DESCRIPTOR callback. All required descriptors must be
 * handled here.
 */
static const USBDescriptor *get_descriptor(USBDriver *usbp,
        uint8_t dtype,
        uint8_t dindex,
        uint16_t lang)
{

    (void)usbp;
    (void)lang;
    switch (dtype)
    {
    case USB_DESCRIPTOR_DEVICE:
        return &audio_device_descriptor;
    case USB_DESCRIPTOR_CONFIGURATION:
        return &audio_configuration_descriptor;
    case USB_DESCRIPTOR_STRING:
        if (dindex < 4)
            return &audio_strings[dindex];
    }
    return NULL;
}

static uint16_t dac_buffer[AUDIO_BUFFER_SIZE];
static uint8_t queue_buf[AUDIO_QUEUE_SIZE];

static uint16_t *bufferp;
static size_t buffern;
static uint8_t sof_feedback_data[3];

void audio_feedback(USBDriver *usbp, usbep_t ep)
{
    if (audio.playback)
    {
        if (system.sof_valid)
        {
            systemMCKValueUSBFeedback(&system, 9, sof_feedback_data);
            usbPrepareTransmit(usbp, ep, sof_feedback_data, 3);
        }
        else
            usbPrepareTransmit(usbp, ep, NULL, 0);
        chSysLockFromISR();
        usbStartTransmitI(usbp, ep);
        chSysUnlockFromISR();
    }
}

/*
 * Data received (or not) in current frame.
 */
void audio_received(USBDriver *usbp, usbep_t ep)
{
    if (audio.playback)
    {
        /* Fill audio data queue */
        usbPrepareQueuedReceive(usbp, ep, &audio.audio_queue,
                                AUDIO_MAX_PACKET_SIZE);
        chSysLockFromISR();
        size_t qs = chIQGetEmptyI(&audio.audio_queue);
        if (qs < AUDIO_PACKET_SIZE)
            audio.overrun_count++;
        usbStartReceiveI(usbp, ep);
        chSysUnlockFromISR();
    }
}

/*
 * Part (half) of I2S buffer transmitted.
 */
static void i2s_callback(I2SDriver *i2sp, size_t off, size_t n)
{
    chSysLockFromISR();
    bufferp = ((uint16_t*)i2sp->config->tx_buffer) + off;
    buffern = n * 2;
    chThdResumeI(&audio.pump, MSG_OK);
    chSysUnlockFromISR();
}

/*
 * EP1 states.
 */
static USBOutEndpointState ep1outstate;
static USBInEndpointState ep1instate;

/*
 * EP1 initialization structure (IN & OUT).
 */
static const USBEndpointConfig ep1config =
{
    USB_EP_MODE_TYPE_ISOC,
    NULL,
    audio_feedback,
    audio_received,
    0x0004,
    AUDIO_MAX_PACKET_SIZE,
    &ep1instate,
    &ep1outstate,
    1,
    NULL
};

/*
 * Temporary buffer for control data.
 */
static uint8_t control_data[8];
static uint8_t control_channel;

/*
 * Volume data received.
 */
static void notify_volume(USBDriver *usbp)
{
    if (control_channel == 0xff)
    {
        audio.volume[0] = ((int16_t*)control_data)[1];
        audio.volume[1] = ((int16_t*)control_data)[2];
    }
    else
    {
        audio.volume[control_channel - 1] = ((int16_t*)control_data)[0];
    }
    chSysLockFromISR();
    chEvtBroadcastFlagsI(&audio.audio_events, AUDIO_EVENT_VOLUME);
    chSysUnlockFromISR();
}

/*
 * Mute data received.
 */
static void notify_mute(USBDriver *usbp)
{
    if (control_channel == 0xff)
    {
        audio.mute[0] = control_data[1];
        audio.mute[1] = control_data[2];
    }
    else
    {
        memcpy(&audio.mute[control_channel - 1], control_data, 2);
        //audio.mute[control_channel - 1] = control_data[0];
    }
    chSysLockFromISR();
    chEvtBroadcastFlagsI(&audio.audio_events, AUDIO_EVENT_MUTE);
    chSysUnlockFromISR();
}

/*
 * Handles requests for audio function unit (volume & mute).
 */
bool audio_volume_control(USBDriver *usbp, uint8_t req, uint8_t ctrl,
                          uint8_t channel, uint16_t length)
{
    switch (req)
    {
    case UAC_REQ_SET_MAX:
    case UAC_REQ_SET_MIN:
    case UAC_REQ_SET_RES:
        if (ctrl == UAC_FU_VOLUME_CONTROL)
        {
            usbSetupTransfer(usbp, control_data, length, NULL);
            return true;
        }
    case UAC_REQ_GET_MAX:
        if (ctrl == UAC_FU_VOLUME_CONTROL)
        {
            for (int i = 0; i < length; i++)
                ((int16_t*)control_data)[i] = 0;
            usbSetupTransfer(usbp, control_data, length, NULL);
            return true;
        }
    case UAC_REQ_GET_MIN:
        if (ctrl == UAC_FU_VOLUME_CONTROL)
        {
            for (int i = 0; i < length; i++)
                ((int16_t*)control_data)[i] = -120 * 256;
            usbSetupTransfer(usbp, control_data, length, NULL);
            return true;
        }
    case UAC_REQ_GET_RES:
        if (ctrl == UAC_FU_VOLUME_CONTROL)
        {
            for (int i = 0; i < length; i++)
                ((int16_t*)control_data)[i] = 128;
            usbSetupTransfer(usbp, control_data, length, NULL);
            return true;
        }
    case UAC_REQ_GET_CUR:
        if (ctrl == UAC_FU_MUTE_CONTROL)
        {
            if (channel == 0xff)
            {
                ((int16_t*)control_data)[0] = 0;
                ((int16_t*)control_data)[1] = audio.mute[0];
                ((int16_t*)control_data)[2] = audio.mute[1];
                usbSetupTransfer(usbp, control_data, length, NULL);
            }
            else
            {
                ((int16_t*)control_data)[0] = audio.mute[channel - 1];
                usbSetupTransfer(usbp, control_data, length, NULL);
            }
            return true;
        }
        else if (ctrl == UAC_FU_VOLUME_CONTROL)
        {
            if (channel == 0xff)
            {
                ((int16_t*)control_data)[0] = 0;
                ((int16_t*)control_data)[1] = audio.volume[0];
                ((int16_t*)control_data)[2] = audio.volume[1];
                usbSetupTransfer(usbp, control_data, length, NULL);
            }
            else
            {
                ((int16_t*)control_data)[0] = audio.volume[channel - 1];
                usbSetupTransfer(usbp, control_data, length, NULL);
            }
            return true;
        }
    case UAC_REQ_SET_CUR:
        if (ctrl == UAC_FU_MUTE_CONTROL)
        {
            control_channel = channel;
            usbSetupTransfer(usbp, control_data, length, notify_mute);
            return true;
        }
        else if (ctrl == UAC_FU_VOLUME_CONTROL)
        {
            control_channel = channel;
            usbSetupTransfer(usbp, control_data, length, notify_volume);
            return true;
        }
    default:
        return false;
    }
}

/*
 * Handles UAC-specific controls.
 */
bool audio_control(USBDriver *usbp, uint8_t iface, uint8_t entity, uint8_t req,
                   uint16_t wValue, uint16_t length)
{
    /* Only requests to audio control iface are supported */
    if (iface == AUDIO_CONTROL_INTERFACE)
    {
        /* Feature unit */
        if (entity == AUDIO_FUNCTION_UNIT_ID)
        {
            return audio_volume_control(usbp, req, (wValue >> 8) & 0xFF,
                                        wValue & 0xFF, length);
        }
    }
    return false;
}

/*
 * Starts USB transfers, and notifies control thread.
 */
void start_playback(USBDriver *usbp)
{
    if (!audio.playback)
    {
        audio.playback = true;
        audio.first_packet = true;
        usbPrepareQueuedReceive(usbp, AUDIO_PLAYBACK_ENDPOINT, &audio.audio_queue,
                                AUDIO_MAX_PACKET_SIZE);
        usbPrepareTransmit(usbp, AUDIO_PLAYBACK_ENDPOINT, NULL, 0);
        chSysLockFromISR();
        chEvtBroadcastFlagsI(&audio.audio_events, AUDIO_EVENT_PLAYBACK);
        usbStartReceiveI(usbp, AUDIO_PLAYBACK_ENDPOINT);
        usbStartTransmitI(usbp, AUDIO_PLAYBACK_ENDPOINT);
        chSysUnlockFromISR();
    }
}

/*
 * Stops playback, and notifies control thread.
 */
void stop_playback(USBDriver *usbp)
{
    if (audio.playback)
    {
        audio.playback = false;
        chSysLockFromISR();
        chEvtBroadcastFlagsI(&audio.audio_events, AUDIO_EVENT_PLAYBACK);
        chSysUnlockFromISR();
    }
}

/*
 * Handles SETUP requests.
 */
bool audio_requests_hook(USBDriver *usbp)
{
    if ((usbp->setup[0] & (USB_RTYPE_TYPE_MASK | USB_RTYPE_RECIPIENT_MASK)) ==
            (USB_RTYPE_TYPE_STD | USB_RTYPE_RECIPIENT_INTERFACE))
    {
        if (usbp->setup[1] == USB_REQ_SET_INTERFACE)
        {
            /* Switch between empty interface and normal one. */
            if (((usbp->setup[5] << 8) | usbp->setup[4]) == AUDIO_STREAMING_INTERFACE)
            {
                if (((usbp->setup[3] << 8) | usbp->setup[2]) == 1)
                {
                    start_playback(usbp);
                }
                else
                {
                    stop_playback(usbp);
                }
                usbSetupTransfer(usbp, NULL, 0, NULL);
                return true;
            }
        }
        return false;
    }
    else if ((usbp->setup[0] & USB_RTYPE_TYPE_MASK) == USB_RTYPE_TYPE_CLASS)
    {
        switch (usbp->setup[0] & USB_RTYPE_RECIPIENT_MASK)
        {
        case USB_RTYPE_RECIPIENT_INTERFACE:
            return audio_control(usbp, usbp->setup[4], usbp->setup[5], usbp->setup[1],
                                 (usbp->setup[3] << 8) | (usbp->setup[2]),
                                 (usbp->setup[7] << 8) | (usbp->setup[6]));
        case USB_RTYPE_RECIPIENT_ENDPOINT:
        default:
            return false;
        }
    }
    return false;
}

/*
 * Handles the USB driver global events.
 */
static void usb_event(USBDriver *usbp, usbevent_t event)
{
    chSysLockFromISR();
    chEvtBroadcastFlagsI(&audio.audio_events, AUDIO_EVENT_USB_STATE);
    chSysUnlockFromISR();

    switch (event)
    {
    case USB_EVENT_RESET:
        stop_playback(usbp);
        return;
    case USB_EVENT_ADDRESS:
        return;
    case USB_EVENT_CONFIGURED:
        chSysLockFromISR();
        /* Enables the endpoints specified into the configuration.
           Note, this callback is invoked from an ISR so I-Class functions
           must be used.*/
        usbInitEndpointI(usbp, AUDIO_PLAYBACK_ENDPOINT, &ep1config);
        chSysUnlockFromISR();
        return;
    case USB_EVENT_SUSPEND:
        return;
    case USB_EVENT_WAKEUP:
        return;
    case USB_EVENT_STALLED:
        return;
    }
    return;
}

/*
 * USB driver configuration.
 */
static const USBConfig usbcfg =
{
    usb_event,
    get_descriptor,
    audio_requests_hook,
    NULL,
};

/*
 * I2S configuration.
 */
static const I2SConfig i2scfg =
{
    (const uint8_t*)dac_buffer,
    NULL,
    AUDIO_BUFFER_SIZE,
    i2s_callback,
    SPI_I2SCFGR_CHLEN,
    4
};

/*
 * Audio demo config
 */
static const USBAudioConfig audiocfg =
{
    &USBD2,
    &I2CD1,
    &I2SD3
};

/*
 * Audio pumping thread.
 */
static THD_WORKING_AREA(waThread1, 128);
static THD_FUNCTION(Thread1, arg)
{
    (void)arg;
    chRegSetThreadName("apump");

    while (true)
    {
        /* Wait until part (half) of buffer transmitted */
        chSysLock();
        chThdSuspendS(&audio.pump);
        size_t qs = chIQGetFullI(&audio.audio_queue);
        chSysUnlock();


        if (audio.first_packet)
        {
            // 2 ms buffered
            if (qs >= 2 * AUDIO_PACKET_SIZE)
                audio.first_packet = false;
        }

        if (!audio.first_packet)
        {
            /* Enough data in queue, 2ms underrun otherwise */
            if (qs >= buffern)
            {
                chIQReadTimeout(&audio.audio_queue, (uint8_t*)bufferp, buffern,
                                TIME_IMMEDIATE);
            }
            else
            {
                audio.first_packet = true;
                audio.underrun_count++;
            }
        }
    }
}

void usbAudioInit(USBAudioDriver *ap)
{
    chEvtObjectInit(&ap->audio_events);
    chIQObjectInit(&ap->audio_queue, queue_buf, AUDIO_QUEUE_SIZE, NULL, NULL);

    ap->config = NULL;
    ap->playback = false;
    ap->pump = NULL;
    ap->underrun_count = 0;
    ap->overrun_count = 0;
    ap->first_packet = true;
}

void usbAudioStart(USBAudioDriver *ap, const USBAudioConfig *cp)
{
    ap->config = cp;
}

void usbAudio()
{
    usbAudioInit(&audio);
    usbAudioStart(&audio, &audiocfg);

    static event_listener_t listener;
    chEvtRegisterMask(&audio.audio_events, &listener, AUDIO_EVENT);

    usbDisconnectBus(&USBD2);
    chThdSleepMilliseconds(1500);
    usbStart(&USBD2, &usbcfg);
    usbConnectBus(&USBD2);

    chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);

    for (;;)
    {
        chEvtWaitOne(AUDIO_EVENT);
        eventflags_t evt = chEvtGetAndClearFlags(&listener);

        if (evt & AUDIO_EVENT_PLAYBACK)
        {
            if (audio.playback)
            {
                i2sStart(&I2SD3, &i2scfg);
                i2sStartExchange(&I2SD3);
                systemStartMCKCapture(&system);
            }
            else
            {
                systemStopMCKCapture(&system);
                i2sStopExchange(&I2SD3);
                i2sStop(&I2SD3);
            }
        }

        if (evt & AUDIO_EVENT_MUTE)
        {
        }

        if (evt & AUDIO_EVENT_VOLUME)
        {
            uint8_t db2l = (((uint16_t)(120 * 256 + audio.volume[0])) >> 7) + 15;
            uint8_t db2r = (((uint16_t)(120 * 256 + audio.volume[1])) >> 7) + 15;
            systemSetVolume(&system, db2l, db2r);
        }
    }
}
