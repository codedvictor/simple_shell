#include "cshell.h"

/**
  * _print_env - Prints environment built-in
  *
  * Return: Success
  */
void _print_env(void)
{
	int x = 0, y = 0;

	while (environ[x])
	{
		y = 0;

		while (environ[x][y])
		{
			_putchar(environ[x][y]);
			y++;
		}

		if (y != 0)
			_putchar('\n');
		x++;
	}
}
