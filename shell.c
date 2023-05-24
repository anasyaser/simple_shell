#include "header.h"

/**
 * main - Entry point
 *
 * @ac: arguments counter
 * @av: array of program arguments
 * @env: program environment
 * Return: always (0)
 */

int main(UNUSED int ac, UNUSED char **av, UNUSED char **env)
{
	char *user_input;
	char **args;
	env_t *path_list = create_path_list();

	while (1)
	{
		user_input = read_input();
		args = get_args(user_input);
		execute_command(args, env, path_list);
	}
	free(user_input);
	free(args);
	return (0);
}
