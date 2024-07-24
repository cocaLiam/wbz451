#include "definitions.h"
#include <stdio.h>
#include <string.h>
#include "config/default/sys_tasks.h"

static int tick_count = 0; // 변수의 범위를 파일로 제한

void check_current_task_name( void );
void check_all_task_list( void );

void app_tick_task( void )
{
    tick_count++;
    if (tick_count <= 5){
        printf("  - app_tick_task is START %d \r\n",tick_count);
    }
    if ((tick_count % 1000) == 0){
        printf("  - app_tick_task is Counting now %d \r\n",tick_count);
        check_all_task_list();
    }
    // if ((tick_count % 5000) == 0){
    //     printf("  - xAPP_Tasks Delay STOP NOW %d \r\n",tick_count);
    //     xTaskAbortDelay(xAPP_Tasks); // xAPP_Tasks의 지연을 중단
    // }
}

void check_current_task_name( void ){
    /* 현재 진행되고 있는 Task 하나만 모니터링 */
    char buffer[100];
    TaskHandle_t xTaskHandle;

    xTaskHandle = xTaskGetCurrentTaskHandle();

    snprintf(buffer, sizeof(buffer), "Current task name: %s\r\n", pcTaskGetName(xTaskHandle));
    SERCOM1_USART_Write((uint8_t *)buffer, strlen(buffer));
}

void check_all_task_list( void ){
    /* 진행되고 있는 모든 Tasks 에 대해 모니터링 
     ex)
    +Task 이름       실행상태   우선순위   Stack사용량    Task의 TCB 번호    
     IDLE            X         0          92            2
     APP_Tasks       B         1          910           1
     APP_Tasks       R         1          910           1
     각 항목별 설명
     - 실행 상태 : Task 의 실행 상태를 표시
      - X (eXecuting): 태스크가 현재 실행 중인 상태
      - B (Blocked): 태스크가 블록된 상태 ( vTaskDelay(1000); 같은 지연 함수로 블럭됨 )
      - R (Ready): 태스크가 실행 가능한 상태이지만 아직 실행 중이지는 않은 상태 ( 지연 함수가 종료되고 Event Loop Q 에 등록만 되고 스케쥴러에 의해 선택되지 않은 상태 )
      - S (Suspended): 태스크가 일시 중단된 상태
      - D (Deleted): 태스크가 삭제된 상태
     - 우선 순위 : Task의 우선 순위. 숫자가 낮을 수록 우선순위가 높음
     - Stack 사용량 : 해당 Task 가 사용하고 있는 Stack 메모리의 크기. ex) 92면 92바이트의 스택을 사용중이란 뜻
     - Task TCB번호 : Task Control Block 내부적으로 Task 를 식별하는 데 사용 되는 고유한 번호
     */
    char taskList[256];
    vTaskList(taskList);
    
    SERCOM1_USART_Write((uint8_t *)taskList, strlen(taskList));
}