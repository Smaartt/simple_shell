#include "shell.h"

/**
 * c_strdup - custom string duplication; exclude beginning bytes
 * @str: string to duplicate
 * @cs: number of bytes to exclude
 * Return: string
 */

char *c_strdup(char *str, int cs)
{
	char *duplicate_str;
	int j, len = 0;

	if (str == NULL)
		return (NULL);

	while (*(str + len))
		len++;
	len++;

	duplicate_str = malloc(sizeof(char) * (len - cs));
	if (duplicate_str == NULL)
		return (NULL);

	j = 0;
	while (j < (len - cs))
	{
		*(duplicate_str + j) = *(str + cs + j);
		j++;
	}
	return (duplicate_str);
}

/**
 * get_env - find and returns a copy of requested environmental variable
 * @str: string to store it in
 * @env: entire set of environmental variable
 * Return: copy of requested environmental variable
 */

char *get_env(char *str, list_t *env)
{
	int k = 0, cs = 0;

	while (env != NULL)
	{
		k = 0;
		while ((env->var)[k] == str[k])
			k++;
		if (str[k] == '\0' && (env->var)[k] == '=')
			break;
		env = env->next;
	}

	while (str[cs] != '\0')
		cs++;
	cs++;
	return (c_strdup(env->var, cs));
}
