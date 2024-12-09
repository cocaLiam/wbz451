//!!! Service Name of Service 0 is invalid !!!
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
  BLE Communication Service Source File

  Company:
    Microchip Technology Inc.

  File Name:
    ble_communication_svc.c

  Summary:
    This file contains the BLE Communication Service functions for application user.

  Description:
    This file contains the BLE Communication Service functions for application user.
 *******************************************************************************/


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <stddef.h>
#include "gatt.h"
#include "ble_util/byte_stream.h"
#include "ble_cms/ble_communication_svc.h"


// *****************************************************************************
// *****************************************************************************
// Section: Macros
// *****************************************************************************
// *****************************************************************************
/* Little Endian. */
#define UUID_COMMUNICATION_PRIMARY_SVC_LE         0x55, 0xE4, 0x05, 0xD2, 0xAF, 0x9F, 0xA9, 0x8F, 0xE5, 0x4A, 0x7D, 0xFE, 0x43, 0x53, 0x53, 0x49    /* Service UUID */

#define UUID_COMMUNICATION_CHARACTERISTIC_0_LE         0x16, 0x96, 0x24, 0x47, 0xC6, 0x23, 0x61, 0xBA, 0xD9, 0x4B, 0x4D, 0x1E, 0x43, 0x53, 0x53, 0x49    /* Characteristic 0 UUID */
#define UUID_COMMUNICATION_CHARACTERISTIC_1_LE         0xB3, 0x9B, 0x72, 0x34, 0xBE, 0xEC, 0xD4, 0xA8, 0xF4, 0x43, 0x41, 0x88, 0x43, 0x53, 0x53, 0x49    /* Characteristic 1 UUID */

// *****************************************************************************
// *****************************************************************************
// Section: Local Variables
// *****************************************************************************
// *****************************************************************************

/* Primary Service Declaration */
static const uint8_t s_communicationSvcUuid[] = {UUID_COMMUNICATION_PRIMARY_SVC_LE};
static const uint16_t s_communicationSvcUuidLen = sizeof(s_communicationSvcUuid);

/* Communication Characteristic 0 Characteristic */
static const uint8_t s_communicationChar0[] = {ATT_PROP_INDICATE, UINT16_TO_BYTES(COMMUNICATION_HDL_CHARVAL_0), UUID_COMMUNICATION_CHARACTERISTIC_0_LE};    /* Indicate */
static const uint16_t s_communicationChar0Len = sizeof(s_communicationChar0);

/* Communication Characteristic 0 Characteristic Value */
static const uint8_t s_communicationUuidChar0[] = {UUID_COMMUNICATION_CHARACTERISTIC_0_LE};
static uint8_t s_communicationChar0Val[] = {0x00};    /* Default Value */
static uint16_t s_communicationChar0ValLen = sizeof(s_communicationChar0Val);

/* Communication Characteristic 0 Client Characteristic Configuration Descriptor */
static uint8_t s_communicationCccChar0[] = {UINT16_TO_BYTES(0x0000)};
static const uint16_t s_communicationCccChar0Len = sizeof(s_communicationCccChar0);

/* Communication Characteristic 1 Characteristic */
static const uint8_t s_communicationChar1[] = {ATT_PROP_READ, UINT16_TO_BYTES(COMMUNICATION_HDL_CHARVAL_1), UUID_COMMUNICATION_CHARACTERISTIC_1_LE};    /* Read */
static const uint16_t s_communicationChar1Len = sizeof(s_communicationChar1);

/* Communication Characteristic 1 Characteristic Value */
static const uint8_t s_communicationUuidChar1[] = {UUID_COMMUNICATION_CHARACTERISTIC_1_LE};
static uint8_t s_communicationChar1Val[] = {0x00};    /* Default Value */
static uint16_t s_communicationChar1ValLen = sizeof(s_communicationChar1Val);

/* Attribute list for Communication service */
static GATTS_Attribute_T s_communicationList[] = {
    /* Service Declaration */
    {
        (uint8_t *) g_gattUuidPrimSvc,
        (uint8_t *) s_communicationSvcUuid,
        (uint16_t *) & s_communicationSvcUuidLen,
        sizeof (s_communicationSvcUuid),
        0,
        PERMISSION_READ
    },
    /* Characteristic 0 Declaration */
    {
        (uint8_t *) g_gattUuidChar,
        (uint8_t *) s_communicationChar0,
        (uint16_t *) & s_communicationChar0Len,
        sizeof (s_communicationChar0),
        0,
        PERMISSION_READ
    },
    /* Characteristic 0 Value */
    {
        (uint8_t *) s_communicationUuidChar0,
        (uint8_t *) s_communicationChar0Val,
        (uint16_t *) & s_communicationChar0ValLen,
        sizeof(s_communicationChar0Val),
        SETTING_UUID_16,    
        0    
    },
    /* Client Characteristic Configuration Descriptor */
    {
        (uint8_t *) g_descUuidCcc,
        (uint8_t *) s_communicationCccChar0,
        (uint16_t *) & s_communicationCccChar0Len,
        sizeof (s_communicationCccChar0),
        SETTING_CCCD,    
        PERMISSION_READ|PERMISSION_WRITE    
    },
    /* Characteristic 1 Declaration */
    {
        (uint8_t *) g_gattUuidChar,
        (uint8_t *) s_communicationChar1,
        (uint16_t *) & s_communicationChar1Len,
        sizeof (s_communicationChar1),
        0,
        PERMISSION_READ
    },
    /* Characteristic 1 Value */
    {
        (uint8_t *) s_communicationUuidChar1,
        (uint8_t *) s_communicationChar1Val,
        (uint16_t *) & s_communicationChar1ValLen,
        sizeof(s_communicationChar1Val),
        SETTING_UUID_16,    
        PERMISSION_READ    
    },
};

static const GATTS_CccdSetting_T s_communicationCccdSetting[] = 
{
    {COMMUNICATION_HDL_CCCD_0, INDICATION},
};

/* Communication Service structure */
static GATTS_Service_T s_communicationSvc = 
{
    NULL,
    (GATTS_Attribute_T *) s_communicationList,
    (GATTS_CccdSetting_T const *)s_communicationCccdSetting,
    COMMUNICATION_START_HDL,
    COMMUNICATION_END_HDL,
    1
};

// *****************************************************************************
// *****************************************************************************
// Section: Functions
// *****************************************************************************
// *****************************************************************************

uint16_t BLE_COMMUNICATION_Add(void)
{
    return GATTS_AddService(&s_communicationSvc, (COMMUNICATION_END_HDL - COMMUNICATION_START_HDL + 1));
}
