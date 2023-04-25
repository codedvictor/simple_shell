#include "cshell.h"

/**
  * frees_get_env - entry point
  * @env_path: The environment variable to frees
  *
  * Return: Nothing to returns
  */
void frees_get_env(char *env_path)
{
	int x;

	for (x = 4; x >= 0; x--)
		env_path--;

	free(env_path);
}
