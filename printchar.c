#include "main.h"
#include <stdarg.h>
/**
 * print_char - Prints a char
 * @buffer: List a of arguments
 * @ch: Character to print
 * Return: Number of chars printed
 */
int print_char(char buffer[], int ch)
{
    int buff_ind = 0;
    buffer[buff_ind] = ch;
    if (buff_ind == BUFF_SIZE)
    {
	    print_buffer(buffer, &buff_ind);
    }
    return (ch);
}
