#ifndef PRINTF_H
#define PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>

#define BUFF_SIZE 1024

int _printf(const char *format, ...);
int print_char(char buffer[], int ch);
void print_buffer(char buffer[], int *buff_ind);

#endif

