/*******************************************************************************
 System Idle Task File

  File Name:
    custom_led.c

  Summary:
    LED 동작 코드

  Remarks:
 *******************************************************************************/
#include "definitions.h"
 /******************************************************************************/

// typedef enum{
//     RED = PB0,
//     GREEN = PB3,
//     BLUE = PB5,
//     NONE = -1,
// }ColorList;

// typedef struct
// {
//     bool ledstate;
//     ColorList current_color;
// }CUSTOM_LED;



CUSTOM_LED device_led;


void LED_INIT()
{
    PinMode(RED, OUTPUT);
    PinMode(GREEN, OUTPUT);
    PinMode(BLUE, OUTPUT);
}


void LED_ON(ColorList color)
{
    PinSet(color, ON);
    device_led.led_state = CURRENT_LED_ON;
    device_led.led_color = color;
}

void LED_OFF(ColorList color)
{
    PinSet(color, OFF);
    device_led.led_state = CURRENT_LED_OFF;
    device_led.led_color = color;
}

// [타이머 추가해야됌]
// void LED_BLINK(ColorList color, int period)
// {
//     PinToggle(color);
//     vTaskDelay(period);
//     device_led.led_state = CURRENT_LED_BLINK;
//     device_led.led_color = color;
// }
