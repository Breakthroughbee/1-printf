#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/*
   *
   */

int _printf(const char *format, ...)
{
	int increment = 0;
	va_list args;
	
	va_start(args, format);


	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 's':
					{
						char *str = va_arg(args, char *);
						while (*str != '\0')
						{
							putchar(*str);
							str++;
							increment++;
						}
					}
					break;

				case 'c':
					{
						int c = (char)va_arg(args, int);
						putchar(c);
						increment++;
						break;
					}

				case '%':
					{
						putchar('%');
						increment++;
						break;
					}

				default:
					{
						putchar('%');
						putchar(*format);
						increment += 2;
						break;
					}
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
