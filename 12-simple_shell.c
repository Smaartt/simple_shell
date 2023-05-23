#include "shell.h"

/**
 * env_linked_list - createing linked list from environmental variable
 * @env: environmental variable
 * Return: linked list
 */

list_t *env_linked_list(char **env)
{
	list_t *head;
	int j = 0;

	head = NULL;
	while (env[j] != NULL)
	{
		add_end_node(&head, env[j]);
		j++;
	}
	return (head);
}

/**
 * _env - printing environmental variable
 * @str: user's command into shell
 * @env: environmental variable
 * Return: 0
 */

int _env(char **str, list_t *env)
{
	free_double_ptr(str);
	print_list(env);
	return (0);
}
