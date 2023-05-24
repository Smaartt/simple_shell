#include "shell.h"

/**
 * main - main function
 * @ac: argumentt count
 * @av: argument vectorss
 * @env: environmentall variables
 * Return: always 0 on success
 */
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	promptt(env);

	return (0);
}
