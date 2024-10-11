/*******************************************************************************
 System Idle Task File

  File Name:
    custom_pin_setting.c

  Summary:
    핀의 입출력 방향, 할당 등에 대한 코드

  Remarks:
 *******************************************************************************/
#include "definitions.h"
 /*******************************************************************************/

// 0. Init

// void CustomPinInit(void)
// {

// }


//1. 핀 모드

void PinInit(void)
{
  
}



bool PinMode(PinNumber pin , PinDirection direction)
{
  if (direction == INPUT)
  {
    ((gpio_registers_t*)(GPIOA_BASE_ADDRESS + (0x100U * (pin>>4U))))->GPIO_TRISSET= (uint32_t)0x1U << (pin & 0xFU);
    return false;
  }
  else
  {
    ((gpio_registers_t*)(GPIOA_BASE_ADDRESS + (0x100U * (pin>>4U))))->GPIO_TRISCLR = (uint32_t)0x1U << (pin & 0xFU);
    return true;
  }
}
    
bool PinSet(PinNumber pin , PinState state){
  if (state == OFF)
  {
    ((gpio_registers_t*)(GPIOA_BASE_ADDRESS + (0x100U * (pin>>4U))))->GPIO_LATCLR = (uint32_t)0x1U << (pin & 0xFU);
    return false;
  }
  else
  {
    ((gpio_registers_t*)(GPIOA_BASE_ADDRESS + (0x100U * (pin>>4U))))->GPIO_LATSET = (uint32_t)0x1U << (pin & 0xFU);
    return true;
  }
}

void PinToggle(PinNumber pin)
{
  ((gpio_registers_t*)(GPIOA_BASE_ADDRESS + (0x100U * (pin>>4U))))->GPIO_LATINV = (uint32_t)0x1U << (pin & 0xFU);
}

// 2. 핀 출력

// void PinOn(PinNumber pin)
// {
    
// }

// 3. 핀 Clear

// void PinOff(PinNumber pin)
// {

// }

// 4. 핀 toggle

// void PinToggle(PinNumber pin)


