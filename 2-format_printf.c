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
	int ch, d;
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
				printf("%d", ch);
			}
			if (*format == 's')
			{
				str = va_arg(args, char *);
				printf("%s", str);
			}
			else if (*format == 'd' || 'i')
			{
				d = va_arg(args, int);
				printf("%d", d);
			}
			else if (*format == '%')
			{
				printf("%%");
			}
			else
				printf("Invalid specifier: %c", *format);
		}
		else
			putchar(*format);

		format++;
	}
	va_end(args);
	return (0);
}
