#include "main.h"
/**
 * _getline - function for get line
 * @buffer_p: address of buffer holding input
 * Return: number of bytes read
 */

ssize_t _getline(char **buffer_p)
{
	static char *buffer;
	static size_t len;
	ssize_t r;

	r = enter_buffer(&buffer, &len);
	if (r == -1)
		return (-1);
	*buffer_p = buffer;
	return (r);
}
/**
 * enter_buffer - buffer to hold string
 * @ptr_buffer: address of buffer
 * @len: length of buffer
 * Return: bytes read on success
 */
ssize_t enter_buffer(char **ptr_buffer, size_t *len)
{
	ssize_t r;
	size_t length = 0;

	if (*len == 0)
	{
		*ptr_buffer = NULL;
		signal(SIGINT, sigintHandler);
		r = my_getline(ptr_buffer, &length);
	 	if (r > 0)
		{
			if ((*ptr_buffer)[r - 1] == '\n')
			{
				(*ptr_buffer)[r - 1] = '\0';
				r--;
			}
		}
	}
	return (r);
}
/**
 * my_getline - gets input froma user
 * @ptr_buffer:pointer to buffer
 * @length:SIZE
 * Return: nytes read on success
 */
ssize_t my_getline(char **ptr_buffer, size_t *length)
{
	static char buf[BUFFER_SIZE];
	static size_t len, i;
	size_t len1;
	ssize_t r = 0, oldsize;
	char *str = NULL, *str2 = NULL, *string;

	str = *ptr_buffer;
	if (str == NULL && *length == 0)
		oldsize = 0;
	if (i == len)
		i = len = 0;
	r = read(STDIN_FILENO, buf, BUFFER_SIZE);
	if (r >= 0)
		len = r;
	if (r == -1 || (r == 0 && len == 0))
		return (-1);
	str2 = strchr(buf + i, '\n');
	if (str2  != NULL)
		len1 = (unsigned int)(str2 - buf) + 1;
	else
		len1 = len;
	string = _realloc(str, oldsize, oldsize ? oldsize + len1 : len1 + 1);
	if (string == NULL)
	{
		if (str != NULL)
			free(str);
		return (-1);
	}
	if (oldsize != 0)
		strncat(string, buf + i, len1 - i);
	else
		strncpy(string, buf + i, len1 - i + 1);
	oldsize = oldsize + (len1 - i);
	i = len1;
	str = string;
	if (length != 0)
		*length = oldsize;
	*ptr_buffer = str;
	return (oldsize);
}
/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(-1);
}
