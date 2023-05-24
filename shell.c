#include "header.h"


/**
 * run_interactive - interactive shell
 *
 * @env: enviroment variable
 * @paths_list: list of paths
 * Return: None
 */

void run_interactive(char **env, env_t *paths_list)
{
	char *user_input;
	char **args;
	env_t *path_list = paths_list;

	while (1)
	{
		user_input = read_input();
		args = get_args(user_input);
		execute_command(args, env, path_list);
	}
	free(user_input);
	free(args);
}


/**
 * run_uninteractive - interactive shell
 *
 * @args: list of arguments
 * @env: enviroment variable
 * @path_list: list of paths
 * Return: None
 */

void run_uninteractive(char **args, char **env, env_t *path_list)
{
	execute_command(args, env, path_list);
}

/**
 * main - Entry point
 *
 * @ac: arguments counter
 * @av: array of program arguments
 * @env: program environment
 * Return: always (0)
 */

int main(int ac, char **av, char **env)
{
	env_t *path_list = create_path_list();
	char **args;

	if (ac > 1)
	{
		args = av + 1;
		args[ac - 1] = NULL;
		run_uninteractive(args, env, path_list);
	}
	else
	{
		run_interactive(env, path_list);
	}
	return (0);
}
