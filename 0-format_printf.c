#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/*
   *
   */

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int num;
	char c;
	char *str;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 's':
					str = va_arg(args, char *);
					while (*str != '\0')
					{
						putchar(*str);
						str++;
						num++;
					}
					break;

				case 'c':
					c = (char)va_arg(args, int);
					putchar(c);
					num++;
					break;

				case '%':
					putchar('%');
					num++;
					break;

				default:
					putchar('%');
					putchar(*format);
					num += 2;
					break;
			}
		}
		else
		{
			putchar(*format);
			num++;
		}

		format++;
	}


	va_end(args);
	return (num);
}
