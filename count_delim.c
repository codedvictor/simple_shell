#include "cshell.h"

/**
  * count_delims - Counts delimiters in a string
  * @stg: The string that contains the delimiters
  * @del: The delimiters to will find in the string
  *
  * Return: The number of delimiters in the string
  */
int count_delims(char *stg, char *del)
{
	int x = 0, y = 0, cd = 0;

	while (del[x])
	{
		y = 0;
		while (stg[y])
		{
			if (stg[y] == del[x])
				cd++;
			y++;
		}
		x++;
	}

	return (cd);
}
