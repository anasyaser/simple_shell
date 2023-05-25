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
 	/* cmd_t *cmd = malloc(sizeof(cmd_t)); */

	/* cmd->user_input = read_input(1); */
	/* cmd->user_args = get_args(cmd->user_input); */
	/* cmd->path_value = get_path_value(); */
	/* cmd->path_dirs = get_path_dir(cmd->path_value); */
	/* cmd->cmd_full_path = get_full_path(cmd->path_dirs, cmd->user_args[0]); */
	/* print_command(cmd); */
	/* free_cmd(cmd); */
	/* free(cmd); */
	int is_interactive = 0;
	cmd_t *cmd = NULL;

	if (isatty(STDIN_FILENO) == 1)
		is_interactive = 1;

	while (1)
	{
		cmd = run_intialize_cmd(is_interactive);
		execute_command(cmd);
		free_cmd(cmd);
		free(cmd);
	}

	return (0);
}
