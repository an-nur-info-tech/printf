#ifndef PRINTF_H
#define PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>

#define BUFF_SIZE 1024

int _printf(const char *format, ...);

#endif

