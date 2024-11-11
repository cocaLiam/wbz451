/* ************************************************************************** */

//  @Company
//    LIFE_BENEFIT
//
//  @File Name
//    custom_led.h
//
//  @Author
//    MOON

/* ************************************************************************** */

#ifndef _CUSTOM_LED_H    /* Guard against multiple inclusion */
#define _CUSTOM_LED_H

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Data Types                                                        */
/* ************************************************************************** */
/* ************************************************************************** */

typedef enum{
    RED = PB0,
    GREEN = PB3,
    BLUE = PB5,
    NONE = -1,
}ColorList;

typedef enum{
    CURRENT_LED_OFF,
    CURRENT_LED_ON,
    CURRENT_LED_BLINK,
}LED_STATE;


typedef struct
{
    LED_STATE led_state;
    ColorList led_color;
}CUSTOM_LED;



/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Function Prototypes                                               */
/* ************************************************************************** */
/* ************************************************************************** */

void LED_INIT(void);
void LED_ON(ColorList color);
void LED_OFF(ColorList color);
void LED_BLINK(ColorList color, int period);



#endif
