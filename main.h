#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * struct f_list_t - structure which contain the specifiers format character and functions pointers
 *
 * @type: pointer on the specifier character
 * @f: function pointer
 */
typedef struct f_list_t
{
	char *type;
	int (*f)(va_list);
} f_list;
int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list list);
int print_string(va_list list);
int print_percent(va_list list);
int print_integer(va_list list);
int check(const char *format, va_list list, f_list *check_format);
int print_binary(va_list list);
char check_hex(unsigned int num, char c);
int print_binary(va_list list);
int print_unsigned_int(va_list list);
int print_heX(va_list list);
int print_hex(va_list list);
int print_octal(va_list list);
int print_reversed(va_list arg);
int rot13(va_list list);

/*Helper functions*/
char *reverse_string(char *s);
void write_base(char *str);
unsigned int base_len(unsigned int num, int base);
char *_memcpy(char *dest, char *src, unsigned int n);

#endif
