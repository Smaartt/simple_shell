#include "shell.h"

/**
 * free_double_ptr - function frees malloced arrays
 * @strr: argument array
 */
void free_double_ptr(char **strr)
{
	int j = 0;

	while (strr[j] != NULL)
	{
		free(strr[j]);
		j++;
	}
	free(strr);
}
