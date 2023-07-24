#include "main.h"
int _integer(va_list list);
void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */


int _printf(const char *format, ...)
{
	int i, printed_chars = 0, printed = 0, buff_ind = 0;
	char buffer[BUFF_SIZE];
	int ch;
	char *str;
	va_list args;

	if (format == NULL)
		return (-1);

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
			print_buffer(buffer, &buff_ind);
			i++;
			switch (format[i])
			{
				case '\0':
					{
						return (-1);
					}
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
				case 'd':
				case 'i':
					{
						/*num = va_arg(args, int);*/
						printed = _integer(args);
						if (printed == -1)
							return (-1);
						printed_chars += printed;
						break;
					}
				default:
					{
						buffer[buff_ind++] = format[--i];
						if (buff_ind == BUFF_SIZE)
							print_buffer(buffer, &buff_ind);
						printed_chars++;
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
 * _integer - prints integer
 * @list: va_list variable
 * Return: prints given number of integers
 */

int _integer(va_list list)
{
long int num1 = va_arg(list, int), num2;
	int div = 1, i = 0;

	if (num1 < 0)
	{
		putchar('-');
		i++;
		num1 *= -1;
	}
	num2 = num1;
	while (num2 > 9)
	{
		div *= 10;
		num2 = num2 / 10;
	}
	while (div >= 1)
	{
		num2 = num1 % div;
		num1 /= div;
		putchar(num1 + '0');
		num1 = num2;
		div /= 10;
		i++;
	}
	return (i);
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
