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
	int is_interactive = isatty(STDIN_FILENO);
	cmd_t *cmd = NULL;

	while (1)
	{
		cmd = run_intialize_cmd(is_interactive);
		execute_command(cmd);
		free_cmd(cmd);

	}
	return (0);
}
