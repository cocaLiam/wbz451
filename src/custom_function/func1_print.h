#ifndef FUNC1_PRINT_H
#define FUNC1_PRINT_H


enum DEV_POSITION
{
    OFF_POSITION = 0x00,
    ON_POSITION = 0x01
};

enum DEV_OPERATION_STATE
{
    STOPPED = 0x00,
    RUNNING = 0x01
};








typedef struct DEV_STATE
{
   
    uint8_t position; // Off Position (0) On Position (1)
    uint8_t operation; // Stopped (0) , Running (1)

} DEV_STATE ;


void func1_print_callback(uintptr_t context);
uint8_t func1_print(uint8_t *p_cmd);



#endif