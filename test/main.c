#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{

     char *str = NULL, k = 'T';
     _printf("Let's try to printf a simple sentence.\n");
     printf("Let's try to printf a simple sentence.\n");
    _printf("Length:[%%, %s, %c]\n", str, k);
    printf("Length:[%%, %s, %c]\n", str, k);
 /*   void *addr; */
    int len;
    int len2, len3, len4, len5, len8;
    unsigned int len6, len7;
    int num = 23, bina = 98;
    char *str2 = "Hello";
     unsigned int ui;
     int uii;
	ui = (unsigned int)INT_MAX + 1024;
	uii = -2;
/*addr = (void *)0x7ffe637541f0; */
    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    len3 = _printf("%d", num);
    _printf("%i\n", len3);
    len4= _printf("%s", str2);
    _printf("%d\n", len4);
   len4= printf("%s", str2);
    printf("%d\n", len4);
    len5 = _printf("%b", bina);
   _printf("%d\n", len5);
   len6 = _printf("Unsigned:[%u]\n", ui);
    _printf("%d\n", len6);
len6 = printf("Unsigned:[%u]\n", ui);
printf("%d\n", len6);
_printf("Unsigned:[%u]\n", uii);
    printf("Unsigned:[%u]\n", uii);
_printf("Unsigned octal:[%o]\n", ui);
printf("Unsigned octal:[%o]\n", ui);
len7 =_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
_printf("%d\n", len7);
    len7 = printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
printf("%d\n", len7);
len8 = _printf("%S\n", "Best\nSchool");
_printf("%d\n", len8);
/**
 * _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr); */
len7 = _printf("%R", str2);
_printf("%d\n", len7);


    return (0);
}
