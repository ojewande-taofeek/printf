#include "main.h"

int _strlen(char *s);
int put_reversed_str(va_list printf_arg);
int put_rot13(va_list printf_arg);

/**
 * _strlen - The function that returns the length of a string constant
 * @s: The string constant
 * Return: Length
 */

int _strlen(char *s)
{
	int idx = 0, len = 0;

	while (s[idx])
	{
		len++;
		idx++;
	}
	return (len);
}

/**
 * put_reversed_str - The function that reverses string
 * @printf_arg: The va_list
 * Return: len of the string
 */

int put_reversed_str(va_list printf_arg)
{
	int idx, len;
	char *str;

	str = va_arg(printf_arg, char *);
	if (str == NULL)
		str = "(null)";
	for (len = 0; str[len]; len++)
		;
	len--;
	for (idx = 0; len >= 0; len--, idx++)
	{
		write(1, &str[len], 1);
	}
	return (idx);
}


/**
 * put_rot13 - The function rotates an alphabet by 13
 * @printf_arg: The va_list
 * Return: The len of the string constant
 */

int put_rot13(va_list printf_arg)
{
	char *str, p_am, p_nz;
	int idx, len = 0;

	str = va_arg(printf_arg, char *);
	if (str == NULL)
		str = "(null)";
	for (idx = 0; str[idx]; idx++, len++)
	{
		if ((str[idx] >= 'A' && str[idx] <= 'M') ||
				(str[idx] >= 'a' && str[idx] <= 'm'))
		{
			p_am = (str[idx] + 13);
			write(1, &p_am, 1);
		}
		else if ((str[idx] >= 'N' && str[idx] <= 'Z') ||
				(str[idx] >= 'n' && str[idx] <= 'z'))
		{
			p_nz = (str[idx] - 13);
			write(1, &p_nz, 1);
		}
		else
			write(1, &str[idx], 1);
	}
	return (len);
}
