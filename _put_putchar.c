#include "main.h"

/**
 * _puts - A function used to print a string with a newline character.
 * This function takes a pointer to a string (`str`) and prints each character
 * of the string, followed by a newline. It calculates and returns
 * the length of the string printed.
 * @str: A pointer to the string to be printed.
 * Return: The length of the string printed .
 */
int _puts(char *str)
{
	char *a = str;

	for (; *str; str++)
		_putchar(*str);
	return (str - a);
}

/**
 * _putchar - A function used to write a character to the standard output.
 * This function writes a single character to the standard output, storing
 * it in an internal buffer until it is flushed or the buffer is full.
 * @ch: The character to be written to the standard output.
 *
 * Return: On successful write, returns 1. Otherwise, returns -1.
 */
int _putchar(int ch)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (ch == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (ch != BUF_FLUSH)
		buf[i++] = ch;
	return (1);
}
