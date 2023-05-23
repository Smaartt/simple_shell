#include "shell.h"

/**
 * _which - fleshes out command by appending it to matching PATH directory
 * @str: first command user typed into shell
 * @env: environmental variable
 * Return: a copy of fleshed out command
 */

char *_which(char *str, list_t *env)
{
	char *pthh, *cat = NULL, **toks;
	int j = 0;

	pthh = get_env("PATH", env);
	toks = c_str_tok(pthh, ":");
	free(pthh);

	j = 0;
	while (toks[j] != NULL)
	{
		if (toks[j][0] == '\0')
			cat = getcwd(cat, 0);
		else
			cat = _strdup(toks[j]);
		cat = _strcat(cat, "/");
		cat = _strcat(cat, str);
		if (access(cat, F_OK) == 0)
		{
			free_double_ptr(toks);
			return (cat);
		}
		free(cat);
		j++;
	}
	free_double_ptr(toks);
	return (str);
}
