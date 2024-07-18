#include "definitions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


// 1�� ���: �ڵ� ���� ��� [ ���� ]
void print_short_string(const char *format, ...) {
/*
���� :
print_short_string("tick Count 1: %d\r\n", ����);

���� :
���ÿ� �ڵ� ������ �Ҵ�ǹǷ� �޸� �Ҵ�� ������ �ڵ����� �̷�����ϴ�.
���� :
���� �޸𸮸� ����ϹǷ� ū ���ڿ��� �ٷ� ���� ���� �����÷ο��� ������ �ֽ��ϴ�.
���ڿ��� ũ�Ⱑ ������ Ÿ�ӿ� �����ǹǷ� �������� �������ϴ�.
��� :
���� ���� String Ÿ�� ���ڿ��� ��� ���

// // dynamic variable print method 1 <- origin code
//     char print_text[snprintf(NULL, 0, "tick Count : %d const char*\r\n", tick_check_val) + 1];
//     snprintf(print_text, sizeof(print_text), "tick Count : %d const char*\r\n", tick_check_val);
//     SERCOM0_USART_Write((uint8_t *)print_text, strlen(print_text));
*/
    va_list args;
    va_start(args, format);

    char print_text[snprintf(NULL, 0, format, args) + 1];
    va_end(args);

    va_start(args, format);
    vsnprintf(print_text, sizeof(print_text), format, args);
    va_end(args);

    SERCOM0_USART_Write((uint8_t *)print_text, strlen(print_text));
}

// 2�� ���: ���� �޸� �Ҵ� ��� [ �� �޸� ]
void print_long_string(const char *format, ...) {
/*
���� :
print_long_string("tick Count 2: %d\r\n", ����);

����:
���� �������� �޸𸮸� �Ҵ��ϹǷ� ū ���ڿ��� ó���� �� �ֽ��ϴ�.
���ڿ��� ũ�⸦ ���� �ð��� ������ �� �־� �������� �����ϴ�.
����:
�޸� ������ ������ �����Ƿ� �Ҵ��� �޸𸮸� �ݵ�� �����ؾ� �մϴ�.
��� :
���� ���� String Ÿ�� ���ڿ��� ��� ���

// // dynamic variable print method 2 <- origin code
//     char *print_text = NULL;
//     if (asprintf(&print_text, "tick Count : %d const char*\r\n", tick_check_val) == -1) {
//         // Memory alloc ERROR Handling
//     }
//     SERCOM0_USART_Write((uint8_t *)print_text, strlen(print_text));
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

    SERCOM0_USART_Write((uint8_t *)print_text, strlen(print_text));
    free(print_text);
}