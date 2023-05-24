#include "shell.h"

/**
 * find_envv - function find given environmental variable in linked list
 * @env: argument
 * @str: argument/variable name
 * Return: alwys returns node in linked list
 */
int find_envv(list_t *env, char *str)
{
	int i = 0, indexx = 0;

	while (env != NULL)
	{
		i = 0;
		while ((env->var)[i] == str[i])
			i++;
		if (str[i] == '\0')
			break;
		env = env->next;
		indexx++;
	}
	if (env == NULL)
		return (-1);
	return (indexx);
}

/**
 * _unsetenvv - function that removes
 * @env: linked list argument
 * @str: string argument
 * Return: returns 0 on success
 */
int _unsetenvv(list_t **env, char **str)
{
	int indexx = 0, i = 0;

	if (str[1] == NULL)
	{
		write(STDOUT_FILENO, "Too few arguments\n", 18);
		free_double_ptr(str);
		return (-1);
	}
	indexx = find_envv(*env, str[1]);
	free_double_ptr(str);
	if (indexx == -1)
	{
		write(STDOUT_FILENO, "Cannot find\n", 12);
		return (-1);
	}
	i = delete_nodeint_at_index(env, indexx);
	if (i == -1)
	{
		write(STDOUT_FILENO, "Cannot find\n", 12);
		return (-1);
	}
	return (0);
}

/**
 * _setenvv - function creates or modify existing environment variables
 * @env: environment linked list
 * @str: argument typed in command
 * Return: alwys return 0 on success, 1 on fail
 */
int _setenvv(list_t **env, char **str)
{
	int indexx = 0, i = 0;
	char *catt;
	list_t *holder;

	if (str[1] == NULL || str[2] == NULL)
	{
		write(STDOUT_FILENO, "Too few arguments\n", 18);
		free_double_ptr(str);
		return (-1);
	}
	catt = _strdup(str[1]);
	catt = _strcat(catt, "=");
	catt = _strcat(catt, str[2]);
	indexx = find_envv(*env, str[1]);
	if (indexx == -1)
	{
		add_end_node(env, catt);
	}
	else
	{
		holder = *env;
		while (i < indexx)
		{
			holder = holder->next;
			i++;
		}
		free(holder->var);
		holder->var = _strdup(catt);
	}
	free(catt);
	free_double_ptr(str);
	return (0);
}
