#include <stdint.h>
#include "app.h"
#include "app_ble/app_ble_handler.h"
#include "ble_cms/ble_print_svc.h"
#include "system/console/sys_console.h"
#include "func1_print.h"

#include"../config/default/peripheral/gpio/plib_gpio.h"

DEV_STATE devData = {OFF_POSITION, STOPPED}; // default OFF, OFF


void hbridge7_motor_control ( uint8_t ctrl )
{
    switch ( ctrl )
    {
        case 1:
        {
//            SLP_Set();
            EN_Set();
            PH_Clear();
            break;
        }
        case 2:
        {
//            SLP_Set();
            EN_Clear();          
            PH_Set();
            break;
        }


        default:
        {
            break;
        }
    }
}










void func1_print_callback(uintptr_t context)
{
    APP_Msg_T appMsg;
    appMsg.msgId = APP_MSG_FUNC1;
    memcpy(appMsg.msgData, (void *)context, (size_t)2);
    OSAL_QUEUE_Send(&appData.appQueue, (void *)&appMsg, 0);
}

uint8_t func1_print(uint8_t *p_cmd)
{
    devData.position = p_cmd[0];
    devData.operation = p_cmd[1];

    switch (devData.position)
    {
        case OFF_POSITION:
        {
            if ((devData.operation != STOPPED) && (devData.operation != RUNNING))
            {
                SYS_CONSOLE_PRINT("OFF_POSITION : OPERATION ERROR (%d)\r\n",devData.operation);
            }
            else if (devData.operation == STOPPED)
            {
                SYS_CONSOLE_PRINT("OFF POSITION : STOPPED (%d , %d)\r\n", devData.position ,devData.operation);
                hbridge7_motor_control(1);
            }
            else
            {
                SYS_CONSOLE_PRINT("OFF POSITION : RUNNING (%d , %d)\r\n", devData.position ,devData.operation);
                hbridge7_motor_control(2);

            }   
        }
        break;

        case ON_POSITION:
        {
            if ((devData.operation != STOPPED) && (devData.operation != RUNNING))
            {
                SYS_CONSOLE_PRINT("ON_POSITION : OPERATION ERROR (%d)\r\n",devData.operation);
            }
            else if (devData.operation == STOPPED)
            {
                SYS_CONSOLE_PRINT("ON_POSITION : STOPPED (%d , %d)\r\n", devData.position ,devData.operation);
            }
            else
            {
                SYS_CONSOLE_PRINT("ON_POSITION : RUNNING (%d , %d)\r\n", devData.position ,devData.operation);
            } 
        }
        break;

        default:
        {
            SYS_CONSOLE_PRINT("POSITION ERROR (%d) \r\n",devData.position);
        }
        break;

        return MBA_RES_SUCCESS;
    }
    
    
    
    

return MBA_RES_SUCCESS;
}
