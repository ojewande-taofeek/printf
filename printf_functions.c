#include "main.h"

int put_char(va_list printf_arg);
int put_str(va_list printf_arg);
int put_mod(va_list printf_arg);
int put_digits(va_list printf_arg);
int print_hexaupper_str(int num, int *len_p);

/**
 * put_char - The function that prints characters
 * @printf_arg: The va_list
 * Return: Each character
 */

int put_char(va_list printf_arg)
{
	char c;

	c = va_arg(printf_arg, int);
	write(1, &c, 1);
	return (1);
}


/**
 * put_str - The function that prints string
 * @printf_arg: The va_list
 * Return: The string length
 */

int put_str(va_list printf_arg)
{
	char *str;
	int idx = 0, len = 0;

	str = va_arg(printf_arg, char *);
	if (str == NULL)
		str = "(null)";
	while (str[idx])
	{
		write(1, &str[idx], 1);
		len++;
		idx++;
	}
	return (len);
}

/**
 * put_mod - The function that prins percentage '%'
 * @printf_arg: The va_list
 * Return: 1
 */

int put_mod(va_list printf_arg)
{
	char m;

	UNUSED(printf_arg);
	m = '%';
	write(1, &m, 1);
	return (1);
}

/**
 * put_digits - The function that prints numbers
 * @printf_arg: The va_list
 * Return: len, length of printed number(s)
 */

int put_digits(va_list printf_arg)
{
	int div = DIV_INIT, num, len = 0;
	char p_n;
	unsigned int n;

	num = va_arg(printf_arg, int);
	if (num < 0)
	{
		p_n = '-';
		write(1, &p_n, 1);
		len++;
		n = -num;
	}
	else
		n = num;
	while ((n / div) >= DIV_CHECK)
		div *= DIV_CHECK;
	while (div > DIV_MIN)
	{
		p_n = (n / div) + '0';
		write(1, &p_n, 1);
		len++;
		n %= div;
		div /= DIV_CHECK;
	}
	return (len);
}


/**
 * print_hexaupper_str - The function that prints the upper hexa number
 *               and returns its len
 * @num: The decimal based number to be converted to upper hexa
 * @len_p: The pointer to int len of the printed upper hexadecimal
 * Return: len
 */
int print_hexaupper_str(int num, int *len_p)
{
	int n, ch1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int ch2[6] = {10, 11, 12, 13, 14, 15};
	char p_hu, letters[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
	int idx;

	if (num > 0)
	{
		print_hexaupper_str((num / 16), len_p);
	}
	n = num % 16;
	for (idx = 0; idx < 10; idx++)
	{
		if (n == ch1[idx])
		{
			p_hu = n + '0';
			write(1, &p_hu, 1);
			break;
		}
	}
	idx = 0;
	while (idx < 6)
	{
		if (n == ch2[idx])
		{
			write(1, &letters[idx], 1);
			break;
		}
		idx++;
	}
	(*len_p)++;
	return (*len_p);
}
