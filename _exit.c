#include "cshell.h"

/**
  * _handle_exit - exit point
  * @u_tok: character token
  * @line: code line
  *
  * Return: Nothing to returns
  */
void _handle_exit(char **u_tok, char *line)
{
	int stat = 0;

	if (u_tok[1] == NULL || (!_strcmp(u_tok[1], "0")))
	{
		frees_tokens(u_tok);
		free(line);
		exit(0);
	}
	stat = _atoi(u_tok[1]);
	if (stat != 0)
	{
		frees_tokens(u_tok);
		free(line);
		exit(stat);
	}
	else
	{
		_puts("exit: Illegal number: ");
		_puts(u_tok[1]);
		_puts("\n");
		exit(2);
	}

	frees_tokens(u_tok);
	free(line);
	exit(EXIT_SUCCESS);
}
