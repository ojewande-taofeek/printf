#include "main.h"

/**
 * f_caller- The function pointer that calls the required function
 * @check: The parameter to points to the format specifier
 * Return: The specified function, if successful
 *         NULL, if otherwise
 */

int (*f_caller(char check))(va_list)
{
	f_call call[] = {
		{'c', put_char},
		{'s', put_str},
		{'%', put_mod},
		{'d', put_digits},
		{'i', put_digits},
		{'b', put_binary},
		{'u', put_unsigned},
		{'o', put_octal},
		{'x', put_hexalower},
		{'X', put_hexaupper},
		{'S', put_Str},
		{'r', put_reversed_str},
		{'R', put_rot13},
		{'\0', NULL}
	};
	int idx = 0;

	while (call[idx].specifier != '\0')
	{
		if (check == call[idx].specifier)
			return (call[idx].fxn);
	idx++;
	}
	return (NULL);
}
