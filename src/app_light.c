#include <stdint.h>
#include <definitions.h>

void LED_Button_Callback(uintptr_t context);
void LED_Button_Handler(void);



bool Button_Debounce = false;

void APP_LIGHT_INIT(void)
{
    // pinMode(GPIO_PIN_RB4,INPUT);
    pinMode(GPIO_PIN_RB3,OUTPUT);
    EIC_InterruptEnable(EIC_PIN_0);
    EIC_CallbackRegister(EIC_PIN_0, LED_Button_Callback, 0);
}

void LED_Button_Callback(uintptr_t context)
{
    if(!Button_Debounce)
    {
        print_short_string("Button_Debounce - Interrupt\r\n");
        Button_Debounce = true;
    }    
}

void LED_Button_Handler(void)
{
    if(Button_Debounce)
    {
        GPIO_PinToggle(GPIO_PIN_RB3);
        print_short_string("Run\r\n");
        Button_Debounce = false;
    }
}

// void Get_Data_LED_Adjust(void)
// {
//     pinMode(GPIO_PIN_RB3,OUTPUT);
//     pinMode(GPIO_PIN_RB4,INPUT);
//     bool RB3_LED_SIGNAL = false;

//     if (GPIO_PinRead(GPIO_PIN_RB4) == 0)
//     {
//         if (RB3_LED_SIGNAL == false)
//         {
//             RB3_LED_SIGNAL = true;
//             pinSet(GPIO_PIN_RB3);
//             print_short_string("LED_ON");
//             for (int i = 0; i < 5; i++)
//             {
//                 print_short_string(". ");
//                 vTaskDelay(500);
//             }
//             print_short_string("LED_OFF\r\n");    
//         }
//     }
//     if (GPIO_PinRead(GPIO_PIN_RB4) == 1)
//     {
//         GPIO_PinClear(GPIO_PIN_RB3);
//         RB3_LED_SIGNAL = false;
//     }
// }
