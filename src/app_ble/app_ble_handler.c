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
  Application BLE Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_ble_handler.c

  Summary:
    This file contains the Application BLE functions for this project.

  Description:
    This file contains the Application BLE functions for this project.
 *******************************************************************************/


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "osal/osal_freertos_extend.h"
#include "app_ble_handler.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Variables
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
// *****************************************************************************
// Section: Functions
// *****************************************************************************
// *****************************************************************************
void APP_BleGapEvtHandler(BLE_GAP_Event_T *p_event)
{
    switch(p_event->eventId)
    {
        case BLE_GAP_EVT_CONNECTED:
        {
            printf("%d : BLE_GAP_EVT_CONNECTED\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_GAP_EVT_DISCONNECTED:
        {
            printf("%d : BLE_GAP_EVT_DISCONNECTED\r\n",p_event->eventId);
            BLE_GAP_SetAdvEnable(true,0);
            printf("%d , Re-Scanning\r\n",p_event->eventId);


            /* TODO: implement your application code.*/
        }
        break;

        case BLE_GAP_EVT_CONN_PARAM_UPDATE:
        {
            printf("%d : BLE_GAP_EVT_CONN_PARAM_UPDATE\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_GAP_EVT_ENCRYPT_STATUS:
        {
            printf("%d : BLE_GAP_EVT_ENCRYPT_STATUS\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_GAP_EVT_ADV_REPORT:
        {
            printf("%d : BLE_GAP_EVT_ADV_REPORT\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_GAP_EVT_ENC_INFO_REQUEST:
        {
            printf("%d : BLE_GAP_EVT_ENC_INFO_REQUEST\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_GAP_EVT_REMOTE_CONN_PARAM_REQUEST:
        {
            printf("%d : BLE_GAP_EVT_REMOTE_CONN_PARAM_REQUEST\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_GAP_EVT_EXT_ADV_REPORT:
        {
            printf("%d : BLE_GAP_EVT_EXT_ADV_REPORT\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_GAP_EVT_ADV_TIMEOUT:
        {
            // Adv 이후 일정 시간 연결이 안되어있을때 나오는 이벤트 
            printf("%d : BLE_GAP_EVT_ADV_TIMEOUT\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_GAP_EVT_TX_BUF_AVAILABLE:
        {
            printf("%d : BLE_GAP_EVT_TX_BUF_AVAILABLE\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_GAP_EVT_DEVICE_NAME_CHANGED:
        {
            printf("%d : BLE_GAP_EVT_DEVICE_NAME_CHANGED\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_GAP_EVT_AUTH_PAYLOAD_TIMEOUT:
        {
            printf("%d : BLE_GAP_EVT_AUTH_PAYLOAD_TIMEOUT\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_GAP_EVT_PHY_UPDATE:
        {
            printf("%d : BLE_GAP_EVT_PHY_UPDATE\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_GAP_EVT_SCAN_REQ_RECEIVED:
        {
            printf("%d : BLE_GAP_EVT_SCAN_REQ_RECEIVED\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_GAP_EVT_DIRECT_ADV_REPORT:
        {
            printf("%d : BLE_GAP_EVT_DIRECT_ADV_REPORT\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_GAP_EVT_PERI_ADV_SYNC_EST:
        {
            printf("%d : BLE_GAP_EVT_PERI_ADV_SYNC_EST\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_GAP_EVT_PERI_ADV_REPORT:
        {
            printf("%d : BLE_GAP_EVT_PERI_ADV_REPORT\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_GAP_EVT_PERI_ADV_SYNC_LOST:
        {
            printf("%d : BLE_GAP_EVT_PERI_ADV_SYNC_LOST\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_GAP_EVT_ADV_SET_TERMINATED:
        {
            printf("%d : BLE_GAP_EVT_ADV_SET_TERMINATED\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_GAP_EVT_SCAN_TIMEOUT:
        {
            printf("%d : BLE_GAP_EVT_SCAN_TIMEOUT\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_GAP_EVT_TRANSMIT_POWER_REPORTING:
        {
            printf("%d : BLE_GAP_EVT_TRANSMIT_POWER_REPORTING\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_GAP_EVT_ADV_COMPL:
        {
            printf("%d : BLE_GAP_EVT_ADV_COMPL\r\n",p_event->eventId);
            /* TODO: implement your application code.*/

        }
        break;

        case BLE_GAP_EVT_PATH_LOSS_THRESHOLD:
        {
            printf("%d : BLE_GAP_EVT_PATH_LOSS_THRESHOLD\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        default:
        break;
    }
}

void APP_BleL2capEvtHandler(BLE_L2CAP_Event_T *p_event)
{
    switch(p_event->eventId)
    {
        case BLE_L2CAP_EVT_CONN_PARA_UPD_REQ:
        {
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_L2CAP_EVT_CONN_PARA_UPD_RSP:
        {
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_L2CAP_EVT_CB_CONN_IND:
        {
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_L2CAP_EVT_CB_CONN_FAIL_IND:
        {
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_L2CAP_EVT_CB_SDU_IND:
        {
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_L2CAP_EVT_CB_ADD_CREDITS_IND:
        {
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_L2CAP_EVT_CB_DISC_IND:
        {
            /* TODO: implement your application code.*/
        }
        break;        

        default:
        break;
    }
}

void APP_GattEvtHandler(GATT_Event_T *p_event)
{   
    switch(p_event->eventId)
    {
        case GATTC_EVT_ERROR_RESP:
        {
            printf("%d : GATTC_EVT_ERROR_RESP\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case GATTC_EVT_DISC_PRIM_SERV_RESP:
        {
            printf("%d : GATTC_EVT_DISC_PRIM_SERV_RESP\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case GATTC_EVT_DISC_PRIM_SERV_BY_UUID_RESP:
        {
            printf("%d : GATTC_EVT_DISC_PRIM_SERV_BY_UUID_RESP\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case GATTC_EVT_DISC_CHAR_RESP:
        {
            printf("%d : GATTC_EVT_DISC_CHAR_RESP\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case GATTC_EVT_DISC_DESC_RESP:
        {
            printf("%d : GATTC_EVT_DISC_DESC_RESP\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case GATTC_EVT_READ_USING_UUID_RESP:
        {
            printf("%d : GATTC_EVT_READ_USING_UUID_RESP\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case GATTC_EVT_READ_RESP:
        {
            printf("%d : GATTC_EVT_READ_RESP\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case GATTC_EVT_WRITE_RESP:
        {
            printf("%d : GATTC_EVT_WRITE_RESP\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case GATTC_EVT_HV_NOTIFY:
        {
            printf("%d : GATTC_EVT_HV_NOTIFY\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case GATTC_EVT_HV_INDICATE:
        {
            printf("%d : GATTC_EVT_HV_INDICATE\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case GATTS_EVT_READ:
        {
            printf("%d : GATTS_EVT_READ\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case GATTS_EVT_WRITE:
        {
            printf("%d : GATTS_EVT_WRITE\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case GATTS_EVT_HV_CONFIRM:
        {
            printf("%d : GATTS_EVT_HV_CONFIRM\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case ATT_EVT_TIMEOUT:
        {
            printf("%d : ATT_EVT_TIMEOUT\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case ATT_EVT_UPDATE_MTU:
        {
            printf("%d : ATT_EVT_UPDATE_MTU\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case GATTC_EVT_DISC_CHAR_BY_UUID_RESP:
        {
            printf("%d : GATTC_EVT_DISC_CHAR_BY_UUID_RESP\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case GATTS_EVT_SERVICE_CHANGE:
        {
            printf("%d : GATTS_EVT_SERVICE_CHANGE\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case GATTS_EVT_CLIENT_FEATURE_CHANGE:
        {
            printf("%d : GATTS_EVT_CLIENT_FEATURE_CHANGE\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case GATTS_EVT_CLIENT_CCCDLIST_CHANGE:
        {
            printf("%d : GATTS_EVT_CLIENT_CCCDLIST_CHANGE\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
            OSAL_Free(p_event->eventField.onClientCccdListChange.p_cccdList);
        }
        break;

        case GATTC_EVT_PROTOCOL_AVAILABLE:
        {
            printf("%d : GATTC_EVT_PROTOCOL_AVAILABLE\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        case GATTS_EVT_PROTOCOL_AVAILABLE:
        {
            printf("%d : GATTS_EVT_PROTOCOL_AVAILABLE\r\n",p_event->eventId);
            /* TODO: implement your application code.*/
        }
        break;

        default:
        break;        
    }
}

void APP_BleSmpEvtHandler(BLE_SMP_Event_T *p_event)
{
    switch(p_event->eventId)
    {
        case BLE_SMP_EVT_PAIRING_COMPLETE:
        {
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_SMP_EVT_SECURITY_REQUEST:
        {
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_SMP_EVT_NUMERIC_COMPARISON_CONFIRM_REQUEST:
        {
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_SMP_EVT_INPUT_PASSKEY_REQUEST:
        {
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_SMP_EVT_DISPLAY_PASSKEY_REQUEST:
        {
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_SMP_EVT_NOTIFY_KEYS:
        {
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_SMP_EVT_PAIRING_REQUEST:
        {
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_SMP_EVT_INPUT_OOB_DATA_REQUEST:
        {
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_SMP_EVT_INPUT_SC_OOB_DATA_REQUEST:
        {
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_SMP_EVT_KEYPRESS:
        {
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_SMP_EVT_GEN_SC_OOB_DATA_DONE:
        {
            /* TODO: implement your application code.*/
        }
        break;

        default:
        break;        
    }
}

void APP_DmEvtHandler(BLE_DM_Event_T *p_event)
{
    switch(p_event->eventId)
    {
        case BLE_DM_EVT_DISCONNECTED:
        {
            /* TODO: implement your application code.*/
        }
        break;
        
        case BLE_DM_EVT_CONNECTED:
        {
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_DM_EVT_SECURITY_START:
        {
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_DM_EVT_SECURITY_SUCCESS:
        {
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_DM_EVT_SECURITY_FAIL:
        {
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_DM_EVT_PAIRED_DEVICE_FULL:
        {
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_DM_EVT_PAIRED_DEVICE_UPDATED:
        {
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_DM_EVT_CONN_UPDATE_SUCCESS:
        {
            /* TODO: implement your application code.*/
        }
        break;

        case BLE_DM_EVT_CONN_UPDATE_FAIL:
        {
            /* TODO: implement your application code.*/
        }
        break;

        default:
        break;
    }
}

// Data
//void APP_TrspsEvtHandler(BLE_TRSPS_Event_T *p_event)
//{
//    APP_Msg_T trps_data;
//    APP_Msg_T *p_trps_data;
//    
//    switch(p_event->eventId)
//    {     
//        case BLE_TRSPS_EVT_RECEIVE_DATA:
//        {
//            /* TODO: implement your application code.*/
//            uint16_t data_len;
//            uint8_t *data;
//            // Retrieve received data length
//            // SERCOM0_USART_Write((uint8_t *)"Data receive\r\n",14);
//            BLE_TRSPS_GetDataLength(p_event->eventField.onReceiveData.connHandle, &data_len);
//            // Allocate memory according to data length
//            data = OSAL_Malloc(data_len);
//            if(data == NULL)
//            break;
//            // Retrieve received data
//            BLE_TRSPS_GetData(p_event->eventField.onReceiveData.connHandle, data);
//            // Output received data to UART
//            // SERCOM0_USART_Write(data, data_len);
//            SERCOM0_USART_Write("\r\n",2);
//
//
//
//            // data + Flag
//            
//            trps_data.msgId = APP_BLE_EVT_RECEIVE;
//            memcpy(trps_data.msgData,data_len,sizeof(data_len));
//            memcpy(trps_data.msgData+sizeof(data_len),data,data_len);
//            p_trps_data = &trps_data;
//
//            OSAL_QUEUE_Send(&appData.appQueue, p_trps_data, 0);
//            // Free memory
//            OSAL_Free(data);
//
//        }
//        break;
//       default:
//        break;
//    }
//}