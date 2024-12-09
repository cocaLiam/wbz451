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
  Application BLE Utility Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_ble_utility.c

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
#include "osal/osal_freertos_extend.h"
#include "app_ble_utility.h"
#include "ble_dm/ble_dm.h"

#include "definitions.h"


// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

typedef enum APP_PdsAppItem_T{
    PDS_APP_ITEM_ID_1 = (PDS_MODULE_APP_OFFSET),
    PDS_APP_ITEM_ID_2

}APP_PdsAppItem_T;


// *****************************************************************************
// *****************************************************************************
// Section: Macros
// *****************************************************************************
// *****************************************************************************
#define SLOT_NUMBER                     (1)
#define AUTHEN_RAM_HOLDER               (3244)

#define APP_RANDOM_BYTE_LEN 32

#define APP_BLE_GAP_RANDOM_SUB_TYPE_MASK           (0xC0U)
#define APP_BLE_GAP_RESOLVABLE_ADDR                (0x40U)
#define APP_BLE_GAP_NON_RESOLVABLE_ADDR            (0x00U)
#define APP_BLE_GAP_STATIC_ADDR                    (0xC0U)

// *****************************************************************************
// *****************************************************************************
// Section: Global Variables
// *****************************************************************************
// *****************************************************************************

//APP_PairedDevInfo_T Global_PairedDevInfo;
//APP_ExtPairedDevInfo_T Global_ExtPairedDevInfo;

// *****************************************************************************
// *****************************************************************************
// Section: Local Variables
// *****************************************************************************
// *****************************************************************************

//static APP_ExtPairedDevInfo_T Static_ExtPairedDEvInfo;
//static APP_PairedDevInfo_T  Static_PairedDevGattInfoBuf;

// *****************************************************************************
// *****************************************************************************
// Section: Functions
// *****************************************************************************
// *****************************************************************************

bool APP_ImageValidation(void)
{
    uint8_t *p_ram;
    bool    result;
    
    p_ram = OSAL_Malloc(AUTHEN_RAM_HOLDER);
    if (p_ram == NULL)
    {
        return false;
    }

    // Calling function authenticate_fw_image in boot flash at 0x5000. The input 
    // parameter is the slot number - 0 or 1, followed by pointer to 3244B memory for ECDSA engine
    result = ((bool (*)(uint8_t slot, uint8_t *p_ram))0x5001)(SLOT_NUMBER, p_ram);
    OSAL_Free(p_ram);

    return result;
}
