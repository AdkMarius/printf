#include "main.h"

/**
 * _printf - same function than printf
 * @format: first input
 * @...: optional input
 *
 * Return: int
 */
int _printf(const char *format, ...)
{
	f_list check_format[] = {
		{"d", print_integer},
		{"i", print_integer},
		{"u", print_unsigned_int},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_heX},
		{"b", print_binary},
		{"c", print_char},
		{"s", print_string},
		{"p", print_pointer},
		{"r", print_reversed},
		{"R", rot13},
		{"%", print_percent},
		{NULL, NULL}
	};
	va_list list;
	int count = 0;

	if (format == NULL)
		return (-1);
	va_start(list, format);
	count = check(format, list, check_format);
	va_end(list);
	return (count);
}
