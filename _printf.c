#include "main.h"
/**
 * _printf - A function that formats and prints a given string based on
 * the specified format.This function takes a format string
 * and optional parameters, similar to the standard printf function,
 * and processes the format string to print the formatted output.
 *
 * @format: A pointer to a format string that specifies
 *  the format of the output.
 * @...: Optional parameters to be formatted and
 * printed based on the format string.
 *
 * Return: The number of bytes printed
 */
int _printf(const char *format, ...)
{
	int lasum = 0;
	va_list li;
	char *po, *begin;
	params_t params = PARAMS_INIT;

	va_start(li, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	po = (char *)format;
	while (*po)
	{
		init_params(&params, li);
		if (*po != '%')
		{
			lasum += _putchar(*po);
			po++;
			continue;
		}
		begin = po;
		po++;
		for (; get_flag(po, &params); po++)
			;
		po = get_width(po, &params, li);
		po = get_precision(po, &params, li);
		if (get_modifier(po, &params))
			po++;
		if (!get_specifier(po))
			lasum += print_from_to(begin, po,
					params.l_modifier || params.h_modifier ? po - 1 : 0);
		else
			lasum += get_print_func(po, li, &params);
		po++;
	}
	_putchar(BUF_FLUSH);
	va_end(li);
	return (lasum);
}
