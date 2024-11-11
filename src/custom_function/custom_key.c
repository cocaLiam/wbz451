// *****************************************************************************
/*
  @Company
    LIFE_BENEFIT

  @File Name
    filename.h

  @Author
    MOON
*/
// *****************************************************************************


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "definitions.h"
#include "stdbool.h"

// *****************************************************************************
// *****************************************************************************
// Section: Macros
// *****************************************************************************
// *****************************************************************************

#define USER_SWITCH 0x10
#define LONG_PRESS_TIME_REF 30
#define DOUBLE_CLICK_TIME_REF 8


// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

enum KEY_DEFINE_T
{
  KEY_DEFINED_RELEASED = 0x00,
  KEY_DEFINED_PRESSED,
};

// *****************************************************************************
// *****************************************************************************
// Section: Global Variables
// *****************************************************************************
// *****************************************************************************

static void checkAndHandlePressRelease(uint8_t* keyMsg);
static bool isPressRelease();
static bool isShortPress();
static bool shouldRelease(uint8_t* keyMsg);
static void handleKeyPress(uint8_t* keyMsg);

// *****************************************************************************
// *****************************************************************************
// Section: Local Variables
// *****************************************************************************
// *****************************************************************************

static KEY_Elem_T local_keyElement;
static KeyCb_T  local_keyCb;
static TIMER_TmrElem_T local_scanTimer;

// *****************************************************************************
// *****************************************************************************
// Section: Function
// *****************************************************************************
// *****************************************************************************
static inline uint16_t createTimerID(uint16_t id, uint8_t instance)
{
  return (id << 8) | instance;
}

static uint16_t app_key_SetTimer(uint16_t idInstance, void *p_tmrParam, uint32_t timeout, bool isPeriodicTimer, TIMER_TmrElem_T *p_tmrElem)
{
    uint8_t tmrId;
    uint16_t result;

    tmrId = (uint8_t)(idInstance >> 8);
    APP_TIMER_SetTimerElem(tmrId, (uint8_t)idInstance, (void *)p_tmrParam, p_tmrElem);
    result = APP_TIMER_SetTimer(p_tmrElem, timeout, isPeriodicTimer);

    return result;
}


void KEY_MSG_REGISTER(KeyCb_T keyCb)
{
  local_keyCb = keyCb;
}

void KEY_Init(void)
{
  GPIOB_REGS->GPIO_ANSELCLR = USER_SWITCH;
  GPIOB_REGS->GPIO_TRISSET = USER_SWITCH;

  memset((uint8_t *)&local_keyElement, 0, sizeof(KEY_Elem_T));
  app_key_SetTimer(createTimerID(APP_TIMER_KEY_SCAN_02,0), NULL, 0x32, true, &local_scanTimer);


  local_keyCb = NULL;
}


void KEY_SCAN(void)
{
    uint8_t keyState, keyMsg = APP_KEY_MSG_NULL;
    bool switchSignal = GPIO_PinRead(PB4);

    keyState = switchSignal ? KEY_DEFINED_RELEASED : KEY_DEFINED_PRESSED;

    if (keyState == KEY_DEFINED_PRESSED)
    {
        local_keyElement.counter++;
        handleKeyPress(&keyMsg);
    }
    else
        checkAndHandlePressRelease(&keyMsg);


    if (keyMsg != APP_KEY_MSG_NULL && local_keyCb)
    {
        local_keyCb(keyMsg);
    }
}



static bool isPressRelease()
{
    return (local_keyElement.state == APP_KEY_STATE_SHORT_PRESS) && 
           (local_keyElement.counter <= DOUBLE_CLICK_TIME_REF);
}

static bool isShortPress()
{
    return (local_keyElement.state == APP_KEY_STATE_SHORT_PRESS) || 
           ((local_keyElement.counter > DOUBLE_CLICK_TIME_REF) && 
            (local_keyElement.state == APP_KEY_STATE_SHORT_PRESS_RELEASE));
}

static bool shouldRelease(uint8_t* keyMsg)
{
    return (*keyMsg != APP_KEY_MSG_NULL) || 
           (local_keyElement.state == APP_KEY_STATE_LONG_PRESS) || 
           (local_keyElement.state == APP_KEY_STATE_DOUBLE_CLICK_PRESS);
}


static void handleKeyPress(uint8_t* keyMsg)
{
    switch (local_keyElement.state)
    {
        case APP_KEY_STATE_RELEASE:
            local_keyElement.state = APP_KEY_STATE_SHORT_PRESS;
            local_keyElement.counter = 0;
            break;

        case APP_KEY_STATE_SHORT_PRESS:
            if (local_keyElement.counter > LONG_PRESS_TIME_REF)
            {
                local_keyElement.state = APP_KEY_STATE_LONG_PRESS;
                *keyMsg = APP_KEY_MSG_LONG_PRESS;
            }
            break;

        case APP_KEY_STATE_SHORT_PRESS_RELEASE:
            local_keyElement.state = APP_KEY_STATE_DOUBLE_CLICK_PRESS;
            *keyMsg = APP_KEY_MSG_DOUBLE_CLICK;
            break;

        default:
            break;
    }
}

static void checkAndHandlePressRelease(uint8_t* keyMsg)
{
    if (local_keyElement.state != APP_KEY_STATE_RELEASE)
        local_keyElement.counter++;

    if (isPressRelease())
        local_keyElement.state = APP_KEY_STATE_SHORT_PRESS_RELEASE;

    else if (isShortPress())
        *keyMsg = APP_KEY_MSG_SHORT_PRESS;

    if (shouldRelease(keyMsg))
    {
        local_keyElement.state = APP_KEY_STATE_RELEASE;
        local_keyElement.counter = 0;
    }
}

void KeyFunction(KEY_MSG_T msg)
{
    switch (msg)
    {
    case APP_KEY_MSG_SHORT_PRESS:
        printf("Click : %d\r\n",msg);
        break;
    
    case APP_KEY_MSG_LONG_PRESS:
        printf("Click : %d\r\n",msg);
        break;

    case APP_KEY_MSG_DOUBLE_CLICK:
        printf("Click : %d\r\n",msg);
        break;        

    default:
    break;
    }
}
