#include "definitions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// utils_print
// utils_funtions
// 1번 방법: 자동 변수 사용 [ 스택 ]
void print_short_string(const char *format, ...) {
/*
사용법 :
print_short_string("tick Count 1: %d\r\n", 변수);

장점 :
스택에 자동 변수로 할당되므로 메모리 할당과 해제가 자동으로 이루어집니다.
단점 :
스택 메모리를 사용하므로 큰 문자열을 다룰 때는 스택 오버플로우의 위험이 있습니다.
문자열의 크기가 컴파일 타임에 결정되므로 유연성이 떨어집니다.
결론 :
적은 양의 String 타입 문자열일 경우 사용

// // dynamic variable print method 1 <- origin code
//     char print_text[snprintf(NULL, 0, "tick Count : %d const char*\r\n", tick_check_val) + 1];
//     snprintf(print_text, sizeof(print_text), "tick Count : %d const char*\r\n", tick_check_val);
//     SERCOM1_USART_Write((uint8_t *)print_text, strlen(print_text));
*/
    va_list args;
    va_start(args, format);

    char print_text[snprintf(NULL, 0, format, args) + 1];
    va_end(args);

    va_start(args, format);
    vsnprintf(print_text, sizeof(print_text), format, args);
    va_end(args);

    SERCOM1_USART_Write((uint8_t *)print_text, strlen(print_text));
}

// 2번 방법: 동적 메모리 할당 사용 [ 힙 메모리 ]
void print_long_string(const char *format, ...) {
/*
사용법 :
print_long_string("tick Count 2: %d\r\n", 변수);

장점:
힙에 동적으로 메모리를 할당하므로 큰 문자열도 처리할 수 있습니다.
문자열의 크기를 실행 시간에 결정할 수 있어 유연성이 높습니다.
단점:
메모리 누수의 위험이 있으므로 할당한 메모리를 반드시 해제해야 합니다.
결론 :
많은 양의 String 타입 문자열일 경우 사용

// // dynamic variable print method 2 <- origin code
//     char *print_text = NULL;
//     if (asprintf(&print_text, "tick Count : %d const char*\r\n", tick_check_val) == -1) {
//         // Memory alloc ERROR Handling
//     }
//     SERCOM1_USART_Write((uint8_t *)print_text, strlen(print_text));
//     free(print_text);
*/
    va_list args;
    va_start(args, format);

    char *print_text = NULL;
    if (vasprintf(&print_text, format, args) == -1) {
        // Memory alloc ERROR Handling
        va_end(args);
        return;
    }
    va_end(args);

    SERCOM1_USART_Write((uint8_t *)print_text, strlen(print_text));
    free(print_text);
}
