#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
  * _printf - function that prints accroding to format
  * @format: argument received
  * @...: ellipsis
  * Return: incrememnt the character and integer
  */
int _printf(const char *format, ...)
{
	int ch, increment = 0;
	char *str;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				ch = va_arg(args, int);
				putchar(ch);
				increment++;
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				while (*str != '\0')
				{
					putchar(*str);
					str++;
					increment++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				putchar(*format);
				increment++;
			}
		}
		else
		{
			putchar(*format);
			increment++;
		}
		format++;
	}
	va_end(args);
	return (increment);
}
