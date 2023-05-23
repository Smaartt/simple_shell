#include "shell.h"

/**
 * c_atom - custom atom converts string to int
 * @t: string
 * Return: number if success, -1 if string contains non-numbers
 */

int c_atom(char *t)
{
	int j = 0;
	unsigned int num = 0;

	while (t[j] != '\0')
	{
		if (t[j] >= '0' && t[j] <= '9')
			num = num * 10 + (t[j] - '0');
		if (t[j] > '9' || t[j] < '0')
			return (-1);
		j++;
	}
	return (num);
}

/**
 * __exit - free user's input and exits main program with value
 * @str: user's command into shell
 * @env: brings environmental variable to free at error
 * @num: brings nth user command line input to print in error message
 * @command: bring in command to free
 * Return: 0 if success 2 if fail
 */

int __exit(char **str, list_t *env, int num, char **command)
{
	int e_value = 0;

	if (str[1] != NULL)
		e_value = c_atom(str[1]);

	if (e_value == -1)
	{
		illegal_number(str[1], num, env);
		free_double_ptr(str);
		return (2);
	}
	free_double_ptr(str);
	free_linked_list(env);
	if (command != NULL)
		free_double_ptr(command);
	exit(e_value);
}
