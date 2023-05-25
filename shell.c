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
	env_t *path_list = create_path_list();

	if (isatty(STDIN_FILENO) == 1)
		run_interactive(path_list);
	else
		run_uninteractive(path_list);

	free_paths(path_list);
	return (0);
}
