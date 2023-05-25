#include "header.h"

/**
 * get_args - convert text to array
 *
 * @command: string to convert to array
 * Return: array of pointers to strings
 */

char **get_args(char *command)
{
	int buffer_size = 5;
	int position = 0;
	char **tokens;
	char *token;

	if (!command)
		return (NULL);

	tokens = malloc(buffer_size * sizeof(char *));
	if (!tokens)
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(command, " ");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= buffer_size)
		{
			buffer_size += buffer_size;
			tokens = realloc(tokens, buffer_size * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "Allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, " ");
	}
	tokens[position] = NULL;
	return (tokens);
}
