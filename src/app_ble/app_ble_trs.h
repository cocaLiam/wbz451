// /* ************************************************************************** */

// //  @Company
// //    LIFE_BENEFIT
// //
// //  @File Name
// //    app_ble_trs.h
// //
// //  @Author
// //    MOON

// /* ************************************************************************** */

// #ifndef APP_BLE_TRS_H
// #define APP_BLE_TRS_H

// // *****************************************************************************
// // *****************************************************************************
// // Section: Included Files
// // *****************************************************************************
// // *****************************************************************************

// #include "stack_mgr.h"

// // *****************************************************************************
// // *****************************************************************************
// // Section: Macros
// // *****************************************************************************
// // *****************************************************************************

// #define BLE_TRSPS_MAX_CONN_NBR                  BLE_GAP_MAX_LINK_NBR

// #define BLE_TRSPS_STATUS_CTRL_DISABLED          (0x00U)
// #define BLE_TRSPS_STATUS_CTRL_OPENED            (0x01U)
// #define BLE_TRSPS_STATUS_TX_DISABLED            (0x00U)
// #define BLE_TRSPS_STATUS_TX_OPENED              (0x01U)



// // *****************************************************************************
// // *****************************************************************************
// // Section: Data Types
// // *****************************************************************************
// // *****************************************************************************

// typedef enum BLE_TRSPS_EventId_T
// {   
//     BLE_TRSPS_EVT_RECEIVE_DATA   
    
// }BLE_TRSPS_EventId_T;

// // *****************************************************************************

// typedef struct BLE_TRSPS_EvtCtrlStatus_T
// {
//     uint16_t         connHandle;                                            
//     uint8_t          status;                                                
// }   BLE_TRSPS_EvtCtrlStatus_T;

// typedef struct BLE_TRSPS_EvtTxStatus_T
// {
//     uint16_t         connHandle;                                           
//     uint8_t          status;                                               
// }   BLE_TRSPS_EvtTxStatus_T;

// typedef struct BLE_TRSPS_EvtCbfcEnabled_T
// {
//     uint16_t         connHandle;                                           
// }BLE_TRSPS_EvtCbfcEnabled_T;


// typedef struct BLE_TRSPS_EvtReceiveData_T
// {
//     uint16_t         connHandle;                                           
// }BLE_TRSPS_EvtReceiveData_T;


// typedef struct BLE_TRSPS_EvtVendorCmd_T
// {
//     uint16_t         connHandle;                                           
//     uint16_t         length;										
//     uint8_t          *p_payLoad;                                           
// }BLE_TRSPS_EvtVendorCmd_T;


// typedef union
// {
//     BLE_TRSPS_EvtCtrlStatus_T        onCtrlStatus;           
//     BLE_TRSPS_EvtTxStatus_T          onTxStatus;             
//     BLE_TRSPS_EvtCbfcEnabled_T       onCbfcEnabled;          
//     BLE_TRSPS_EvtReceiveData_T       onReceiveData;          
//     BLE_TRSPS_EvtVendorCmd_T         onVendorCmd;            
// } BLE_TRSPS_EventField_T;

// typedef struct  BLE_TRSPS_Event_T
// {
//     BLE_TRSPS_EventId_T       eventId;                        
//     BLE_TRSPS_EventField_T    eventField;                     
// } BLE_TRSPS_Event_T;

// typedef struct  BLE_TRSPS_Uuids_T
// {
//     uint8_t *p_primaryService;                    
//     uint8_t *p_transTx;                           
//     uint8_t *p_transRx;                           
//     uint8_t *p_transCtrl;                         
// } BLE_TRSPS_Uuids_T;

// typedef void(*BLE_TRSPS_EventCb_T)(BLE_TRSPS_Event_T *p_event);

// // *****************************************************************************
// // *****************************************************************************
// // Section: Function Prototypes
// // *****************************************************************************
// // *****************************************************************************

// void BLE_TRSPS_EventRegister(BLE_TRSPS_EventCb_T bleTranServHandler);

// uint16_t BLE_TRSPS_Init(void);

// uint16_t BLE_TRSPS_SendVendorCommand(uint16_t connHandle, uint8_t commandID, uint8_t commandLength, uint8_t *p_commandPayload);

// uint16_t BLE_TRSPS_SendData(uint16_t connHandle, uint16_t len, uint8_t *p_data);

// void BLE_TRSPS_GetDataLength(uint16_t connHandle, uint16_t *p_dataLength);

// uint16_t BLE_TRSPS_GetData(uint16_t connHandle, uint8_t *p_data);

// void BLE_TRSPS_BleEventHandler(STACK_Event_T *p_stackEvent);


// #endif