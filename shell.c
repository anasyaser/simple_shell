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
	path_t *paths_list = create_path_list();
	print_paths(paths_list);
	free(paths_list);
	/* if (isatty(STDIN_FILENO) == 1) */
	/* { */
	/* 	run_interactive(); */
	/* } else */
	/* { */
	/* 	run_uninteractive(); */
	/* } */

	return (0);
}
