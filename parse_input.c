#include "header.h"

/**
 * get_args - convert text to array
 *
 * @user_input: string to conver to array
 * Return: array of pointers to strings
 */

char **get_args(char *command)
{
	int buffer_size = 10;
	int position = 0;
	char **tokens = malloc(buffer_size * sizeof(char*));
	char *token;

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
			tokens = realloc(tokens, buffer_size * sizeof(char*));
			if (!tokens)
			{
				fprintf(stderr, "Allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, " ");
	}
	tokens[position] = NULL;
	return tokens;
}
