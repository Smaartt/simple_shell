#include "shell.h"

/**
 * c_t_size - function that returns number of delim
 * @strr: argument command
 * @delmm: delim argument
 * Return: 0 (no of tokens)
 */
int c_t_size(char *strr, char delmm)
{
	int j = 0, num_delmm = 0;

	while (strr[j] != '\0')
	{
		if (strr[j] == delmm)
		{
			num_delmm++;
		}
		j++;
	}
	return (num_delmm);
}


/**
 * c_str_tok - function that tokenizes a string
 * @strr: argument to shell
 * @delmm: the delimeter
 * Return: returns array of tokens
 */
char **c_str_tok(char *strr, char *delmm)
{
	int buffsizee = 0, q = 0, sii = 0, j = 0, lenn = 0, see = 0;
	char **tokss = NULL, d_ch;

	d_ch = delmm[0];
	buffsizee = c_t_size(strr, d_ch);
	tokss = malloc(sizeof(char *) * (buffsizee + 2));
	if (tokss == NULL)
		return (NULL);
	while (strr[see] != '\0')
		see++;
	while (sii < see)
	{
		lenn = t_strlen(strr, sii, d_ch);
		tokss[q] = malloc(sizeof(char) * (lenn + 1));
		if (tokss[q] == NULL)
			return (NULL);
		j = 0;
		while ((strr[sii] != d_ch) &&
		       (strr[sii] != '\0'))
		{
			tokss[q][j] = strr[sii];
			j++;
			sii++;
		}
		tokss[q][j] = '\0';
		q++;
		sii++;
	}
	tokss[q] = NULL;
	return (tokss);
}
