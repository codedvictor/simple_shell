#include "cshell.h"

/**
  * remove_new_line - Removes a new line character from string
  * @stg: The string
  *
  * Return: The string without a new line character
  */
char *remove_new_line(char *stg)
{
	int x = 0;

	while (stg[x])
	{
		if (stg[x] == '\n')
			stg[x] = '\0';
		x++;
	}

	return (stg);
}
