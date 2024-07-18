
#include "../../config/default/peripheral/gpio/plib_gpio.h"
#include <device.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <definitions.h>


bool pinMode(GPIO_PIN pin, int mode)
{

    if (0U<=pin&&pin<30U)
    {
        InOutChange(pin,mode);
        return true;
    }
    return false;
}

void InOutChange(GPIO_PIN pin,int mode)
{
    if (mode == 1)
    {
        GPIO_PinOutputEnable(pin);
    }
    else if(mode == 0)
    {
        GPIO_PinInputEnable(pin);
    }
    
}

bool pinSet(GPIO_PIN pin)
{
    if (0U<=pin&&pin<30U)
    {
        GPIO_PinSet(pin);
        return true;
    }
    return false;
}

bool pinClear(GPIO_PIN pin)
{
    if (0U<=pin&&pin<30U)
    {
        GPIO_PinClear(pin);
        return true;
    }
    return false;
}
