#include "main.h"

int put_binary(va_list printf_arg);
int print_bin(int num, int *len);

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
	if (num >= 0)
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
int print_bin(int num, int *len_p)
{
	int n;
	char p_b;

	if (num > 1)
	{
		print_bin((num / 2), len_p);
	}
	if (num >= 0)
	{
		n = num % 2;
		p_b = n + '0';
		write(1, &p_b, 1);
		(*len_p)++;
	}
	return (*len_p);
}
