#include "main.h"

/**
 * print_char - display a character
 * @list: list of arguments
 *
 * Return: The number of char whicg displayed
 */
int print_char(va_list list)
{
	char c;

	c = va_arg(list, int);
	_putchar(c);
	return (1);
}

/**
 * print_string - display a string
 * @list: list of arguments
 *
 * Return: The number of character which displayed
 */
int print_string(va_list list)
{
	char *str;
	int i;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
		_putchar(str[i]);
	return (i);

}

/**
 * print_percent - display the percent character
 * @list: list of arguments
 *
 * Return: 1
 */
int print_percent(__attribute__((unused))va_list list)
{
	_putchar('%');
	return (1);
}

