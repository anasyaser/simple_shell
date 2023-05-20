#include "header.h"

/**
 * list_path_dirs - create singly linked list of path directories
 *
 * @env_value: pointer of environment variable value
 * Return: pointer to directories
 */

env_t *create_path_list(char *env_value)
{
	env_t *head;
	env_t *current;
	char *paths;

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
char *get_path(env_t *head, char *cmd)
{
	char *path = head->path;
	env_t *cur_path = head;
	int cmd_len = strlen(cmd);
	struct stat st;

	if (stat(cmd, &st) == 0)
		return (cmd);

	while (cur_path)
	{
		path = realloc(path, strlen(cur_path->path) + cmd_len + 1);
		strcat(path, "/");
		strcat(path,cmd);
		if (stat(path, &st) == 0)
			return (path);
	}
	return (NULL);
}

/**
 * input_exec - execute user input command
 *
 * @args: array of arguments
 * @env: environment
 * Return: None
 */

void input_exec(char *args[], char **env)
{
	pid_t child_process;
	int status;

	
	child_process = fork();
	if (child_process == -1)
	{
		printf("Error:");
		return;
	}

	if (child_process == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			printf("Error: no such file or directory\n");
		}
	}
	wait(&status);
}
