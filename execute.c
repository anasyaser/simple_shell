#include "header.h"

/**
 * create_path_list - create singly linked list of path directories
 *
 * @env_value: pointer of environment variable value
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
		current->next = malloc(sizeof(env_t));
		current = current->next;
		paths = strtok(NULL, ":");
	}
	return (head);
}

/**
 * get_path - create absolute path of command
 *
 * @head: pointer to head of paths linked list
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
	printf("hello 1\n");
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
 * Return: None
 */

void execute_command(char *args[], char **env,env_t *path_list)
{
	pid_t child_process;
	int status;
	char *full_path;

	if (strcmp(args[0], "exit") == 0)
		exit(EXIT_SUCCESS);
	if (strcmp(args[0], "env") == 0)
	{
		print_env();
		return;
	}
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
		if (execve(args[0], args, env) == -1)
			perror("Error: ");
		exit(EXIT_FAILURE);
	}
	wait(&status);
	free(full_path);
}
