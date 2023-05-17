						\
#include "header.h"

/**
 * main - Entry point
 *
 * @ac: arguments counter
 * @av: array of program arguments
 * @env: program environment
 * Return: always (0)
 */

int main(UNUSED int ac, UNUSED char **av, char **env)
{
	char *user_input;
	char **args;

	while (1)
	{
		user_input = read_input();
		args = get_args(user_input);
		input_exec(args, env);

		free(user_input);
		free(args);
	}
	return (0);
}
