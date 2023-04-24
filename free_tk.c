#include "cshell.h"

/**
  * frees_tokens - entry to free space
  * @tok: free memory space
  *
  * Return: success
  */
void frees_tokens(char **tok)
{
	char **tmp = tok;

	if (tok)
	{
		while (*tok)
			free(*tok++);

		free(tmp);
	}
}
