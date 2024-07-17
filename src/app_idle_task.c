#include "definitions.h"

static int tick_count = 0; // 변수의 범위를 파일로 제한

void app_idle_task( void )
{
    tick_count++;
    if (tick_count <= 5){
        print_short_string(" - app_idle_task is START %d \r\n",tick_count);
    }
//    if ((tick_count % 100) == 0){
//        print_short_string(" -- app_idle_task is Counting now %d \r\n",tick_count);
//    }
}




/*-----------------------------------------------------------*/
/*******************************************************************************
 End of File
 */