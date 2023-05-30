#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
* _printf - printf function entry point to print out according to format
* @format: an argument that printf function will recieve
* @...: ellipsis
* Return: increment the characters and integers
*/
int _printf(const char *format, ...)
{
int increment = 0, ch;
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
			char *s = va_arg(args, char *);

			while (*s != '\0')
			{
				putchar(*s);
				increment++;
				s++;
			}
		}
		else if (*format == '%')
		{
			putchar('%');
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
