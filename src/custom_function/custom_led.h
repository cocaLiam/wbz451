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

#ifndef _CUSTOM_LED_H
#define _CUSTOM_LED_H

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Data Types                                                        */
/* ************************************************************************** */
/* ************************************************************************** */


typedef enum{
    RED,
    GREEN,
    BLUE,
    TOTAL
}ColorList;

typedef enum{
    CURRENT_LED_OFF,
    CURRENT_LED_ON,
}LedState;

typedef enum{
    RED_PORT = PB0,
    GREEN_PORT = PB3,
    BLUE_PORT = PB5
}LedPort;


typedef struct
{
    
    ColorList color;
    LedState led_state;
    LedPort port;

}DeviceLED;



/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Function Prototypes                                               */
/* ************************************************************************** */
/* ************************************************************************** */


void LED_INIT(void);
void LED_ON(ColorList color);
void LED_OFF(ColorList color);
void LED_TOGGLE(ColorList color);


#endif
