#include "main.h"

/**
 * print_integer - display the number
 * @list: the number which will be display
 *
 * Return: The number of arguments printed
 */
int print_integer(va_list list)
{
	int absolute, count, div, n;
	
	div = 1;
	count = 0;
	n = va_arg(list, int);
	if (n < 0)
	{
		count += _putchar('-');
		absolute = n * -1;
	}
	else
		absolute = n;
	for (; absolute / div > 9; )
		div *= 10;
	for (; div != 0; )
	{
		count += _putchar((absolute / div) + '0');
		absolute %= div;
		div /= 10;
	}
	return (count);
}

/**
 * print_unsigned_int - display the positive number
 * @list: number
 *
 * Return: The number of arguments printed
 */
int print_unsigned_int(va_list list)
{
	unsigned int count, n, div;

	div = 1;
	count = 0;
	n = va_arg(list, unsigned int);
	for (; n / div > 9; )
		div *= 10;
	for (; div != 0; )
	{
		count += _putchar((n / div) + '0');
		n %= div;
		div /= 10;
	}
	return (count);
}
