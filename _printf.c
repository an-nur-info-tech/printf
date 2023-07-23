#include "main.h"
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	int i;
	int ch;
	char *str;
	va_list args;
	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
		}
		else
		{
			i++;
			switch (format[i])
			{
				case '%':
					{
						write(1, &format[i], 1);
						break;
					}
				case  'c':
					{
						ch = va_arg(args, int);
						/*putchar(ch);*/
						write(1, &ch, 1);
						break;
					}
				case 's':
					{
						str = va_arg(args, char*);
						while (*str != '\0')
						{
							write(1, &str[0], 1);
							/*putchar(*str);*/
							str++;
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
	va_end(args);
	return (0);
}


