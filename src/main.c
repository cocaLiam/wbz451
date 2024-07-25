/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes


// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
//    /* Initialize all modules */
    SYS_Initialize ( NULL );
    // 반드시 SERCOM1_USART_Write 는 SYS_Initialize 함수 안에 있는 
    // SERCOM1_USART_Initialize(); 초기화 작업을 해준 후 써야 한다.

    printf("SYS_Initialize END \r\n");
    GPIO_RB3_Set();
    SERCOM1_USART_Write((uint8_t *)"SYS_Initialize END \r\n",21);
//    vTaskDelay(1000); // task.c 에 있는 vTaskStartScheduler(); 함수가 호출되기 전 까진 쓰면 안된다
//    GPIO_RB3_Clear();


    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

