#include "main.h"

int put_binary(va_list printf_arg);
int print_bin(unsigned int num, int *len);
int put_octal(va_list printf_arg);
int print_octal(unsigned int num, int *len);
int print_hexaupper_str(int num, int *len_p);


/**
 * put_binary - The function that prints binary
 * @printf_arg: The va_list
 * Return: Len of the binary
 */

int put_binary(va_list printf_arg)
{
	unsigned int num;
	int len = 0;

	num = va_arg(printf_arg, unsigned int);
	if (num)
	{
		return (print_bin(num, &len));
	}
	return (0);
}

/**
 * print_bin - The function that prints the binary number and returns its len
 * @num: The decimal based number to be converted to binary
 * @len_p: The pointer to int len of the printed binary
 * Return: len
 */
int print_bin(unsigned int num, int *len_p)
{
	unsigned int n;
	char p_b;

	if (num > 1)
	{
		print_bin((num / 2), len_p);
	}
	n = num % 2;
	p_b = n + '0';
	write(1, &p_b, 1);
	(*len_p)++;
	return (*len_p);
}


/**
 * put_unsigned - Function that prints unsigned values
 * @printf_arg: The va_list
 * Return: The len of the printed value
 */
int put_unsigned(va_list printf_arg)
{
	int div = DIV_INIT, len = 0;
	char p_n;
	unsigned int n;

	n = va_arg(printf_arg, unsigned int);
	if (n)
	{
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
	return (-1);
}

/**
 * put_octal - The function that octal binary
 * @printf_arg: The va_list
 * Return: Len of the printed value
 */

int put_octal(va_list printf_arg)
{
	unsigned int num;
	int len = 0;

	num = va_arg(printf_arg, unsigned int);
	if (num)
	{
		return (print_octal(num, &len));
	}
	return (0);
}

/**
 * print_octal - The function that prints the octal number and returns its len
 * @num: The decimal based number to be converted to octal
 * @len_p: The pointer to int len of the printed binary
 * Return: len
 */
int print_octal(unsigned int num, int *len_p)
{
	unsigned int n;
	char p_o;

	if (num > 7)
	{
		print_octal((num / 8), len_p);
	}
	n = num % 8;
	p_o = n + '0';
	write(1, &p_o, 1);
	(*len_p)++;
	return (*len_p);
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
