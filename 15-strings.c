#include "shell.h"

/**
 * numlen - function counts number of 0
 * @nb: argument
 * Return: always returns count of digits
 */
int numlen(int nb)
{
	int countt = 0;
	int numm = nb;

	while (numm > 9 || numm < -9)
	{
		numm /= 10;
		countt++;
	}
	return (countt);
}
/**
 * int_to_string - function to turn an int into a string
 * @numm: int argument
 * Return: alwyas return the int as a string, NULL if unsucessful
 */

char *int_to_string(int numm)
{
	int digitss, tenss, j = 0, u = 0, y;
	char *ress;

	digitss = numm;
	tenss = 1;

	if (numm < 0)
		u = 1;
	ress = malloc(sizeof(char) * (numlen(digitss) + 2 + u));
	if (ress == NULL)
		return (NULL);
	if (numm < 0)
	{
		ress[j] = '-';
		j++;
	}
	for (y = 0; digitss > 9 || digitss < -9; y++)
	{
		digitss /= 10;
		tenss *= 10;
	}
	for (digitss = numm; y >= 0; y--)
	{
		if (digitss < 0)
		{
			ress[j] = (digitss / tenss) * -1 + '0';
			j++;
		}
		else
		{
			ress[j] = (digitss / tenss) + '0';
			j++;
		}
		digitss %= tenss;
		tenss /= 10;
	}
	ress[j] = '\0';
	return (ress);
}
