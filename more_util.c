#include "cshell.h"

/**
  * _realloc - Resize the ptr that was previously allocated
  * @pntr: The pointer previously allocated
  * @o_size: The old size of the pointer
  * @n_size: The new size of the new pointer
  *
  * Return: A new pointer to the memory block allocated with the new size
  */
void *_realloc(void *pntr, unsigned int o_size, unsigned int n_size)
{
	char *nptr;
	unsigned int x;

	if (n_size == o_size)
		return (pntr);

	if (pntr == NULL)
	{
		nptr = malloc(n_size);

		if (nptr == NULL)
			return (NULL);

		return (nptr);
	}
	else
	{
		if (n_size == 0)
		{
			free(pntr);
			return (NULL);
		}
	}

	nptr = malloc(n_size);

	if (nptr == NULL)
		return (NULL);

	for (x = 0; x < o_size && x < n_size; x++)
	{
		nptr[x] = ((char *) pntr)[x];
	}

	free(pntr);
	return (nptr);
}
