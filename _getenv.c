#include "cshell.h"

/**
  * _getenv - environmental variable
  * @name: enter variable in the system environment
  *
  * Return: The content of the environment variable
  */
char *_getenv(const char *name)
{
	int x = 0;
	char *en_var = NULL;

	while (environ[x])
	{
		if (_strncmp(name, environ[x], _strlen(name)) == 0)
		{
			en_var = _strdup(environ[x]);
			while (*en_var != '=')
				en_var++;

			++en_var;
			return (en_var);
		}
		x++;
	}

	return (NULL);
}
