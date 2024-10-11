#ifndef CUSTOM_FUNCTION_H
#define CUSTOM_FUNCTION_H






typedef enum{
    RED = PB0,
    GREEN = PB3,
    BLUE = PB5,
    NONE = -1,
}ColorList;

typedef enum{
    CURRENT_LED_OFF,
    CURRENT_LED_ON,
    CURRENT_LED_BLINK,
}LED_STATE;


typedef struct
{
    LED_STATE led_state;
    ColorList led_color;
}CUSTOM_LED;


void LED_INIT(void);
void LED_ON(ColorList color);
void LED_OFF(ColorList color);
void LED_BLINK(ColorList color, int period);

#endif