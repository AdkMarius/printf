#include "main.h"

/**
 * print_octal - display a number in octal base (base 8)
 * @list: list of arguments
 *
 * Return: The number of character which displayed
 */
int print_octal(va_list list)
{
	unsigned int num;
	int len;
	char *octal_rep;
	char *rev_str;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 8);
	octal_rep = malloc(sizeof(char) * len + 1);
	if (octal_rep == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		octal_rep[len] = (num % 8) + 48;
		num = num / 8;
	}
	octal_rep[len] = '\0';
	rev_str = reverse_string(octal_rep);
	if (rev_str == NULL)
		return (-1);
	write_base(rev_str);
	free(octal_rep);
	free(rev_str);
	return (len);
}

/**
 * print_hex - display a number in base 16
 * @list: list of arguments
 *
 * Return: The number of character which displayed
 */
int print_hex(va_list list)
{
	unsigned int num, res_num;
	int len;
	char *hex_rep;
	char *rev_str;

	num = va_arg(list, unsigned int);
	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 16);
	hex_rep = malloc(sizeof(char) * len + 1);
	if (hex_rep == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		res_num = num % 16;
		if (res_num > 9)
		{
			res_num = check_hex(res_num, 'x');
			hex_rep[len] = res_num;
		}
		else
			hex_rep[len] = res_num + '0';
		num /= 16;
	}
	hex_rep[len] = '\0';
	rev_str = reverse_string(hex_rep);
	if (rev_str == NULL)
		return (-1);
	write_base(rev_str);
	free(hex_rep);
	free(rev_str);
	return (len);
}

int print_heX(va_list list)
{
	unsigned int num;
	int len;
	int rem_num;
	char *hex_rep;
	char *rev_hex;

	num = va_arg(list, unsigned int);
	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 16);
		hex_rep = malloc(sizeof(char) * len + 1);
	if (hex_rep == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = check_hex(rem_num, 'X');	
			hex_rep[len] = rem_num;												
		}
		else																
			hex_rep[len] = rem_num + '0';
		num = num / 16;
	}											
	hex_rep[len] = '\0';
	rev_hex = reverse_string(hex_rep);
	if (rev_hex == NULL)
		return (-1);
	write_base(rev_hex);
	free(hex_rep);
	free(rev_hex);
	return (len);
}

/**
 * print_binary - Converts a number from base 10 to binary
 * @list: List of arguments passed to this function
 * Return: The length of the number printed
 */
int print_binary(va_list list)
{
	unsigned int num;
	int i, len;
	char *str;
	char *rev_str;

	num = va_arg(list, unsigned int);
	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 2);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (-1);
	for (i = 0; num > 0; i++)
	{
		if (num % 2 == 0)
			str[i] = '0';
		else
			str[i] = '1';																			num = num / 2;
	}
	str[i] = '\0';
	rev_str = reverse_string(str);
	if (rev_str == NULL)
		return (-1);
	write_base(rev_str);
	free(str);
	free(rev_str);
	return (len);
}

/**
 * print_pointer - display a pointer
 * @list: list of arguments
 *
 * Return: The address
 */
int print_pointer(va_list list)
{
	void *str;
	int i;

}
/**
 * check_hex - send a character which correspond a number in base 16
 * @num: number 
 * @c: identifier the base 16 in lower case or upper case
 *
 * Return: character in base 16 that correspond num
 */
char check_hex(unsigned int num, char c)
{
	unsigned int tab[] = {10, 11, 12, 13, 14, 15};
	char *hex = "abcdef";
	char *heX = "ABCDEF";
	int i;
	char s;

	if (c == 'x')
	{
		for (i = 0; i < 6; i++)
		{
			if (tab[i] == num)
				s = hex[i];
		}
	}
	if (c == 'X')
	{
		for (i = 0; i < 6; i++)
		{
			if (tab[i] == num)
				s = heX[i];
		}
	}
	return (s);
}
