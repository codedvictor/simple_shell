#include "cshell.h"

/**
  * main - Entry point to the Shell
  *
  * Return: Always zero.
  */
int main(void)
{
	char *line = NULL, **u_tok = NULL;
	int w_leng = 0, execFlag = 0;
	size_t line_size = 0;
	ssize_t line_leng = 0;

	while (line_leng >= 0)
	{
		signal(SIGINT, signal_handler);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		line_leng = getline(&line, &line_size, stdin);
		if (line_leng == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		w_leng = count_input(line);
		if (line[0] != '\n' && w_leng > 0)
		{
			u_tok = tokenize(line, " \t", w_leng);
			execFlag = execBuiltInCommands(u_tok, line);
			if (!execFlag)
			{
				u_tok[0] = find(u_tok[0]);
				if (u_tok[0] && access(u_tok[0], X_OK) == 0)
					exec(u_tok[0], u_tok);
				else
					perror("./hsh");
			}

			frees_tokens(u_tok);
		}
	}

	free(line);
	return (0);
}
