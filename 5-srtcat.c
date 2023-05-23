#include "shell.h"

/**
 * _strcat - function to concatenate two strings
 * @destt: appended to string
 * @srcc: appended string
 * Return: string on sucess
 */
char *_strcat(char *destt, char *srcc)
{
	int lenn = 0;
	int lenn2 = 0;
	int total_lenn = 0;
	int k = 0;

	while (destt[lenn] != '\0')
	{
		lenn++;
		total_lenn++;
	}
	while (srcc[lenn2] != '\0')
	{
		lenn2++;
		total_lenn++;
	}

	destt = _realloc(destt, lenn, sizeof(char) * total_lenn + 1);

	while (srcc[k] != '\0')
	{
		destt[lenn] = srcc[k];
		lenn++;
		k++;
	}
	destt[lenn] = '\0';

	return (destt);
}
