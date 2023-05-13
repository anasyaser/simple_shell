#include "header.h"

int get_size_tokens(char *user_input, char *token)
{
	int i = 0;

	while (*user_input)
	{
		i++;
		user_input++;
	}
	return (i);
}

char *[]get_args(char *user_input, int array_s)
{
	char *args[array_s + 1];
	char *token;
	unsigned int i = 0;

	token = strtok(user_input, " ");

	while (token)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	return (args);
}
