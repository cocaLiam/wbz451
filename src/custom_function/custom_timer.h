/* ************************************************************************** */

//  @Company
//    LIFE_BENEFIT
//
//  @File Name
//    custom_timer.h
//
//  @Author
//    MOON

/* ************************************************************************** */

#ifndef _CUSTOM_TIMER_H    /* Guard against multiple inclusion */
#define _CUSTOM_TIMER_H

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include <stdint.h>
#include "osal/osal_freertos_extend.h"
#include "timers.h"


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Data Types                                                        */
/* ************************************************************************** */
/* ************************************************************************** */

typedef enum TIMER_TimerId_T
{
    APP_TIMER_LED_01,                       /**< The timer to measure LED interval and duration. */
    APP_TIMER_KEY_SCAN_02,                  /**< The timer for key scan. */
    APP_TIMER_CONN_TIMEOUT_03,              /**< The timer for the timeout of connection. */

    APP_TIMER_TOTAL
} TIMER_TimerId_T;

typedef struct TIMER_TmrElem_T
{
    uint8_t        tmrId;           /**< Dedicated timer Id */
    uint8_t        instance;        /**< Dedicated timer instance */ 
    TimerHandle_t   tmrHandle;      /**< Dedicated timer handler */ 
    void            *p_tmrParam;    /**< Dedicated timer parameter */
} TIMER_TmrElem_T;


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Function Prototypes                                               */
/* ************************************************************************** */
/* ************************************************************************** */

void APP_TIMER_SetTimerElem(uint8_t timerId, uint8_t instance, void *p_tmrParam, TIMER_TmrElem_T *p_tmrElem);
uint16_t APP_TIMER_SetTimer(TIMER_TmrElem_T *p_timerId, uint32_t timeout, bool isPeriodicTimer);



#endif
