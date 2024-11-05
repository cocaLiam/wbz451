// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <string.h>
#include "app.h"
#include "definitions.h"
#include "app_ble.h"
#include "app_ble_dsadv.h"




// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************





// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;


    appData.appQueue = xQueueCreate( 64, sizeof(APP_Msg_T) );
    /* TODO: Initialize your application's state machine and other
     * parameters.
     */

}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
    APP_Msg_T    appMsg[1];
    APP_Msg_T   *p_appMsg;
    p_appMsg=appMsg;

    /* Check the application's current state. */
    switch ( appData.state )
    {
        // case APP_STATE_INIT:
        // {
        //     bool appInitialized = true;
        //     //appData.appQueue = xQueueCreate( 10, sizeof(APP_Msg_T) );

        //     DEVICE_DeepSleepWakeSrc_T wakeSrc;
        //     DEVICE_GetDeepSleepWakeUpSrc(&wakeSrc);
        //     printf(" - APP_STATE_INIT \r\n");
        //     if ((wakeSrc != DEVICE_DEEP_SLEEP_WAKE_INT0) && (wakeSrc != DEVICE_DEEP_SLEEP_WAKE_RTC))
        //     {
        //         printf(" - wakeSrc \r\n");
        //         RTC_Timer32Start();
        //         DEVICE_EnterDeepSleep(false,0);
        //         printf(" - wakeSrc \r\n");
        //     }
            
        //     if (wakeSrc == DEVICE_DEEP_SLEEP_WAKE_INT0)
        //     {
        //         printf(" - WAKE \r\n");
        //         APP_BleStackInit();
        //         APP_BleDsadvStart(false);
        //         GPIO_RB3_Set();
        //         printf(" - WAKE \r\n");
        //     }
        //     else   
        //     {
        //         printf(" - ELSE \r\n");
        //         GPIO_RB3_Set();
        //         APP_BleDsadvStart(true);
        //         printf(" - ELSE \r\n");
        //     }
        
        // /* ------------ App 에 있는 코드 --------------*/


        case APP_STATE_INIT:
        {
            bool appInitialized = true;
            appData.appQueue = xQueueCreate( 10, sizeof(APP_Msg_T) );

            DEVICE_DeepSleepWakeSrc_T wakeSrc;
            DEVICE_GetDeepSleepWakeUpSrc(&wakeSrc);
            printf("  ------ %d \r\n", wakeSrc);
            
            // if ((wakeSrc != DEVICE_DEEP_SLEEP_WAKE_INT0) && (wakeSrc != DEVICE_DEEP_SLEEP_WAKE_RTC))
            // { 
            //     printf("--- Waiting Start Adv Signal --- %d \r\n", wakeSrc);
            //     GPIO_RB0_Set();
            //     RTC_Timer32Start();
            //     // RTC_Timer32CounterSet(5);
            //     DEVICE_EnterDeepSleep(false,0);  
            //     /*  RB0 ,   RB3 ,   RB5
            //         2150    2150    2150*/
            // }
            switch ( wakeSrc ){
                case DEVICE_DEEP_SLEEP_WAKE_NONE:{    // 0 초기 상태
                    RTC_Timer32Start();
                    printf("0 DEVICE_DEEP_SLEEP_WAKE_NONE DS START : %d \r\n",wakeSrc);
                    DEVICE_EnterDeepSleep(false,0);
                    /*  RB0 ,   RB3 ,   RB5
                        2150    2150    2150*/
                    
                    printf("0 DEVICE_DEEP_SLEEP_WAKE_NONE DS END : %d \r\n",wakeSrc);
                    break;
                } case DEVICE_DEEP_SLEEP_WAKE_INT0:{  // 1 사용자 스위치
                    printf("1 DEVICE_DEEP_SLEEP_WAKE_INT0 DSADV START : %d \r\n",wakeSrc);
                    APP_BleStackInit();             // 
                    APP_BleDsadvStart(false);       // <- Deep sleep 명령후 프로그램 진행(background)
                    // DEVICE_EnterDeepSleep(false,0); // <- Deep sleep 프로그램 정지            
                    printf("1 DEVICE_DEEP_SLEEP_WAKE_INT0 DSADV END : %d \r\n",wakeSrc);
                    break;
                } 
                // case DEVICE_DEEP_SLEEP_WAKE_RTC:{   /* 2 RTC 타이머에 의한 Interrupt
                // app_ble_dsadv.c 에 "#define DSADV_INTERVAL    1536" 해당 값에 의해 DEVICE_DEEP_SLEEP_WAKE_RTC Interrupt 발생
                // ex) DSADV_INTERVAL이 1600 일시, 0.625ms x 1600 = 1000ms(1초)
                // + app_ble.c 파일에 있는 Adv interval 값도 바꿔야 함
                //   advParam.intervalMin = 1536;
                //   advParam.intervalMax = 1600;
                // */
                //     printf("2 DEVICE_DEEP_SLEEP_WAKE_RTC DSADV START : %d \r\n",wakeSrc);
                //     APP_BleDsadvStart(true);
                //     printf("2 DEVICE_DEEP_SLEEP_WAKE_RTC DSADV END : %d \r\n",wakeSrc);
                //     break;
                // } 
                case DEVICE_DEEP_SLEEP_WAKE_DSWDT:{
                    printf("3 DEVICE_DEEP_SLEEP_WAKE_DSWDT : %d \r\n",wakeSrc);
                    break;
                } case DEVICE_DEEP_SLEEP_WAKE_MCLR:{  /* 4 리셋 스위치  
                ( "0 초기 상태" 일떄 Reset 스위치 누르면 Interrupt on. 
                "4 리셋 스위치" 일때 Reset 스위치 누르면 초기 상태로 회귀 )
                */
                    printf("4 DEVICE_DEEP_SLEEP_WAKE_MCLR : %d \r\n",wakeSrc);
                    break;
                } case DEVICE_DEEP_SLEEP_WAKE_OTHER:{
                    printf("5 DEVICE_DEEP_SLEEP_WAKE_OTHER : %d \r\n",wakeSrc);
                    break;
                } case DEVICE_DEEP_SLEEP_WAKE_END:{
                    printf("6 DEVICE_DEEP_SLEEP_WAKE_END : %d \r\n",wakeSrc);
                    break;
                } default:{
                    printf("8 Nothing : %d \r\n",wakeSrc);
                    break;
                }
            }
            // // printf("Trying to Adv ... %d \r\n", wakeSrc);
            // APP_BleDsadvStart(true);
            // printf("Trying to Adv ... %d \r\n", wakeSrc);

            if (appInitialized)
            {
                appData.state = APP_STATE_SERVICE_TASKS;
                printf("------------------ APP_STATE_INIT END ------------------");
            }
            break;
        }
        case APP_STATE_SERVICE_TASKS:
        {
            printf(" +++++++++++ \r\n");
            if (OSAL_QUEUE_Receive(&appData.appQueue, &appMsg, OSAL_WAIT_FOREVER))
            {
              printf("11");
                if(p_appMsg->msgId==APP_MSG_BLE_STACK_EVT)
                {
                    // Pass BLE Stack Event Message to User Application for handling
                    APP_BleStackEvtHandler((STACK_Event_T *)p_appMsg->msgData);
                    printf("22");
                }
                else if(p_appMsg->msgId==APP_MSG_BLE_STACK_LOG)
                {
                    // Pass BLE LOG Event Message to User Application for handling
                    APP_BleStackLogHandler((BT_SYS_LogEvent_T *)p_appMsg->msgData);
                    printf("33");
                }


            printf("44");
            }
            printf("  BREAK");
            break;
        }
        printf("55");

        /* TODO: implement your application state machine.*/

        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            printf("66");
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
