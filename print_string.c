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

/*
 * print_reversed - Calls a function to reverse and print a string
 * @arg: Argument passed to the function
 *
 * Return: The amount of characters printed
 */
int print_reversed(va_list arg)
{
	int len;
	char *str;
	char *ptr;

	str = va_arg(arg, char *);
	if (str == NULL)
		return (-1);
	ptr = reverse_string(str);
	if (ptr == NULL)
		return (-1);
	for (len = 0; ptr[len] != '\0'; len++)
		_putchar(ptr[len]);
	free(ptr);
	return (len);
}

/**
 * rot13 - Converts string to rot13
 * @list: string to convert
 *
 * Return: converted string
 */
int rot13(va_list list)
{
	int i;
	int x;
	char *str;
	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char u[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(list, char *);
	if (str == NULL)
		return (-1);
	for (i = 0; str[i] != '\0'; i++)
	{
		for (x = 0; x <= 52; x++)
		{
			if (str[i] == s[x])
			{
				_putchar(u[x]);
				break;
			}
			if (x == 53)
				_putchar(str[i]);
		}
	}
	return (i);
}
