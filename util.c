#include "cshell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
  * _puts - Prints a string
  * @stg: The string to print
  *
  * Return: Nothing to returns
  */
void _puts(char *stg)
{
	while (*stg)
	{
		_putchar(*stg);
		stg++;
	}

	_putchar('\n');
}

/**
  * _strncmp - Compares at most the first n bytes of str1 and str2
  * @st1: The first string
  * @st2: The second string
  * @ln: The limit bytes of comparison
  *
  * Return: int value
  */
int _strncmp(const char *st1, const char *st2, size_t ln)
{
	unsigned int pos = 0;
	int dev = 0;

	while (pos < ln)
	{
		if (st1[pos] == st2[pos])
		{
			pos++;
			continue;
		}
		else
		{
			dev = st1[pos] - st2[pos];
			break;
		}

		pos++;
	}

	return (dev);
}
