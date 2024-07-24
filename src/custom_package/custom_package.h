#ifndef CUSTOM_PACKAGE_H
#define CUSTOM_PACKAGE_H

#include "definitions.h"

// «…¿Ã∏ß ∫Ø∞Ê
#define     PA0     GPIO_PIN_RA0
#define     PA1     GPIO_PIN_RA1 
#define     PA2     GPIO_PIN_RA2 
#define     PA3     GPIO_PIN_RA3 
#define     PA4     GPIO_PIN_RA4 
#define     PA5     GPIO_PIN_RA5 
#define     PA6     GPIO_PIN_RA6 
#define     PA7     GPIO_PIN_RA7 
#define     PA8     GPIO_PIN_RA8 
#define     PA9     GPIO_PIN_RA9 
#define     PA10    GPIO_PIN_RA10
#define     PA11    GPIO_PIN_RA11
#define     PA12    GPIO_PIN_RA12
#define     PA13    GPIO_PIN_RA13
#define     PA14    GPIO_PIN_RA14
#define     PB0     GPIO_PIN_RB0 
#define     PB1     GPIO_PIN_RB1 
#define     PB2     GPIO_PIN_RB2 
#define     PB3     GPIO_PIN_RB3 
#define     PB4     GPIO_PIN_RB4 
#define     PB5     GPIO_PIN_RB5 
#define     PB6     GPIO_PIN_RB6 
#define     PB7     GPIO_PIN_RB7 
#define     PB8     GPIO_PIN_RB8 
#define     PB9     GPIO_PIN_RB9 
#define     PB10    GPIO_PIN_RB10
#define     PB11    GPIO_PIN_RB11
#define     PB12    GPIO_PIN_RB12
#define     PB13    GPIO_PIN_RB13
//

// Port_direction
#define OUTPUT 0
#define INPUT 1

//===============================GPIO_PIN CONTROLLER
void Pin_init(void);

int Pin_verification(GPIO_PIN pin);
void Port_direction(GPIO_PIN pin, int mode);
bool Pin_mode(GPIO_PIN pin, char mode);

bool Pin_read(GPIO_PIN pin);
void Pin_set(GPIO_PIN pin);
void Pin_clr(GPIO_PIN pin);
void Pin_toggle(GPIO_PIN pin);

const char* getPinName(GPIO_PIN pin);
const char* getDirectionString(int mode);


#endif