#ifndef CUSTOM_FUNCTION_H
#define CUSTOM_FUNCTION_H

#include "custom_timer.h"
#include "custom_key.h"
#include "custom_led.h"

/**************************************************************************************/

#define APP_RES_SUCCESS                         (0x0000U)               /**< Execution successfully. */
#define APP_RES_FAIL                            (0x0001U)               /**< Execution fail. */
#define APP_RES_OOM                             (0x0002U)               /**< Out of memory. */
#define APP_RES_INVALID_PARA                    (0x0003U)               /**< Invalid parameters. */
#define APP_RES_NO_RESOURCE                     (0x0004U)               /**< No resource. */
#define APP_RES_BAD_STATE                       (0x0005U)               /**< Bad State. */
#define APP_RES_PENDING_DUE_TO_SECURITY         (0x0006U)               /**< Pending the request due to security process. */
#define APP_RES_BUSY                            (0x0007U)               /**< Execution fail due to system is busy. */
#define APP_RES_COMPLETE                        (0x1000)                /**< Some procedure is complete to distinguish execution successfully */


#endif