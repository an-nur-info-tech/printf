#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */


int _printf(const char *format, ...)
{
	int i, printed_chars = 0, buff_ind = 0;
	char buffer[BUFF_SIZE];
	int ch;
	char *str;
	va_list args;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_ind);
			}
			printed_chars++;
		}
		else
		{
			i++;
			switch (format[i])
			{
				case '%':
					{
						buffer[buff_ind++] = format[i];
						if (buff_ind == BUFF_SIZE)
						{
							print_buffer(buffer, &buff_ind);
						}
						printed_chars++;
						break;
					}
				case  'c':
					{
						ch = va_arg(args, int);
						buffer[buff_ind++] = ch;
						if (buff_ind == BUFF_SIZE)
						{
							print_buffer(buffer, &buff_ind);
						}
						printed_chars++;
						break;
					}
				case 's':
					{
						str = va_arg(args, char*);
						if (str == NULL)
						{
							str = "(null)";
						}
						while (*str != '\0')
						{
							buffer[buff_ind++] = *str;
							if (buff_ind == BUFF_SIZE)
							{
								print_buffer(buffer, &buff_ind);
							}
							str++;
							printed_chars++;
						}
						break;
					}
				default:
					{
					break;
					}
			}
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(args);
	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
