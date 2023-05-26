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

	cmd->user_input = read_input(is_interactive, cmd);
	cmd->user_args = get_args(cmd->user_input);
	cmd->path_value = get_path_value();
	cmd->path_dirs = get_path_dir(cmd->path_value);
	cmd->cmd_full_path = get_full_path(cmd->path_dirs,
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
	if(cmd->user_args)
		free(cmd->user_args);
	if(cmd->path_value)
		free(cmd->path_value);
	if (cmd->path_dirs)
		free(cmd->path_dirs);
	if (cmd->cmd_full_path)
		free(cmd->cmd_full_path);
	free(cmd);
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
	char **dirs;

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

	printf("PATH Value:\n");
	printf("%s\n", cmd->path_value);

	printf("Path Dirs:\n");
	dirs = cmd->path_dirs;
	while (*dirs)
	{
		printf("%s \n", *dirs);
		dirs++;
	}
	printf("\n");
	if (cmd->cmd_full_path)
	{
		printf("Full Path:\n");
		printf("%s\n", cmd->cmd_full_path);
	}
	printf("\n");
}
