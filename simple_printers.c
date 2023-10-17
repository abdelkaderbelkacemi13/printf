#include "main.h"

/**
 * print_from_to - A function to print characters from a starting
 * to a stopping point.This function iterates through the characters from
 * a starting point to a stopping point.
 * @start: A pointer to the starting character.
 * @stop: A pointer to the stopping character.
 * @except: A pointer to the exception character to be excluded from printing.
 *
 * Return: The number of characters printed within the specified range.
 */
int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	for (; start <= stop; start++)
	{
		if (start != except)
			sum += _putchar(*start);
	}
	return (sum);
}

/**
 * print_rev - A function to print a string in reverse order.
 * This function takes a string and prints its characters in reverse order,
 * effectively printing the string in reverse. It calculates the length of
 * the string and iterates through the characters to achieve the reversal.
 * @li: The va_list containing the string to be printed in reverse.
 * @params: A pointer to the structure containing printing parameters
 * Return: The number of characters printed in reverse.
 */
int print_rev(va_list li, params_t *params)
{
	int len = 0, sum = 0;
	char *str = va_arg(li, char *);
	(void)params;

	if (str)
	{
		while (*str)
		{
			len++;
			str++;
		}
		str--;
		while (len > 0)
		{
			sum += _putchar(*str);
			len--;
			str--;
		}
	}
	return (sum);
}

/**
 * print_rot13 - A function to apply the ROT13 algo and print the result str.
 * @li: The va_list containing the string to be ROT13 transformed and printed.
 * @params: A pointer to the structure containing printing parameters.
 *
 * Return: The number of characters printed after ROT13 transformation.
 */
int print_rot13(va_list li, params_t *params)
{

		int i, index;
		int count = 0;
		char arr[] =
			"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
		char *a = va_arg(li, char *);
		(void)params;

		for (i = 0; a[i]; i++)
		{
			if ((a[i] >= 'A' && a[i] <= 'Z')
					|| (a[i] >= 'a' && a[i] <= 'z'))
			{
				index = a[i] - 65;
				count += _putchar(arr[index]);
			}
			else
				count += _putchar(a[i]);
		}
		return (count);

}
