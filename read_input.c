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

	printf("$ ");

	inp = getline(&input, &len, stdin);
	if (inp == -1)
		exit(1);
	*(input + inp - 1) = '\0';
	
	return (input);
}
