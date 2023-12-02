#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 *print_char - a function that prints char
 *@args: number of arguments
 */

void print_char(va_list args)
{
	int c = va_arg(args, int);

	write(1, &c, 1);
}

/**
 *print_string - a function that prints string
 *@args: number of rgumnts
 *Return: string
 */
int print_string(va_list args)
{
	char *str;

	str = va_arg(args, char*);
	if (str == NULL)
	{
		return (write(1, "(null)", strlen("(null)")));
	}
	else
	{
		return (write(1, str, strlen(str)));
	}
}


/**
 * print_int - function that prints numbers
 * @args: list of arguments
 * Return: inetegers
 */
int print_int(va_list args)
{
	int num = va_arg(args, int);
	int count = 0;
	char buffer[12];

	count = snprintf(buffer, sizeof(buffer), "%d", num);
	write(1, buffer, count);
	return (count);
}

/**
 * print_binary - function that prints numbers in binary
 * @args: list of arguments
 * Return: number of characters printed
 */
int print_binary(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    char buffer[32];

    int i;
    for (i = 31; i >= 0; i--)
    {
        buffer[i] = (num & 1) + '0';
        num >>= 1;
    }
    write(1, buffer, 32);

    return 32;
}
/**
 * _printf - function that produces output
 * Return: the number of characters printed
 * @format: character string
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

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
				case 'd':
				case 'i':
					count += print_int(args);
					break;
				case 'c':
					print_char(args);
					count++;
					break;
				case 's':
					count += print_string(args);
					break;
				case 'b':
					count += print_binary(args);
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
