#include "shell.h"

/**
 * _realloc - allocates memory and set all values to 0
 * @ptr: pointer to the previously allocated memory(malloc(old_size))
 * @old_sizee: size previously allocated
 * @new_sizee: new size to reallocate
 * Return: pointer to reallocated memory
 */

void *_realloc(void *ptr, unsigned int old_sizee, unsigned int new_sizee)
{
	void *q;
	unsigned int j;

	if (new_sizee == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_sizee == old_sizee)
		return (ptr);

	if (ptr == NULL)
	{
		q = malloc(new_sizee);
		if (q == NULL)
			return (NULL);
		else
			return (q);
	}

	q = malloc(new_sizee);
	if (q == NULL)
		return (NULL);

	for (j = 0; j < old_sizee && j < new_sizee; j++)
		*((char *)q + j) = *((char *)ptr + j);
	free(ptr);

	return (q);
}
