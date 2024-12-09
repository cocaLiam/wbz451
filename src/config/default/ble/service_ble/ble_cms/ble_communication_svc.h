
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
  BLE Communication Service Header File

  Company:
    Microchip Technology Inc.

  File Name:
    ble_communication_svc.h

  Summary:
    This file contains the BLE Communication Service functions for application user.

  Description:
    This file contains the BLE Communication Service functions for application user.
 *******************************************************************************/


/**
 * @addtogroup BLE_COMMUNICATION BLE COMMUNICATION
 * @{
 * @brief Header file for the BLE Communication Service.
 * @note Definitions and prototypes for the BLE Communication Service stack layer application programming interface.
 */
#ifndef BLE_COMMUNICATION_H
#define BLE_COMMUNICATION_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <stdint.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Macros
// *****************************************************************************
// *****************************************************************************
/**@defgroup BLE_COMMUNICATION_ASSIGN_HANDLE BLE_COMMUNICATION_ASSIGN_HANDLE
 * @brief Assigned attribute handles of BLE Communication Service.
 * @{ */
#define COMMUNICATION_START_HDL                               0x8000                                   /**< The start attribute handle of communication service. */
/** @} */

/**@brief Definition of BLE Communication Service attribute handle */
typedef enum BLE_COMMUNICATION_AttributeHandle_T
{
    COMMUNICATION_HDL_SVC = COMMUNICATION_START_HDL,           /**< Handle of Primary Service. */
    COMMUNICATION_HDL_CHAR_0,                            /**< Handle of characteristic 0. */
    COMMUNICATION_HDL_CHARVAL_0,                         /**< Handle of characteristic 0 value. */
    COMMUNICATION_HDL_CCCD_0,                            /**< Handle of characteristic 0 CCCD . */
    COMMUNICATION_HDL_CHAR_1,                            /**< Handle of characteristic 1. */
    COMMUNICATION_HDL_CHARVAL_1,                         /**< Handle of characteristic 1 value. */
}BLE_COMMUNICATION_AttributeHandle_T;

/**@defgroup BLE_COMMUNICATION_ASSIGN_HANDLE BLE_COMMUNICATION_ASSIGN_HANDLE
 * @brief Assigned attribute handles of BLE Communication Service.
 * @{ */
#define COMMUNICATION_END_HDL                                 (COMMUNICATION_HDL_CHARVAL_1)         /**< The end attribute handle of communication service. */
/** @} */


// *****************************************************************************
// *****************************************************************************
// Section: Function Prototypes
// *****************************************************************************
// *****************************************************************************
/**
 *@brief Initialize BLE Communication Service callback function.
 *
 *
 *@return MBA_RES_SUCCESS                    Successfully register BLE Communication service.
 *@return MBA_RES_NO_RESOURCE                Fail to register service.
 *
 */
uint16_t BLE_COMMUNICATION_Add(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END


#endif

/**
  @}
 */
