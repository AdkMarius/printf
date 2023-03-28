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
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
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

