#include "shell.h"

/**
 * get_linee - stores buffer  of the user's command
 * @strr: buffer
 * Return: characters
 */
size_t get_linee(char **strr)
{
	ssize_t j = 0, size = 0, t = 0, t2 = 0, n = 0;
	char buff[1024];

	/* read while there's stdin greater than buffsize; -1 to add a '\0' */
	while (t2 == 0 && (j = read(STDIN_FILENO, buff, 1024 - 1)))
	{
		if (j == -1) /* check if read errored */
			return (-1);

		buff[j] = '\0'; /* terminate buff with \0 to use with _strcat */

		n = 0; /* last loop if \n is found in the stdin read */
		while (buff[n] != '\0')
		{
			if (buff[n] == '\n')
				t2 = 1;
			n++;
		}

		/* copy what's read to buff into get_line's buffer */
		if (t == 0) /* malloc the first time */
		{
			j++;
			*strr = malloc(sizeof(char) * j);
			*strr = _strcpy(*strr, buff);
			size = j;
			t = 1;
		}
		else /* _realloc via _strcat with each loop */
		{
			size += j;
			*strr = _strcat(*strr, buff);
		}
	}
	return (size);
}
