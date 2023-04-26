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
	int status = 0;

	if (u_tok[1] == NULL)
	{
		free(line);
		frees_tokens(u_tok);
		exit(0);
	}
	if (!_strcmp(u_tok[1], "0"))
	{
		free(line);
		frees_tokens(u_tok);
		exit(0);
	}
	status = _atoi(u_tok[1]);
	if (status != 0)
	{
		free(line);
		frees_tokens(u_tok);
		exit(status);
	}
	else
	{
		_puts("exit: Illegal number: ");
		_puts(u_tok[1]);
		_puts("\n");
		free(line);
		frees_tokens(u_tok);
		exit(1);
	}
}

