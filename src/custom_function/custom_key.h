/* ************************************************************************** */

//  @Company
//    LIFE_BENEFIT
//
//  @File Name
//    filename.h
//
//  @Author
//    MOON

/* ************************************************************************** */

#ifndef _CUSTOM_KEY_H    /* Guard against multiple inclusion */
#define _CUSTOM_KEY_H

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Data Types                                                        */
/* ************************************************************************** */
/* ************************************************************************** */

enum KEY_STATE_T
{
  APP_KEY_STATE_RELEASE = 0x00,
  APP_KEY_STATE_SHORT_PRESS,
  APP_KEY_STATE_LONG_PRESS,
  APP_KEY_STATE_SHORT_PRESS_RELEASE,
  APP_KEY_STATE_DOUBLE_CLICK_PRESS,
  
  APP_KEY_STATE_END 
};

typedef enum KEY_MSG_T
{
    APP_KEY_MSG_NULL = 0x00,
    APP_KEY_MSG_SHORT_PRESS,
    APP_KEY_MSG_LONG_PRESS,
    APP_KEY_MSG_DOUBLE_CLICK,
    
    APP_KEY_MSG_END 
}KEY_MSG_T;


typedef struct KEY_Elem_T
{
    uint8_t state;
    uint8_t counter;
}KEY_Elem_T;


typedef void (*KeyCb_T)(KEY_MSG_T msg);

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Function Prototypes                                               */
/* ************************************************************************** */
/* ************************************************************************** */

void KEY_MSG_REGISTER(KeyCb_T keyCb);
void KEY_Init(void);
void KEY_SCAN(void);
void KeyFunction(KEY_MSG_T msg);


#endif
