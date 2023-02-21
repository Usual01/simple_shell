#include "main.h"

/**
 * _puts - prints a string
 * @ch: pointer to the string
 */
void _puts(char *ch)
{
	int i = 0;

	while (*(ch + i) != '\0')
	{
		_putchar(*(ch + i));
		i++;
	}
}

/**
 * _putchar - prints the character
 *
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
