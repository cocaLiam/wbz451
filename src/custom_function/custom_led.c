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
