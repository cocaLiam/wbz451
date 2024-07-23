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
#include "ble_trsps/ble_trsps.h"


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

uint16_t conn_hdl;// connection handle info captured @BLE_GAP_EVT_CONNECTED event
uint16_t ret;
uint8_t uart_data;
void uart_cb(SERCOM_USART_EVENT event, uintptr_t context)
{
  APP_Msg_T   appMsg;  
  // If RX data from UART reached threshold (previously set to 1)
  if( event == SERCOM_USART_EVENT_READ_THRESHOLD_REACHED )
  {
    SERCOM0_USART_Write((uint8_t *)"\r\n - READ FROM Terminal \r\n", 26);
    // Read 1 byte data from UART
    // Teraterm에서 치는 데이터들 Read [ 1byte(1글자)씩 ]
    SERCOM0_USART_Read(&uart_data, 1);
    appMsg.msgId = APP_MSG_UART_CB;
    // OSAL 큐에 넣음으로써 결국엔 APP_STATE_SERVICE_TASKS 상태인 appData.state 안에
    //   else if(p_appMsg->msgId==APP_MSG_UART_CB) 해당 조건문에서 다뤄짐
    OSAL_QUEUE_Send(&appData.appQueue, &appMsg, 0);
  }
}

void APP_UartCBHandler()
{
    // Send the data from UART to connected device through Transparent service
    SERCOM0_USART_Write((uint8_t *)" <- SEND TO Peripheral \r\n", 25);
    // conn_hdl = p_event->eventField.evtConnect.connHandle;  <- Connect 시 해당 변수에 connect 핸들러 대입됨
    // 1 <- 1byte씩 data를 전송
    // uart_data <- 보낼데이터 ( 여기서는 TeraTerm 에 있는 Input Data )
    BLE_TRSPS_SendData(conn_hdl, 1, &uart_data);      
}

void SERCOM0_USART_SettupOptions( void )
{
    // Enable UART Read ( SERCOM0_UART Read 기능 온 )
    SERCOM0_USART_ReadNotificationEnable(true, true);
    // Set UART RX notification threshold to be 1
    // param 설명 : SERCOM0_UART 에서 1byte 씩 읽어 오겠다는 설정
    SERCOM0_USART_ReadThresholdSet(1);
    // Register the UART RX callback function
    SERCOM0_USART_ReadCallbackRegister(uart_cb, (uintptr_t)NULL);
}

void BLE_GAP_Advertise_start( void )
{
    // Start Advertisement 
    // param 설명 : Advertising 할지 안할지 여부, Advertising 의 주기 ( 0일시 딜레이 없이 Advertising)
    BLE_GAP_SetAdvEnable(0x01, 0x00);
    SERCOM0_USART_Write((uint8_t *)"Advertising -- \r\n",17);
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
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            bool appInitialized = true;

            SERCOM0_USART_SettupOptions();
            //appData.appQueue = xQueueCreate( 10, sizeof(APP_Msg_T) );
            APP_BleStackInit();

            BLE_GAP_Advertise_start();

            if (appInitialized)
            {

                appData.state = APP_STATE_SERVICE_TASKS;
            }
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {
            // SERCOM0_USART_Write((uint8_t *)"00 \r\n",5);
            // 여기서 OSAL Queue 로 appMsg 를 받을 때까지 무한 대기 상태
            if (OSAL_QUEUE_Receive(&appData.appQueue, &appMsg, OSAL_WAIT_FOREVER))
            {   
                // SERCOM0_USART_Write((uint8_t *)"22 \r\n",5);
                if(p_appMsg->msgId==APP_MSG_BLE_STACK_EVT)
                {
                    // SERCOM0_USART_Write((uint8_t *)"33 \r\n",5);
                    // Pass BLE Stack Event Message to User Application for handling
                    APP_BleStackEvtHandler((STACK_Event_T *)p_appMsg->msgData);
                }
                else if(p_appMsg->msgId==APP_MSG_BLE_STACK_LOG)
                {
                    // Pass BLE LOG Event Message to User Application for handling
                    APP_BleStackLogHandler((BT_SYS_LogEvent_T *)p_appMsg->msgData);
                }
                else if(p_appMsg->msgId==APP_MSG_UART_CB)
                {
                    // Pass BLE UART Data transmission target BLE UART Device handling
                    APP_UartCBHandler();
                }                
            }
            break;
        }

        /* TODO: implement your application state machine.*/


        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
