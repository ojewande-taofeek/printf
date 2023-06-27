#include "main.h"

/**
 * _printf - The fucntion that prints various inputs of different formats
 * @format: The string supplied to be printed
 * Return: len, if successful
 */

int _printf(const char *format, ...)
{
	int idx, len = 0;
	char check;
	va_list printf_arg;

	if (format == NULL)
		return (-1);

	va_start(printf_arg, format);
	for (idx = 0; format[idx] && (format[idx] != '\0'); idx++)
	{
		if (format[idx] == '%')
		{
			idx++;
			check = format[idx];
			if (check == 'c' || check == 's' || check == '%'
					|| check == 'd' || check == 'i')
				len += f_caller(check)(printf_arg);
		}
		else
		{
			write(1, &format[idx], 1);
			len++;
		}
	}
	va_end(printf_arg);
	return (len);
}
