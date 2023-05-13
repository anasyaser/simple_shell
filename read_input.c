#include "header.h"

/**
 * read_input - hundle user input
 *
 * Return: string of user input
 */

char *read_input()
{
	char *input;
	size_t len = 0;
	ssize_t inp;

	while (1)
	{
		printf("$ ");

		inp = getline(&input, &len, stdin);
		if (inp > 0)
			break;
		else if (inp == -1)
			exit(1);
	}
	return (input);
}
