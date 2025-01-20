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
  BLE Ble_print Service Source File

  Company:
    Microchip Technology Inc.

  File Name:
    ble_ble_print_svc.c

  Summary:
    This file contains the BLE Ble_print Service functions for application user.

  Description:
    This file contains the BLE Ble_print Service functions for application user.
 *******************************************************************************/


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <stddef.h>
#include "gatt.h"
#include "ble_util/byte_stream.h"
#include "ble_cms/ble_ble_print_svc.h"


// *****************************************************************************
// *****************************************************************************
// Section: Macros
// *****************************************************************************
// *****************************************************************************
/* Little Endian. */
#define UUID_BLE_PRINT_PRIMARY_SVC_LE         0x55, 0xE4, 0x05, 0xD2, 0xAF, 0x9F, 0xA9, 0x8F, 0xE5, 0x4A, 0x7D, 0xFE, 0x43, 0x53, 0x53, 0x49    /* Service UUID */

#define UUID_BLE_PRINT_CHARACTERISTIC_0_LE         0x16, 0x96, 0x24, 0x47, 0xC6, 0x23, 0x61, 0xBA, 0xD9, 0x4B, 0x4D, 0x1E, 0x43, 0x53, 0x53, 0x49    /* Characteristic 0 UUID */
#define UUID_BLE_PRINT_CHARACTERISTIC_1_LE         0xB3, 0x9B, 0x72, 0x34, 0xBE, 0xEC, 0xD4, 0xA8, 0xF4, 0x43, 0x41, 0x88, 0x43, 0x53, 0x53, 0x49    /* Characteristic 1 UUID */

// *****************************************************************************
// *****************************************************************************
// Section: Local Variables
// *****************************************************************************
// *****************************************************************************

/* Primary Service Declaration */
static const uint8_t s_ble_printSvcUuid[] = {UUID_BLE_PRINT_PRIMARY_SVC_LE};
static const uint16_t s_ble_printSvcUuidLen = sizeof(s_ble_printSvcUuid);

/* Ble_print Characteristic 0 Characteristic */
static const uint8_t s_ble_printChar0[] = {ATT_PROP_READ, UINT16_TO_BYTES(BLE_PRINT_HDL_CHARVAL_0), UUID_BLE_PRINT_CHARACTERISTIC_0_LE};    /* Read */
static const uint16_t s_ble_printChar0Len = sizeof(s_ble_printChar0);

/* Ble_print Characteristic 0 Characteristic Value */
static const uint8_t s_ble_printUuidChar0[] = {UUID_BLE_PRINT_CHARACTERISTIC_0_LE};
static uint8_t s_ble_printChar0Val[] = {0x00};    /* Default Value */
static uint16_t s_ble_printChar0ValLen = sizeof(s_ble_printChar0Val);

/* Ble_print Characteristic 1 Characteristic */
static const uint8_t s_ble_printChar1[] = {ATT_PROP_WRITE_REQ, UINT16_TO_BYTES(BLE_PRINT_HDL_CHARVAL_1), UUID_BLE_PRINT_CHARACTERISTIC_1_LE};    /* Write with response */
static const uint16_t s_ble_printChar1Len = sizeof(s_ble_printChar1);

/* Ble_print Characteristic 1 Characteristic Value */
static const uint8_t s_ble_printUuidChar1[] = {UUID_BLE_PRINT_CHARACTERISTIC_1_LE};
static uint8_t s_ble_printChar1Val[2] = {};    /* Default Value */
static uint16_t s_ble_printChar1ValLen = sizeof(s_ble_printChar1Val);

/* Attribute list for Ble_print service */
static GATTS_Attribute_T s_ble_printList[] = {
    /* Service Declaration */
    {
        (uint8_t *) g_gattUuidPrimSvc,
        (uint8_t *) s_ble_printSvcUuid,
        (uint16_t *) & s_ble_printSvcUuidLen,
        sizeof (s_ble_printSvcUuid),
        0,
        PERMISSION_READ
    },
    /* Characteristic 0 Declaration */
    {
        (uint8_t *) g_gattUuidChar,
        (uint8_t *) s_ble_printChar0,
        (uint16_t *) & s_ble_printChar0Len,
        sizeof (s_ble_printChar0),
        0,
        PERMISSION_READ
    },
    /* Characteristic 0 Value */
    {
        (uint8_t *) s_ble_printUuidChar0,
        (uint8_t *) s_ble_printChar0Val,
        (uint16_t *) & s_ble_printChar0ValLen,
        sizeof(s_ble_printChar0Val),
        SETTING_MANUAL_READ_RSP|SETTING_UUID_16,    /* Manual Read Response */
        PERMISSION_READ    
    },
    /* Characteristic 1 Declaration */
    {
        (uint8_t *) g_gattUuidChar,
        (uint8_t *) s_ble_printChar1,
        (uint16_t *) & s_ble_printChar1Len,
        sizeof (s_ble_printChar1),
        0,
        PERMISSION_READ
    },
    /* Characteristic 1 Value */
    {
        (uint8_t *) s_ble_printUuidChar1,
        (uint8_t *) s_ble_printChar1Val,
        (uint16_t *) & s_ble_printChar1ValLen,
        sizeof(s_ble_printChar1Val),
        SETTING_UUID_16,    
        PERMISSION_WRITE    
    },
};


/* Ble_print Service structure */
static GATTS_Service_T s_ble_printSvc = 
{
    NULL,
    (GATTS_Attribute_T *) s_ble_printList,
    NULL,
    BLE_PRINT_START_HDL,
    BLE_PRINT_END_HDL,
    0
};

// *****************************************************************************
// *****************************************************************************
// Section: Functions
// *****************************************************************************
// *****************************************************************************

uint16_t BLE_BLE_PRINT_Add(void)
{
    return GATTS_AddService(&s_ble_printSvc, (BLE_PRINT_END_HDL - BLE_PRINT_START_HDL + 1));
}
