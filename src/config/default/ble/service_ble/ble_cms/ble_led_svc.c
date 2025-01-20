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
  BLE Ble_led Service Source File

  Company:
    Microchip Technology Inc.

  File Name:
    ble_ble_led_svc.c

  Summary:
    This file contains the BLE Ble_led Service functions for application user.

  Description:
    This file contains the BLE Ble_led Service functions for application user.
 *******************************************************************************/


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <stddef.h>
#include "gatt.h"
#include "ble_util/byte_stream.h"
#include "ble_cms/ble_led_svc.h"


// *****************************************************************************
// *****************************************************************************
// Section: Macros
// *****************************************************************************
// *****************************************************************************
/* Little Endian. */
#define UUID_BLE_LED_PRIMARY_SVC_LE         0x5c, 0x07, 0xf6, 0x9f, 0x85, 0x68, 0x49, 0x4a, 0x91, 0x66, 0xa8, 0xc2, 0xe3, 0x7d, 0x32, 0x40    /* Service UUID */

#define UUID_BLE_LED_CHARACTERISTIC_0_LE         0x6c, 0x07, 0xf6, 0x9f, 0x85, 0x68, 0x49, 0x4a, 0x91, 0x66, 0xa8, 0xc2, 0xe3, 0x7d, 0x32, 0x40    /* Characteristic 0 UUID */
#define UUID_BLE_LED_CHARACTERISTIC_1_LE         0x7c, 0x07, 0xf6, 0x9f, 0x85, 0x68, 0x49, 0x4a, 0x91, 0x66, 0xa8, 0xc2, 0xe3, 0x7d, 0x32, 0x40    /* Characteristic 1 UUID */

// *****************************************************************************
// *****************************************************************************
// Section: Local Variables
// *****************************************************************************
// *****************************************************************************

/* Primary Service Declaration */
static const uint8_t s_ble_ledSvcUuid[] = {UUID_BLE_LED_PRIMARY_SVC_LE};
static const uint16_t s_ble_ledSvcUuidLen = sizeof(s_ble_ledSvcUuid);

/* Ble_led Characteristic 0 Characteristic */
static const uint8_t s_ble_ledChar0[] = {ATT_PROP_READ, UINT16_TO_BYTES(BLE_LED_HDL_CHARVAL_0), UUID_BLE_LED_CHARACTERISTIC_0_LE};    /* Read */
static const uint16_t s_ble_ledChar0Len = sizeof(s_ble_ledChar0);

/* Ble_led Characteristic 0 Characteristic Value */
static const uint8_t s_ble_ledUuidChar0[] = {UUID_BLE_LED_CHARACTERISTIC_0_LE};
static uint8_t s_ble_ledChar0Val[] = {0x00};    /* Default Value */
static uint16_t s_ble_ledChar0ValLen = sizeof(s_ble_ledChar0Val);

/* Ble_led Characteristic 1 Characteristic */
static const uint8_t s_ble_ledChar1[] = {ATT_PROP_WRITE_REQ, UINT16_TO_BYTES(BLE_LED_HDL_CHARVAL_1), UUID_BLE_LED_CHARACTERISTIC_1_LE};    /* Write with response */
static const uint16_t s_ble_ledChar1Len = sizeof(s_ble_ledChar1);

/* Ble_led Characteristic 1 Characteristic Value */
static const uint8_t s_ble_ledUuidChar1[] = {UUID_BLE_LED_CHARACTERISTIC_1_LE};
static uint8_t s_ble_ledChar1Val[2] = {};    /* Default Value */
static uint16_t s_ble_ledChar1ValLen = sizeof(s_ble_ledChar1Val);

/* Attribute list for Ble_led service */
static GATTS_Attribute_T s_ble_ledList[] = {
    /* Service Declaration */
    {
        (uint8_t *) g_gattUuidPrimSvc,
        (uint8_t *) s_ble_ledSvcUuid,
        (uint16_t *) & s_ble_ledSvcUuidLen,
        sizeof (s_ble_ledSvcUuid),
        0,
        PERMISSION_READ
    },
    /* Characteristic 0 Declaration */
    {
        (uint8_t *) g_gattUuidChar,
        (uint8_t *) s_ble_ledChar0,
        (uint16_t *) & s_ble_ledChar0Len,
        sizeof (s_ble_ledChar0),
        0,
        PERMISSION_READ
    },
    /* Characteristic 0 Value */
    {
        (uint8_t *) s_ble_ledUuidChar0,
        (uint8_t *) s_ble_ledChar0Val,
        (uint16_t *) & s_ble_ledChar0ValLen,
        sizeof(s_ble_ledChar0Val),
        SETTING_MANUAL_READ_RSP|SETTING_UUID_16,    /* Manual Read Response */
        PERMISSION_READ    
    },
    /* Characteristic 1 Declaration */
    {
        (uint8_t *) g_gattUuidChar,
        (uint8_t *) s_ble_ledChar1,
        (uint16_t *) & s_ble_ledChar1Len,
        sizeof (s_ble_ledChar1),
        0,
        PERMISSION_READ
    },
    /* Characteristic 1 Value */
    {
        (uint8_t *) s_ble_ledUuidChar1,
        (uint8_t *) s_ble_ledChar1Val,
        (uint16_t *) & s_ble_ledChar1ValLen,
        sizeof(s_ble_ledChar1Val),
        SETTING_UUID_16,    
        PERMISSION_WRITE    
    },
};


/* Ble_led Service structure */
static GATTS_Service_T s_ble_ledSvc = 
{
    NULL,
    (GATTS_Attribute_T *) s_ble_ledList,
    NULL,
    BLE_LED_START_HDL,
    BLE_LED_END_HDL,
    0
};

// *****************************************************************************
// *****************************************************************************
// Section: Functions
// *****************************************************************************
// *****************************************************************************

uint16_t BLE_LED_Add(void)
{
    return GATTS_AddService(&s_ble_ledSvc, (BLE_LED_END_HDL - BLE_LED_START_HDL + 1));
}
