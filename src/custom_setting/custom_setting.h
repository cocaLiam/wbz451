/* ************************************************************************** */

//  @Company
//    LIFE_BENEFIT
//
//  @File Name
//    custom_setting.h
//
//  @Author
//    MOON

/* ************************************************************************** */

#ifndef CUSTOM_SETTING_H    /* Guard against multiple inclusion */
#define CUSTOM_SETTING_H

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Data Types                                                        */
/* ************************************************************************** */
/* ************************************************************************** */

typedef enum{
//PortA
    PA0 = (0U),PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10,PA11,PA12,PA13,PA14,
//PortB
    PB0 = (16U),PB1,PB2,PB3,PB4,PB5,PB6,PB7,PB8,PB9,PB10,PB11,PB12,PB13,
}PinNumber;

typedef enum{
    INPUT,
    OUTPUT,
}PinDirection;

typedef enum{
    ON,
    OFF,
}PinState;

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Function Prototypes                                               */
/* ************************************************************************** */
/* ************************************************************************** */

void PinInit(void);
bool PinMode(PinNumber pin , PinDirection direction);
bool PinSet(PinNumber pin , PinState state);
void PinToggle(PinNumber pin);

#endif
