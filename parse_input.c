#include "header.h"
/**
 * _strtok - split string at delim to tokens
 *
 * @str: string to split
 * @delim: string of delim
 * Return: pointer to string at nth delim
 */

char *_strtok(char *str, const char *delim)
{
	return (NULL);
}

/**
 * get_args - convert text to array
 *
 * @user_input: string to conver to array
 * Return: array of pointers to strings
 */

char **get_args(char *user_input)
{
	char *token;
	unsigned int i = 0;
	char **args = NULL;

	args = realloc(args, sizeof(char *) * (i + 1));
	token = strtok(user_input, " ");
	while (token)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
		args = realloc(args, sizeof(char *) * (i + 1));
	}
	args[i] = (char *) '\0';
	return (args);
}
