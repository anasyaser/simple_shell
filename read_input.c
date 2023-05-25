#include "header.h"


/**
 * read_input - hundle user input
 *
 * @is_interactive: interactive mode
 * Return: string of user input
 */

char *read_input(int is_interactive)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t inp = -1;

	if (is_interactive)
		printf("$ ");

	inp = getline(&input, &len, stdin);

	if (feof(stdin) && inp == -1)
	{
		free(input);
		exit(EXIT_SUCCESS);
	}
	if (inp == -1)
	{
		perror("reading line error");
		free(input);
		exit(EXIT_FAILURE);
	}

	input[inp - 1] = '\0';

	return (input);
}
