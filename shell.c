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
	char **args = NULL;

	if (isatty(STDIN_FILENO) == 1)
		run_interactive(path_list);
	else
		run_uninteractive(args, path_list);
	return (0);
}
