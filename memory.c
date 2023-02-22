#include "main.h"

/**
 * smart_alloc - allocate space if there is any, and add memory
 * to list of space to free
 *
 * @size: size of space to allocate
 *
 * Return: pointer to space in memory
 */
void *smart_alloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		_puts("We used up all the memory!!! Holy shit\n");
		exit(20);
	}
	return (ptr);
}

/**
 * free_array - frees a pointer array of strings
 *
 * @array: 2d array
 *
 * Return: void
 */
void free_array(char **array)
{
	free(array[0]);
	free(array);
}
/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
