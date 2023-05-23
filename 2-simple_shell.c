#include "shell.h"

/**
 * c_exit - free user's typed command and linked list before exiting
 * @str: user's command typed
 * @env: input linked list of envirnment
 */

void c_exit(char **str, list_t *env)
{
	free_double_ptr(str);
	free_linked_list(env);
	_exit(0);
}

/**
 * _execve - executes command user typed in shell
 * @s: command user
 * @env: environmental variable
 * @num: nth user command; used in error message
 * Return: 0
 */

int _execve(char **s, list_t *env, int num)
{
	char *holder;
	int status = 0, t = 0;
	pid_t pid;

	if (access(s[0], F_OK) == 0)
	{
		holder = s[0];
		t = 1;
	}
	else
		holder = _which(s[0], env);

	if (access(holder, X_OK) != 0)
	{
		not_found(s[0], num, env);
		free_double_ptr(s);
		return (127);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(holder, s, NULL) == -1)
			{
				not_found(s[0], num, env);
				c_exit(s, env);
			}
		}
		else
		{
			wait(&status);
			free_double_ptr(s);
			if (t == 0)
				free(holder);
		}
	}
	return (0);
}
