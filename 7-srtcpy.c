#include "shell.h"

/**
 * _strcpy - copies string
 * @destt: copy source to this buffer
 * @srcc: copies to buffer
 * Return: destt
 */

char *_strcpy(char *destt, char *srcc)
{
	int j, lenn;

	for (lenn = 0; srcc[lenn] != '\0'; lenn++)
		;

	for (j = 0; j <= lenn; j++)
		destt[j] = srcc[j];

	return (destt);
}
