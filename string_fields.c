#include "main.h"

/**
 * get_precision - A function to parse and retrieve the precision
 * from a format string. This function parses the format string
 * to retrieve the precision used in formatting,
 * indicated by a '.' followed by a numeric value or an asterisk.
 * @p: The format string containing the precision specifier.
 * @params: A pointer to the structure containing printing parameters.
 * @li: The va_list used to retrieve the precision.
 *
 * Return: A pointer to the updated string after
 * parsing the precision specifier.
 */
char *get_precision(char *p, params_t *params, va_list li)
{
	int d = 0;

	switch (*p)
	{
		case '.':
			p++;
			if (*p == '*')
			{
				d = va_arg(li, int);
				p++;
			}
			else
			{
				do {
					if (_isdigit(*p))
						d = d * 10 + (*p - '0');
					else
						break;
					p++;
				} while (1);
			}
			params->precision = d;
			break;
		default:
			break;
	}
	return (p);
}
