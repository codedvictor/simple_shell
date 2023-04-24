#include "cshell.h"

/**
  * count_input - words counts by the user
  * @stg: words string
  *
  * Return: The number of words found in the string
  */
int count_input(char *stg)
{
	int x = 0, cr = 0, stt = 0;

	while (stg[x])
	{
		if (stg[x] == ' ' || stg[x] == '\n' || stg[x] == '\t')
			stt = 0;
		else if (stt == 0)
		{
			stt = 1;
			cr++;
		}

		x++;
	}

	return (cr);
}
