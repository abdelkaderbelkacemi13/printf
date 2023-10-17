#include "main.h"
/**
 * print_char - A function to print a single character.
 * This function takes a single character, pads it according to the
 *  specified width.
 * @li: The va_list containing the character to be printed.
 * @params: A pointer to the structure containing printing parameters.
 *
 * Return: The number of characters printed.
 */
int print_char(va_list li, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(li, int);

	if (params->minus_flag)
		sum += _putchar(ch);
	for (pad = 1; pad < params->width; pad++)
		sum += _putchar(pad_char);
	if (!params->minus_flag)
		sum += _putchar(ch);
	return (sum);
}
/**
 * print_int - A function to format and print an integer.
 * This function takes an integer, formats it as a string,
 * and prints it according to the provided parameters.
 * @li: The va_list containing the integer to be printed.
 * @params: A pointer to the structure containing printing parameters.
 *
 * Return: The number of characters printed.
 */
int print_int(va_list li, params_t *params)
{
	long lo;

	if (params->l_modifier)
		lo = va_arg(li, long);
	else if (params->h_modifier)
		lo = (short int)va_arg(li, int);
	else
		lo = (int)va_arg(li, int);
	return (print_number(convert(lo, 10, 0, params), params));
}

/**
 * print_string - A function to format and print a string.
 *
 * This function takes a string, formats it based on the specified width
 * and precision, and prints it. It supports left or right alignment based on
 * the 'minus_flag' in the printing parameters.
 * @li: The va_list containing the string to be printed.
 * @params: A pointer to the structure containing printing parameters.
 *
 * Return: The number of characters printed.
 */
int print_string(va_list li, params_t *params)
{
	char *chr = va_arg(li, char *);
	char pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;
	(void)params;

	if (!chr)
		chr = NULL_STRING;
	j = pad = _strlen(chr);

	if (params->precision < pad)
		j = pad = params->precision;
	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
		{
			while (i < pad)
			{
				sum += _putchar(*chr++);
				i++;
			}
		}
		else
			sum += _puts(chr);
	}
	while (j++ < params->width)
		sum += _putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
		{
			for (i = 0; i < pad; i++)
				sum += _putchar(*chr++);
		}
		else
			sum += _puts(chr);
	}
	return (sum);
}
/**
 * print_percent - A function to print the percentage symbol (%).
 * @li: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list li, params_t *params)
{
	(void)li;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - A function to format and print a string,
 * handling non-printable characters.This function takes a string, formats it,
 * and prints it.
 * @li: The va_list containing the string to be printed.
 * @params: A pointer to the structure containing printing parameters.
 *
 * Return: The number of characters printed.
 */
int print_S(va_list li, params_t *params)
{
	char *str = va_arg(li, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}
