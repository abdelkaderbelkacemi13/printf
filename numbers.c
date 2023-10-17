#include "main.h"

/**
 * convert - A function to convert an integer to a string
 * representation in the specified base.This function takes a long integer
 * and converts it to a string representation in the specified base.
 *
 * @num: The long integer to be converted.
 * @base: The base for the conversion.
 * @flags: Flags to determine the conversion behavior.
 * @params: A pointer to the structure containing printing parameters.
 *
 * Return: A pointer to a static buffer containing the converted string representation.
 */

char *convert(long int num, int base, int flags, params_t *params)
{
	static char *conversion_array;
	static char result_buffer[50];
	char sign = 0;
	char *result_ptr;
	unsigned long n = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}

	conversion_array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	result_ptr = &result_buffer[49];
	*result_ptr = '\0';

	do
	{
		*--result_ptr = conversion_array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--result_ptr = sign;

	return result_ptr;

}


/**
 * print_unsigned - A function to format and print an unsigned integer.
 * This function takes an unsigned integer, formats it as a string, and prints it
 * according to the provided parameters.
 * @li: The va_list containing the argument to be printed.
 * @params: A pointer to the structure containing printing parameters.
 *
 * Return: The number of characters printed.
 */
int print_unsigned(va_list li, params_t *params)
{
	unsigned long lo;

	if (params->l_modifier)
		lo = (unsigned long)va_arg(li, unsigned long);
	else if (params->h_modifier)
		lo = (unsigned short int)va_arg(li, unsigned int);
	else
		lo = (unsigned int)va_arg(li, unsigned int);
	params->unsign = 1;
	return (print_number(convert(lo, 10, CONVERT_UNSIGNED, params), params));
}


/**
 * print_address - A function to format and print a memory address.
 * This function takes a memory address, formats it as a hexadecimal string,
 * and prints it according to the provided parameters.
 * @li: The va_list containing the address to be printed.
 * @params: A pointer to the structure containing printing parameters.
 *
 * Return: The number of characters printed.
 */

int print_address(va_list li, params_t *params)
{
unsigned long int n = va_arg(li, unsigned long int);
char *str;

	if (!n)
		return (_puts("(nil)"));

	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}
