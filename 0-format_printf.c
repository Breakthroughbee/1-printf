#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
* _print - printf function entry point to print out according to format
*
* @format: an argument that printf function will recieve
*
* @...: elipsis
*
* Returnii: increment the characters and integers
*/
int _printf(const char *format, ...)

int increment = 0, c;
va_list args;
char *str;

va_start(args, format);

while (*format)
{
	if (*format == '%')
	{
		format++;

	if (*format == 'c')
	{
		c = va_arg(args, int);
		putchar(c);
		increment++;
	}
	else if (*format == 's')
	{
		*str = va_arg(args, char *);

		while (*str)
		{
			putchar(*str);
			increment++;
			str++;
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
		(*format);
		increment++;
	}
	format++;
}
va _end(args);
return increment;
}

