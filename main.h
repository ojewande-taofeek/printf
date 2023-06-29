
#ifndef MAIN_H
#define MAIN_H

/* HEADER FILES */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/* STRUCTURE FOR FUNCTION CALL*/

/**
 * struct function_call - The structure to check for format specifier and
 *                        call respective function
 * @specifier: The format specifier character
 * @fxn: The function pointer to the function
 */

typedef struct function_call
{
	char specifier;
	int (*fxn)(va_list);
} f_call;

/* FUNCTIONS PROTOTYPES */

int _printf(const char *format, ...);
int put_char(va_list printf_arg);
int put_str(va_list printf_arg);
int put_mod(va_list printf_arg);
int put_digits(va_list printf_arg);
int put_binary(va_list printf_arg);
int print_bin(unsigned int, int *);
int put_unsigned(va_list printf_arg);
int put_octal(va_list printf_arg);
int print_octal(unsigned int, int *);
int put_hexalower(va_list printf_arg);
int print_hexalower(unsigned int num, int *len);
int put_hexaupper(va_list printf_arg);
int print_hexaupper(unsigned int num, int *len);


int (*f_caller(char check))(va_list);

/* SYMBOLIC CONSTANTS */
#define UNUSED(x) (void)(x)
#define DIV_INIT (1)
#define DIV_CHECK (10)
#define DIV_MIN (0)



#endif /* MAIN_H */
