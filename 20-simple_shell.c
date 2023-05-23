#include "shell.h"

/**
 * ctrl_c - ignores Ctrl-C input and prints prompt
 * @n: take int from signal
 */

void ctrl_c(int n)
{
	(void)n;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * built_in - handles builtins (exit, env, cd)
 * @token: user's typed command
 * @env: environmental variable
 * @num: take in nth user command typed to write error message
 * @command: bring in command to free
 * Return: 1 if acted on builtin, 0 if not
 */

int built_in(char **token, list_t *env, int num, char **command)
{
	int j = 0;

	if (_strcmp(token[0], "exit") == 0)
	{
		j = __exit(token, env, num, command);
	}

	else if (_strcmp(token[0], "env") == 0)
	{
		_env(token, env);
		j = 1;
	}

	else if (_strcmp(token[0], "cd") == 0)
	{
		j = _cd(token, env, num);
	}

	else if (_strcmp(token[0], "setenv") == 0)
	{
		_setenv(&env, token);
		j = 1;
	}

	else if (_strcmp(token[0], "unsetenv") == 0)
	{
		_unsetenv(&env, token);
		j = 1;
	}
	return (j);
}

/**
 * ignore_space - return string without spaces
 * @str: string
 * Return: new string
 */

char *ignore_space(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

/**
 * ctrl_D - exits program if Ctrl-D is pressed
 * @i: characters read by get_line
 * @command: user's typed in command
 * @env: environmental variable linked list
 */

void ctrl_D(int i, char *command, list_t *env)
{
	if (j == 0)
	{
		free(command);
		free_linked_list(env);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
}

/**
 * prompt - repeatedly prompts user and executes user cmds if applicable
 * @en: envrionmental variable
 * Return: 0
 */

int prompt(char **en)
{
	list_t *env;
	size_t j = 0, n = 0;
	int command_line_no = 0, exit_stat = 0;
	char *command, *n_command, **token;

	env = env_linked_list(en);
	do {
		command_line_no++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		else
			non_interactive(env);
		signal(SIGINT, ctrl_c);
		command = NULL; j = 0;
		j = get_line(&command);
		ctrl_D(j, command, env);
		n_command = command;
		command = ignore_space(command);
		n = 0;
		while (command[n] != '\n')
			n++;
		command[n] = '\0';
		if (command[0] == '\0')
		{
			free(n_command); continue;
		}
		token = NULL; token = _str_tok(command, " ");
		if (n_command != NULL)
			free(n_command);
		exit_stat = built_in(token, env, command_line_no, NULL);
		if (exit_stat)
			continue;
		exit_stat = _execve(token, env, command_line_no);
	} while (1);
	return (exit_stat);
}
