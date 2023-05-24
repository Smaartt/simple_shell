#include "shell.h"

/**
 * not_foundd - function write error
 * @str: argument user's typed command
 * @c_n: argument typed command
 * @env: arg environmental variables linked list to write shell name
 */
void not_foundd(char *str, int c_n, list_t *env)
{
	int countt = 0;
	char *shelll, *numm;

	shelll = get_env("_", env);
	while (shelll[countt] != '\0')
		countt++;
	write(STDOUT_FILENO, shelll, countt);
	free(shelll);
	write(STDOUT_FILENO, ": ", 2);
	numm = int_to_string(c_n);
	countt = 0;
	while (numm[countt] != '\0')
		countt++;
	write(STDOUT_FILENO, numm, countt);
	free(numm);
	write(STDOUT_FILENO, ": ", 2);
	countt = 0;
	while (str[countt] != '\0')
		countt++;
	write(STDOUT_FILENO, str, countt);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not found\n", 10);
}

/**
 * cant_cd_too - function writes error
 * @str: the argument after the cmd cd
 * @c_n: the argument user's typed command
 * @env: the environmental variables
 */
void cant_cd_too(char *str, int c_n, list_t *env)
{
	int countt = 0;
	char *shelll, *numm;

	shelll = get_env("_", env);
	while (shelll[countt] != '\0')
		countt++;
	write(STDOUT_FILENO, shelll, countt);
	free(shelll);
	write(STDOUT_FILENO, ": ", 2);
	numm = int_to_string(c_n);
	countt = 0;
	while (numm[countt] != '\0')
		countt++;
	write(STDOUT_FILENO, numm, countt);
	free(numm);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "cd: can't cd to ", 16);
	countt = 0;
	while (str[countt] != '\0')
		countt++;
	write(STDOUT_FILENO, str, countt);
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * illegal_numberr - function write error
 * @str: argument user's typed argument after the cmd exit
 * @c_n: argument user's typed command
 * @env: arg  environmental variables linked list to write shell name
 */
void illegal_numberr(char *str, int c_n, list_t *env)
{
	int countt = 0;
	char *shelll = NULL, *numm = NULL;

	shelll = get_env("_", env);
	while (shelll[countt] != '\0')
		countt++;
	write(STDOUT_FILENO, shelll, countt);
	free(shelll);
	write(STDOUT_FILENO, ": ", 2);
	numm = int_to_string(c_n);
	countt = 0;
	while (numm[countt] != '\0')
		countt++;
	write(STDOUT_FILENO, numm, countt);
	free(numm);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "exit: Illegal number: ", 22);
	countt = 0;
	while (str[countt] != '\0')
		countt++;
	write(STDOUT_FILENO, str, countt);
	write(STDOUT_FILENO, "\n", 1);
}
