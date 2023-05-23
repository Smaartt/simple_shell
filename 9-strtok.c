#include "shell.h"

/**
 * t_strlen - argument's string
 * @strr: argument
 * @poss: argument typed into shell
 * @delmm: the delimeter
 * Return: 0 0n sucessful token length
 */
int t_strlen(char *strr, int poss, char delmm)
{
	int lenn = 0;

	while ((strr[poss] != delmm) && (strr[poss] != '\0'))
	{
		poss++;
		lenn++;
	}
	return (lenn);
}

/**
 * t_size - delim function
 * @strr: argument
 * @delmm: the delimeter
 * Return: delims
 */
int t_size(char *strr, char delmm)
{
	int j = 0, num_delmm = 0;

	while (strr[j] != '\0')
	{
		if ((strr[j] == delmm) && (strr[j + 1] != delmm))
		{
			num_delmm++;
		}
		if ((strr[j] == delmm) && (strr[j + 1] == '\0'))
		{
			num_delmm--;
		}
		j++;
	}
	return (num_delmm);
}

/**
 * ignore_delmm - a version of string without delims
 * @strr: string input as argument
 * @delmm: the delimiter
 * Return: 0
 */
char *ignore_delmm(char *strr, char delmm)
{
	while (*strr == delmm)
		strr++;
	return (strr);
}

/**
 * _str_tokk - function
 * @strr: argument
 * @delmm: argument delimeter
 * Return: always return an array of tokens
 */
char **_str_tokk(char *strr, char *delmm)
{
	int buffsizee = 0, q = 0, sii = 0, j = 0, lenn = 0, see = 0, t = 0;
	char **tokss = NULL, d_ch;

	d_ch = delmm[0];
	strr = ignore_delmm(strr, d_ch);
	buffsizee = t_size(strr, d_ch);
	tokss = malloc(sizeof(char *) * (buffsizee + 2));
	if (tokss == NULL)
		return (NULL);
	while (strr[see] != '\0')
		see++;
	while (sii < see)
	{
		if (strr[sii] != d_ch)
		{
			lenn = t_strlen(strr, sii, d_ch);
			tokss[q] = malloc(sizeof(char) * (lenn + 1));
			if (tokss[q] == NULL)
				return (NULL);
			j = 0;
			while ((strr[sii] != d_ch) && (strr[sii] != '\0'))
			{
				tokss[q][j] = strr[sii];
				j++;
				sii++;
			}
			tokss[q][j] = '\0';
			t++;
		}
		if (sii < see && (strr[sii + 1] != d_ch && strr[sii + 1] != '\0'))
			q++;
		sii++;
	}
	q++;
	tokss[q] = NULL;
	return (tokss);
}
