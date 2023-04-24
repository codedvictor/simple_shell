#include "cshell.h"

/**
 * execBuiltInCommands - Built-in command Execution
 * @u_tok: command listing
 * @line: command line
 *
 * Return: 1 if is a built-in command or 0 if not
 */
int execBuiltInCommands(char **u_tok, char *line)
{
	int x = 0;
	char *ListBuiltinCmds[] = { "exit", "cd", "help", "env", NULL };

	while (ListBuiltinCmds[x])
	{
		if (_strcmp(u_tok[0], ListBuiltinCmds[x]) == 0)
		{
			switch (x)
			{
				case 0:
					_handle_exit(u_tok, line);
				case 1:
					chdir(u_tok[1]);
					return (1);
				case 2:
					_open_help();
					return (1);
				case 3:
					_print_env();
					return (1);
				default:
					break;
			}
		}
		x++;
	}

	return (0);
}
