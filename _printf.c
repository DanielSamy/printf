#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 *_printf - prints according to format
 *
 *@format: string
 *
 *Return: the printed char.
 *
 */
int _printf(const char *format, ...)
{
	int Ch_NUM = 0;
	char c;
	char *rr;
	int x;
	va_list ToT;

	if (format == NULL)
		return (-1);/**Error*/
	va_start(ToT, format);
	while (*format != '\0')
	{
		if (*format != '%')/**if there is no %*/
		{
			putchar(*format);/**just print the characters*/
			Ch_NUM++;
		}
		else if (*format == '%')/**if there is %*/
		{
			format++;/** go to the next element & compare*/
			if (*format == 's')/**it is s(string)*/
			{
				rr = va_arg(ToT, char *);
				for (x = 0; rr[x] != '\0'; x++)
					putchar(rr[x]);/**replace s with the given string*/
				Ch_NUM++;
			}
			else if (*format == 'c')/**if it is c(character)*/
			{
				c = va_arg(ToT, int);
				putchar(c);/**replace it with the given char*/
				Ch_NUM++;
			}
			else if (*format == '%')/**if there is 2 %*/
				putchar('%');/**print one %*/
		}
		format++;/**repeat all this for the second char*/
	}
	va_end(ToT);
	return (Ch_NUM);/**return the no. of printed character*/
}
