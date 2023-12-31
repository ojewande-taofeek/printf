#include "main.h"

int put_hexalower(va_list printf_arg);
int print_hexalower(unsigned int num, int *len);
int put_hexaupper(va_list printf_arg);
int print_hexaupper(unsigned int num, int *len);
int put_Str(va_list printf_arg);
int print_hexaupper_str(int num, int *len_p);

/**
 * put_hexalower - The function that hexadecimal lower
 * @printf_arg: The va_list
 * Return: Len of the printed value
 */

int put_hexalower(va_list printf_arg)
{
	unsigned int num;
	int len = 0;

	num = va_arg(printf_arg, unsigned int);
	if (num)
	{
		return (print_hexalower(num, &len));
	}
	return (0);
}

/**
 * print_hexalower - The function that prints the lower hexa number
 *               and returns its len
 * @num: The decimal based number to be converted to lower hexa
 * @len_p: The pointer to int len of the printed lower hexadecimal
 * Return: len
 */
int print_hexalower(unsigned int num, int *len_p)
{
	unsigned int n, ch1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	unsigned int ch2[6] = {10, 11, 12, 13, 14, 15};
	char p_hu, letters[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int idx;

	if (num > 15)
	{
		print_hexalower((num / 16), len_p);
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


/**
 * put_hexaupper - The function that hexadecimal upper
 * @printf_arg: The va_list
 * Return: Len of the printed value
 */

int put_hexaupper(va_list printf_arg)
{
	unsigned int num;
	int len = 0;

	num = va_arg(printf_arg, unsigned int);
	if (num)
	{
		return (print_hexaupper(num, &len));
	}
	return (0);
}

/**
 * print_hexaupper - The function that prints the upper hexa number
 *               and returns its len
 * @num: The decimal based number to be converted to upper hexa
 * @len_p: The pointer to int len of the printed upper hexadecimal
 * Return: len
 */
int print_hexaupper(unsigned int num, int *len_p)
{
	unsigned int n, ch1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	unsigned int ch2[6] = {10, 11, 12, 13, 14, 15};
	char p_hu, letters[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
	int idx;

	if (num > 15)
	{
		print_hexaupper((num / 16), len_p);
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


/**
 * put_Str - The function that print special characters
 * @printf_arg: The va_list
 * Return: len;
 */
int put_Str(va_list printf_arg)
{
	char *str, x[2] = {'\\', 'x'};
	int idx = 0, j, ch, len = 0, len_hu, len_idx;

	str = va_arg(printf_arg, char *);

	if (str == NULL)
		str = "(null)";
	while (str[idx] != '\0')
	{
		if ((str[idx] < 32 && str[idx] > 0) || str[idx] >= 127)
		{
			ch = str[idx];
			for (j = 0; j < 2; j++, len++)
				write(1, &x[j], 1);
			len_idx = 0;
			len_hu = print_hexaupper_str(ch, &len_idx);
			len += len_hu;
		}
		else
		{
			write(1, &str[idx], 1);
			len++;
		}
		idx++;
	}
	return (len);
}

