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
#include "timers.h"

// *****************************************************************************
// *****************************************************************************
// Section: Macros
// *****************************************************************************
// *****************************************************************************




// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************



// *****************************************************************************
// *****************************************************************************
// Section: Global Variables
// *****************************************************************************
// *****************************************************************************



// *****************************************************************************
// *****************************************************************************
// Section: Local Variables
// *****************************************************************************
// *****************************************************************************



// *****************************************************************************
// *****************************************************************************
// Section: Function
// *****************************************************************************
// *****************************************************************************

static void app_timer_OneShotTimerExpiredHandle(TimerHandle_t xTimer)
{
    TIMER_TmrElem_T *p_tmrId;
    APP_Msg_T appMsg;

    if (xTimer == NULL)
        return;
    p_tmrId = (TIMER_TmrElem_T *)pvTimerGetTimerID(xTimer);

    if (p_tmrId != NULL)
    {
        switch (p_tmrId->tmrId)
        {
            case APP_TIMER_LED_01:
            {
                appMsg.msgId = 4;
            }
            break;

            case APP_TIMER_CONN_TIMEOUT_03:
            {
                appMsg.msgId = 6;
            }
            break;

            default:
            break;
        }
        ((TIMER_TmrElem_T *)appMsg.msgData)->tmrId = p_tmrId->tmrId;
        ((TIMER_TmrElem_T *)appMsg.msgData)->instance = p_tmrId->instance;
        ((TIMER_TmrElem_T *)appMsg.msgData)->tmrHandle = p_tmrId->tmrHandle;
        ((TIMER_TmrElem_T *)appMsg.msgData)->p_tmrParam = p_tmrId->p_tmrParam;
        
        OSAL_QUEUE_Send(&appData.appQueue, &appMsg, 0);
    }
}



static void app_timer_PeriodicTimerExpiredHandle(TimerHandle_t xTimer)
{
    TIMER_TmrElem_T *p_tmrId;
    APP_Msg_T appMsg;

    if (xTimer == NULL)
        return;
    p_tmrId = (TIMER_TmrElem_T *)pvTimerGetTimerID(xTimer);

    if (p_tmrId != NULL)
    {
        switch (p_tmrId->tmrId)
        {
            case APP_TIMER_KEY_SCAN_02:
            {
                appMsg.msgId = APP_MSG_KEY_SCAN;
            }
            break;

            default:
            break;
        }
        ((TIMER_TmrElem_T *)appMsg.msgData)->tmrId = p_tmrId->tmrId;
        ((TIMER_TmrElem_T *)appMsg.msgData)->instance = p_tmrId->instance;
        ((TIMER_TmrElem_T *)appMsg.msgData)->tmrHandle = p_tmrId->tmrHandle;
        ((TIMER_TmrElem_T *)appMsg.msgData)->p_tmrParam = p_tmrId->p_tmrParam;

         OSAL_QUEUE_Send(&appData.appQueue, &appMsg, 0);
    }
}






void APP_TIMER_SetTimerElem(uint8_t timerId, uint8_t instance, void *p_tmrParam, TIMER_TmrElem_T *p_tmrElem)
{
    p_tmrElem->tmrId = timerId;
    p_tmrElem->instance= instance;
    p_tmrElem->p_tmrParam= p_tmrParam;
}



uint16_t APP_TIMER_SetTimer(TIMER_TmrElem_T *p_timerId, uint32_t timeout, bool isPeriodicTimer)
{
    char timerName[] = "APP_Timer0";
    uint8_t nameLen;

    if ((p_timerId == NULL) || (timeout == 0))
    {
        return APP_RES_INVALID_PARA;
    }

    if (p_timerId->tmrHandle)
    {
        if (xTimerStop(p_timerId->tmrHandle, 0) != pdPASS)
        {
            return APP_RES_FAIL;
        }
        if (xTimerDelete(p_timerId->tmrHandle, 0) != pdPASS)
        {
            return APP_RES_FAIL;
        }
        p_timerId->tmrHandle = NULL;
    }
    
    nameLen = sizeof(timerName) / sizeof(char) - 1;   //-1 means the end character
    timerName[nameLen - 1] = '0' + p_timerId->tmrId;           //Switch to ASCII

    if (isPeriodicTimer)
    {
        p_timerId->tmrHandle = xTimerCreate(timerName, (timeout / portTICK_PERIOD_MS), pdTRUE, (void *)p_timerId, app_timer_PeriodicTimerExpiredHandle);
    }
    else
    {
        p_timerId->tmrHandle = xTimerCreate(timerName, (timeout / portTICK_PERIOD_MS), pdFALSE, (void *)p_timerId, app_timer_OneShotTimerExpiredHandle);
    }

    if (p_timerId->tmrHandle)
    {
        if (pdFAIL == xTimerStart(p_timerId->tmrHandle, 0))
        {
            return APP_RES_FAIL;
        }
        
        return APP_RES_SUCCESS;
    }

    return APP_RES_NO_RESOURCE;
}