#include "header.h"


/**
 * _getline - read line from stream
 *
 * @buff: pointer to buffer containf the text
 * @n: number of line chars
 * @stream: file to read from
 * Return: number of readed chars else if fail return -1
 */

ssize_t _getline(char **buffer, size_t *n, FILE *stream)
{
	char buff[120];
	ssize_t nread;

	nread = read(fileno(stream), buff, sizeof(buff));
	if (nread == -1)
		exit(EXIT_FAILURE);
}


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
