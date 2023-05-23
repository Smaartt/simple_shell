#include "shell.h"

/**
 * _strcmp - compare two strings
 * @s2: string 2
 * @s3: string 3
 * Return: int that tells num spaces in between, 0 if exactly the same string
 */

int _strcmp(char *s2, char *s3)
{
	int j = 0;

	while (*(s2 + j) == *(s3 + j) && *(s2 + j))
		j++;

	if (*(s3 + j))
		return (*(s2 + j) - *(s3 + j));
	else
		return (0);
}
