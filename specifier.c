#include "main.h"

/**
 * get_specifier - A function to retrieve the appropriate
 * print function based on the specifier.
 * This function retrieves the appropriate print function
 * based on the specifier found in the format string.
 * @s: The format string containing the specifier.
 *
 * Return: A pointer to the appropriate print function for
 * the specified data type, or NULL if not found.
 */
int (*get_specifier(char *s))(va_list li, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i;

	for (i = 0; specifiers[i].specifier; i++)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
	}
	return (NULL);
}
/**
 * get_print_func - A function to retrieve and call the appropriate
 * print function based on the specifier.
 * This function retrieves the appropriate print function based on the
 *  specifier found in the format string.
 * @s: The format string containing the specifier.
 * @li: The va_list containing the variable arguments.
 * @params: A pointer to the structure containing printing parameters.
 *
 * Return: The return value from the appropriate print function,
 * or 0 if no valid function is found.
 */
int get_print_func(char *s, va_list li, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(li, params));
	return (0);
}
/**
 * get_flag - A function to parse and retrieve flags from a format string.
 * This function parses the format string to retrieve various formatting flags,
 * including '+', ' ', '#', '-', and '0'.
 * @s: The format string containing the flag character to be retrieved.
 * @params: A pointer to the structure containing printing parameters.
 *
 * Return: A flag indicating the presence of the specified flag character.
 */
int get_flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}
/**
 * get_modifier - A function to parse and retrieve the length
 *  modifier from a format string.This function parses the format
 * string to retrieve the length modifier used in formatting.
 * @s: The format string containing the length modifier.
 * @params: A pointer to the structure containing printing parameters
 *
 * Return: A flag indicating the presence of a modifier
 */
int get_modifier(char *s, params_t *params)
{
	int i = 0;

	if (*s == 'h')
	{
		i = params->h_modifier = 1;
	}
	else if (*s == 'l')
	{
		i = params->l_modifier = 1;
	}
	return (i);
}

/**
 * get_width - A function to parse and retrieve the width
 *  parameter from a format string.This function parses the format
 *   string to retrieve the width parameter used in
 * formatting. It updates the width value in the
 * printing parameters structure and returns the updated string pointer.
 * @s: The format string containing the width specifier.
 * @params: A pointer to the structure containing printing parameters
 * @li: The va_list used to retrieve the width .
 *
 * Return: A pointer to the updated string after parsing the width specifier.
 */

char  *get_width(char *s, params_t *params, va_list li)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(li, int);
		s++;
	}
	else
	{
		do {
			if (_isdigit(*s))
				d = d * 10 + (*s - '0');
			else
				break;
			s++;
		} while (1);
	}
	params->width = d;
	return (s);
}
