#include "main.h"

/**
 * _isdigit - A function to check if a character is a digit (0-9).
 * This function determines if a given character represents a digit (0-9).
 * @c: The character to be checked.
 *
 * Return: 1 if the character is a digit (0-9), 0 otherwise.
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/**
 * _strlen - A function to calculate the length of a string.
 * This function calculates the length of a given string by iterating through
 * the characters of the string until the null terminator is encountered.
 * @s: A pointer to the string whose length is to be calculated.
 *
 * Return: The length of the string excluding the null terminator.
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}

/**
 * print_number - A function to print a formatted numeric string.
 * This function takes a formatted numeric string and prints it according
 * to the provided parameters.
 * @str: The formatted numeric string to be printed.
 * @params: A pointer to the structure containing printing parameters.
 *
 * Return: The number of characters printed.
 */

int print_number(char *str, params_t *params)
{
	unsigned int i = _strlen(str);
	int neg = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '-';
	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - A function to print a formatted numeric string
 * with right alignment.This function takes a formatted numeric string
 * and prints it with right alignment according to the provided parameters.
 * @str: The formatted numeric string to be printed with right alignment.
 * @params: A pointer to the structure containing printing parameters.
 *
 * Return: The number of characters printed with right alignment.
 */

int print_number_right_shift(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');

	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;
	if ((params->plus_flag && !neg2) ||
			(!params->plus_flag && params->space_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == '0' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
			!params->unsign && params->zero_flag)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
			!params->unsign && !params->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_left_shift - A function to print a formatted numeric string
 * with left alignment.This function takes a formatted numeric string and
 * prints it with left alignment according to the provided parameters.
 * @str: The formatted numeric string to be printed with left alignment.
 * @params: A pointer to the structure containing printing parameters.
 *
 * Return: The number of characters printed with left alignment.
 */

int print_number_left_shift(char *str, params_t *params)
{
	unsigned int n = 0, i = _strlen(str);
	char pad_char = ' ';

	switch (params->zero_flag + (params->minus_flag << 1))
	{
		case 1:
			pad_char = '0';
			break;
		default:
			break;
	}
	if ((!params->unsign && *str == '-') && i < params->width &&
			pad_char == '0' && !params->minus_flag)
		str++;
	else
		params->unsign = 0;
	switch ((params->plus_flag << 1) + params->space_flag)
	{
		case 1:
			n += _putchar('+');
			i++;
			break;
		case 2:
			n += _putchar(' ');
			i++;
			break;
		default:
			break;
	}
	n += _puts(str);
	while (i++ < params->width)
		n += _putchar(pad_char);
	return (n);
}
