#include "cshell.h"

/**
  * tokenize - Extract tokens from string
  * @stg: The string to tokenize
  * @del: The delimiter of tokenization
  * @ln: Tokens number
  *
  * Return: An array of tokens of the string
  */
char **tokenize(char *stg, char *del, int ln)
{
	char **tokens = NULL, *token = NULL, *tmp = NULL;
	int x = 0;

	tokens = malloc(sizeof(char *) * (ln + 1));
	if (!tokens)
		return (NULL);

	stg = remove_new_line(stg);
	tmp = _strdup(stg);
	token = strtok(tmp, del);

	while (token)
	{
		tokens[x] = _strdup(token);
		token = strtok(NULL, del);
		x++;
	}

	tokens[x] = NULL;
	free(tmp);
	return (tokens);
}
