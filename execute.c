#include "header.h"

/**
 * execute_command - execute user input command
 *
 * @args: array of arguments
 * @path_list: linked list of paths dirs
 * Return: None
 */

void execute_command(cmd_t *cmd)
{
	pid_t child_process;
	int status;
	char *full_path;

	if (!*(cmd->user_input))
		return;

	if (builtin_handle(cmd) == 0)
	{
		free_cmd(cmd);
		exit(EXIT_SUCCESS);
	}
	full_path = cmd->cmd_full_path;
	if (!full_path)
	{
		fprintf(stderr, "%s: command not found\n",
			cmd->user_args[0]);
		return;
	}

	child_process = fork();
	if (child_process == -1)
	{
		perror("Error:");
		return;
	}
	if (child_process == 0)
	{
		if (execve(cmd->cmd_full_path, cmd->user_args,
			   environ) == -1)
			perror("Exe Error: ");
		exit(EXIT_FAILURE);
	}
	wait(&status);
	free_cmd(cmd);
	exit(EXIT_SUCCESS);
}
