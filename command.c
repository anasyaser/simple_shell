#include "header.h"

/**
 * run_intialize_cmd - intialize command
 *
 * Return: commdand
 */

cmd_t *run_intialize_cmd(int is_interactive)
{
	cmd_t *cmd = malloc(sizeof(cmd_t));
	if (cmd == NULL)
	{
		fprintf(stderr, "Allocation error");
		exit(EXIT_FAILURE);
	}
	cmd->user_input = read_input(is_interactive);
	cmd->user_args = get_args(cmd->user_input);
	cmd->env_paths = create_path_list();
	cmd->cmd_full_path = get_full_path(cmd->env_paths,
					   cmd->user_args[0]);

	return (cmd);
}

/**
 * free_cmd - free all memory allocation by command
 *
 * @cmd: pointer to command
 * Return: None
 */

void free_cmd(cmd_t *cmd)
{
	free(cmd->user_input);
	free(cmd->user_args);
	if (cmd->env_paths)
	{
		free_paths(cmd->env_paths);
	}
	if (cmd->cmd_full_path)
		free(cmd->cmd_full_path);
}

/**
 * print_command - print command info
 *
 * @cmd: pointer to command
 * Return: None
 */

void print_command(cmd_t *cmd)
{
	char **args;

	if (!cmd)
		printf("No command is intialized");
	printf("Command Info:\n");

	printf("User Input:\n");
	printf("%s\n", cmd->user_input);

	printf("argunents:\n");
	args = cmd->user_args;
	while (*args)
	{
		printf("%s ", *args);
		args++;
	}
	printf("\n");

	printf("PATH:\n");
	print_paths(cmd->env_paths);

	printf("Full Path:\n");
	printf("%s\n", cmd->cmd_full_path);
	printf("\n");
}
