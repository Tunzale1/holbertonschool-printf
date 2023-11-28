#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - function that produces output
 * Return: the number of characters printed
 * @format: character string
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, c;
	char *str;

	va_start(args, format);
	if (format == NULL || (strlen(format) == 1 && format[0] == '%'))
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					c = va_arg(args, int);
					write(1, &c, 1);
					count++;
					break;
				case 's':
					str = va_arg(args, char*);
					if (str == NULL)
						str = "(null)";
					count += write(1, str, strlen(str));
					break;
				case '%':
					write(1, "%", 1);
					count++;
					break;
				default:
					write(1, "%", 1);
					write(1, &format[i], 1);
					count += 2; } }
		else
		{
			write(1, &format[i], 1);
			count++; }
		i++; }
	va_end(args);
	return (count); }
