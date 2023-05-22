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
	{
		free(input);
		exit(EXIT_FAILURE);
	}
	*(input + inp - 1) = '\0';

	return (input);
}


/**
 * _getline - read line from stream
 *
 * @buffer: pointer to buffer containf the text
 * @n: number of line chars
 * @stream: file to read from
 * Return: number of readed chars else if fail return -1
 */

ssize_t _getline(UNUSED char **buffer, UNUSED size_t *n, FILE *stream)
{
	char buff[1024];
	ssize_t nread;

	if (n == NULL || buffer == NULL)
		return (-1);

	nread = read(fileno(stream), buff, 1024);
	if (nread == -1)
		exit(EXIT_FAILURE);

	return (nread);
}


/**
 * read_input_v2 - read input and split string at delim to tokens
 *
 * Return: pointer to string at nth delim
 */

char **read_input_v2()
{
	char *token;
	size_t n = 0;
	unsigned int i = 0;
	char **args = NULL;

	args = realloc(args, sizeof(char *) * (i + 1));

	while (getdelim(&token, &n, ' ', STDIN_FILENO) != -1)
	{
		args[i] = token;
		i++;
		args = realloc(args, sizeof(char *) * (i + 1));
	}
	args[i] = (char *) '\0';
	return (args);
}

