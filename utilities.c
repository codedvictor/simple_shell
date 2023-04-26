#include "cshell.h"

/**
  * _strcat - Concatenates two strings
  * @desty: The destination string
  * @srce: The source string
  *
  * Return: A pointer to the resulting string dest
  */
char *_strcat(char *desty, char *srce)
{
	int dln = 0, x = 0;

	while (desty[dln])
		dln++;

	for (x = 0; srce[x] != '\0'; x++)
	{
		desty[dln] = srce[x];
		dln++;
	}

	desty[dln] = '\0';
	return (desty);
}

/**
  * _strlen - Counts the length of a string
  * @c: The string to counts
  *
  * Return: The length of a string
  */
int _strlen(const char *c)
{
	int x = 0;

	while (c[x])
		x++;

	return (x);
}

/**
  * _strcmp - Compares two strings
  * @st1: The first string
  * @st2: The second string
  *
  * Return: int value
  */

int _strcmp(char *st1, char *st2)
{
	int ln_s1 = 0, ln_s2 = 0, pos = 0, dev = 0, lim = 0;

	ln_s1 = _strlen(st1);
	ln_s2 = _strlen(st2);

	if (ln_s1 <= ln_s2)
		lim = ln_s1;
	else
		lim = ln_s2;

	while (pos <= lim)
	{
		if (st1[pos] == st2[pos])
		{
			pos++;
			continue;
		}
		else
		{
			dev = st1[pos] - st2[pos];
			break;
		}

		pos++;
	}

	return (dev);
}

/**
  * _strdup - Duplicate a string
  * @stg: the string to duplicate
  *
  * Return: the string duplicated
  */
char *_strdup(char *stg)
{
	int idx = 0, ln = 1;
	char *dup_str;

	if (stg == NULL)
		return (NULL);

	ln = _strlen(stg);
	dup_str = malloc((sizeof(char) * ln) + 1);
	if (dup_str == NULL)
		return (NULL);

	while (idx < ln)
	{
		dup_str[idx] = stg[idx];
		idx++;
	}

	dup_str[idx] = '\0';
	return (dup_str);
}

/**
  * _atoi - Convert a string to an integer.
  * @c: The pointer to convert
  *
  * Return: A integer
  */
int _atoi(char *c)
{
	int min = 1, isi = 0, pos = 0;
	unsigned int ni = 0;

	while (c[pos])
	{
		if (c[pos] == '-')
			min *= -1;

		while (c[pos] >= '0' && c[pos] <= '9')
		{
			isi = 1;
			ni = (ni * 10) + (c[pos] - '0');
			pos++;
		}

		if (isi == 1)
			break;

		pos++;
	}

	ni *= min;
	return (ni);
}
