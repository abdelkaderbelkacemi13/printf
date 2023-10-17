#include "main.h"

/**
 * print_hex - A function to format and print an unsigned
 * integer in hexadecimal. This function takes an unsigned integer,
 * formats it as a hexadecimal string, and prints
 * it according to the provided parameters.
 * @li: The va_list containing the argument to be printed.
 * @params: A pointer to the structure containing printing parameters.
 *
 * Return: The number of characters printed.
 */
int print_hex(va_list li, params_t *params)
{
	unsigned long lo;
	int i = 0;
	char *chr;

	if (params->l_modifier)
		lo = (unsigned long)va_arg(li, unsigned long);
	else if (params->h_modifier)
		lo = (unsigned short int)va_arg(li, unsigned int);
	else
		lo = (unsigned int)va_arg(li, unsigned int);

	chr = convert(lo, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && lo)
	{
		*--chr = 'x';
		*--chr = '0';
	}
	params->unsign = 1;
	return (i += print_number(chr, params));
}

/**
 * print_HEX - A function to format and print an unsigned
 * integer in uppercase hexadecimal.This function takes an unsigned integer,
 * formats it as an uppercase hexadecimal string,
 * and prints it according to the provided parameters.
 * @li: The va_list containing the argument to be printed.
 * @params: A pointer to the structure containing printing parameters.
 *
 * Return: The number of characters printed.
 */
int print_HEX(va_list li, params_t *params)
{
	unsigned long lo;
	int c = 0;
	char *chr;

	if (params->l_modifier)
		lo = (unsigned long)va_arg(li, unsigned long);
	else if (params->h_modifier)
		lo = (unsigned short int)va_arg(li, unsigned int);
	else
		lo = (unsigned int)va_arg(li, unsigned int);
	chr = convert(lo, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && lo)
	{
		*--chr = 'X';
		*--chr = '0';
	}
	params->unsign = 1;
	return (c += print_number(chr, params));
}
/**
 * print_binary - A function to format and print an
 * unsigned integer in binary.
 * This function takes an unsigned integer, formats it as a binary string,
 * and prints it according to the provided parameters.
 * @li: The va_list containing the argument to be printed.
 * @params: A pointer to the structure containing printing parameters.
 *
 * Return: The number of characters printed.
 */
int print_binary(va_list li, params_t *params)
{
	unsigned int n = va_arg(li, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);
	int c = 0;

	if (params->hashtag_flag && n)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * print_octal - A function to format and print an unsigned integer in octal.
 * This function takes an unsigned integer, formats it as an octal string,
 * and prints it according to the provided parameters.
 * @li: The va_list containing the argument to be printed.
 * @params: A pointer to the structure containing printing parameters.
 *
 * Return: The number of characters printed.
 */
int print_octal(va_list li, params_t *params)
{
	unsigned long value;
	char *str;
	int chars_printed = 0;

	if (params->l_modifier)
		value = (unsigned long)va_arg(li, unsigned long);
	else if (params->h_modifier)
		value = (unsigned short int)va_arg(li, unsigned int);
	else
		value = (unsigned int)va_arg(li, unsigned int);
	str = convert(value, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && value)
		*--str = '0';
	params->unsign = 1;
	chars_printed = print_number(str, params);

	return (chars_printed);
}
