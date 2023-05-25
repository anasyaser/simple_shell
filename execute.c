#include "header.h"

/**
 * create_path_list - create singly linked list of path directories
 *
 * Return: pointer to head of linked list of dirs
 */

path_t *create_path_list()
{
	path_t *head;
	path_t *current;
	char *paths;
	char *env_value = getenv("PATH");

	if (!env_value)
		return (NULL);
	paths = strdup(env_value);
	if (paths == NULL)
		return (NULL);

	head = malloc(sizeof(path_t));
	if (head == NULL)
		return (NULL);
	current = head;
	paths = strtok(paths, ":");
	while (paths)
	{
		current->path = paths;

		paths = strtok(NULL, ":");
		if (paths)
			current->next = malloc(sizeof(path_t));
		current = current->next;
	}
	return (head);
}

/**
 * get_full_path - create absolute path of command
 *
 * @path_list: pointer to head of paths linked list
 * @cmd: user command
 * Return: pointer to absoulte path of command
 */
char *get_full_path(path_t *path_list,char *cmd)
{
	char *path = NULL;
	int cmd_len = strlen(cmd);
	struct stat st;

	if (stat(cmd, &st) == 0)
		return (strdup(cmd));

	while (path_list)
	{
		path = realloc(path, strlen(path_list->path) + cmd_len + 2);
		if (path == NULL)
		{
			perror("Error: ");
			exit(EXIT_FAILURE);
		}
		strcpy(path, path_list->path);
		strcat(path, "/");
		strcat(path, cmd);
		if (stat(path, &st) == 0)
			return (path);
		path_list = path_list->next;
	}
	free(path);
	return (NULL);
}

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

	if (!cmd->user_args)
		return;

	if (builtin_handle(cmd->user_args) == 0)
		exit(EXIT_SUCCESS);
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
		free(full_path);
		return;
	}
	if (child_process == 0)
	{
		if (execve(cmd->user_args[0], cmd->user_args,
			   environ) == -1)
			perror("Error: ");
		exit(EXIT_FAILURE);
	}
	wait(&status);
}


/**
 * run_interactive - interactive shell
 *
 * @paths_list: list of paths
 * Return: None
 */

void run_interactive()
{
	cmd_t *cmd = NULL;
	while (1)
	{
		cmd = run_intialize_cmd(1);
		print_command(cmd);
		execute_command(cmd);
		free_cmd(cmd);
		free(cmd);
	}
}


/**
 * run_uninteractive - interactive shell
 *
 * @paths_list: list of paths
 * Return: None
 */

void run_uninteractive()
{
	cmd_t *cmd = NULL;
	while (1)
	{
		cmd = run_intialize_cmd(0);
		execute_command(cmd);
		free_cmd(cmd);
		free(cmd);
	}
}
