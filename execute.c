#include "header.h"

/**
 * create_path_list - create singly linked list of path directories
 *
 * Return: pointer to head of linked list of dirs
 */

env_t *create_path_list()
{
	env_t *head;
	env_t *current;
	char *paths;
	char *env_value = _getenv("PATH");

	paths = malloc(strlen(env_value) + 1);
	if (paths == NULL)
		return (NULL);

	strcpy(paths, env_value);
	head = malloc(sizeof(env_t));
	if (head == NULL)
		return (NULL);
	current = head;
	paths = strtok(paths, ":");
	while (paths)
	{
		current->path = paths;

		paths = strtok(NULL, ":");
		if (paths)
			current->next = malloc(sizeof(env_t));
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
char *get_full_path(env_t *path_list, char *cmd)
{
	char *path;
	int cmd_len = strlen(cmd);
	struct stat st;

	if (stat(cmd, &st) == 0)
		return (cmd);

	while (path_list)
	{
		path = malloc(strlen(path_list->path) + cmd_len + 2);
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
	return (NULL);
}

/**
 * execute_command - execute user input command
 *
 * @args: array of arguments
 * @env: environment
 * @path_list: linked list of paths dirs
 * Return: None
 */

void execute_command(char *args[], env_t *path_list)
{
	pid_t child_process;
	int status;
	char *full_path;

	if (!*args)
		return;

	builtin_handle(args);

	full_path = get_full_path(path_list, args[0]);

	if (!full_path)
	{
		free(full_path);
		fprintf(stderr, "%s: command not found\n", args[0]);
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
		args[0] = full_path;
		if (execve(args[0], args, environ) == -1)
			perror("Error: ");
		exit(EXIT_FAILURE);
	}
	wait(&status);
	free(full_path);
}


/**
 * run_interactive - interactive shell
 *
 * @env: enviroment variable
 * @paths_list: list of paths
 * Return: None
 */

void run_interactive(env_t *paths_list)
{
	char *user_input;
	char **args;
	env_t *path_list = paths_list;

	while (1)
	{
		user_input = read_input();
		args = get_args(user_input);
		execute_command(args, path_list);
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

void run_uninteractive(char **args, env_t *path_list)
{
	execute_command(args, path_list);
}
