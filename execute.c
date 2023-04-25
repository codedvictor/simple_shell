#include "cshell.h"

/**
  * find - Verify if a command is found in the system
  * @cname: The command name to find in the system
  *
  * Return: The path name of the command found or NULL if failed
  */
char *find(char *cname)
{
	char *env_path = NULL, **p_tok = NULL;
	int x = 0, num_del = 0;
	struct stat sb;

	if (cname)
	{
		if (stat(cname, &sb) != 0 && cname[0] != '/')
		{
			env_path = _getenv("PATH");
			num_del = count_delims(env_path, ":") + 1;
			p_tok = tokenize(env_path, ":", num_del);

			while (p_tok[x])
			{
				p_tok[x] = concat_path(p_tok[x], cname);

				if (stat(p_tok[x], &sb) == 0)
				{
					free(cname);
					cname = _strdup(p_tok[x]);
					frees_get_env(env_path);
					frees_tokens(p_tok);
					return (cname);
				}

				x++;
			}

			frees_get_env(env_path);
			frees_tokens(p_tok);
		}

		if (stat(cname, &sb) == 0)
			return (cname);
	}

	free(cname);
	return (NULL);
}

/**
  * exec - Executes a command
  * @cname: The command to execute
  * @opts: The options or flags to the command
  *
  * Return: A integer status value
  */
int exec(char *cname, char **opts)
{
	pid_t child;
	int stts;

	switch (child = fork())
	{
		case -1:
			perror("fork failed");
			return (-1);
		case 0:
			execve(cname, opts, environ);
			break;
		default:
			do {
				waitpid(child, &stts, WUNTRACED);
			} while (WIFEXITED(stts) == 0 && WIFSIGNALED(stts) == 0);
	}

	return (0);
}
