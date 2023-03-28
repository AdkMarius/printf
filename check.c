#include "main.h"

/**
 * check - check the character which is in format
 * @format: A list which contain all constant character
 * @list: A list which contain all possible character
 * @check_t: A list which contain all possible specifiers format character
 *
 * Return: A total character which is in format
 */
int check(const char *format, va_list list, f_list check_t[])
{
	int i, j, count_char, return_value; 
	
	count_char = 0;
	for (i = 0; format[i]; i++) /*Iterate on the list of constant character*/
	{
		if (format[i] == '%') /*Check that the character is %, for checking that tha after character is a specifier character format*/
		{
			for (j = 0; check_t[j].type != NULL; j++) /*Iterate on the list which contain all the specifiers format character*/
			{
				if (format[i + 1] == check_t[j].type[0])
				{
					return_value = check_t[j].f(list);
					if (return_value == -1)
						return (-1);
					count_char += return_value;
					break;
				}
			}
			if (check_t[j].type == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					count_char += 2;
				}
				else
				{
					return (-1);
				}
			}
			i++;
		}
		else
		{
			_putchar(format[i]);
			count_char++;
		}
	}
	return (count_char);
}
