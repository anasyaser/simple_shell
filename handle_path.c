#include "header.h"

/**
 * get_path_value - return path value
 *
 * Return: pointer to allocated path value
 */

char *get_path_value()
{
	char *path_value = getenv("PATH");
	char *path_cpy = NULL;

	if (path_value == NULL)
		return (path_cpy);
	path_cpy = strdup(path_value);
	return (path_cpy);
}

/**
 * get_path_dir - creat array of paths directories
 *
 * @path_value: PATH value
 * Return: pointer to array of paths directories
 */

char **get_path_dir(char *path_value)
{
	int buffer_size = 5;
	int position = 0;
	char **tokens = NULL;
	char *token;


	if (path_value == NULL)
		return (NULL);

	tokens = malloc(buffer_size * sizeof(char *));
	if (tokens == NULL)
		return (NULL);


	token = strtok(path_value, ":");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= buffer_size)
		{
			buffer_size += buffer_size;
			tokens = realloc(tokens,
					 buffer_size * sizeof(char *));
			if (!tokens)
				return (NULL);
		}
		token = strtok(NULL, ":");
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 * command_in_dir - return absolute command path
 *
 * @dir: command directory
 * @command: command
 * Return: pointer to absolute command path
 */
char *command_in_dir(char *dir, char *command)
{
	int dir_len = strlen(dir);
	int command_len = strlen(command);
	char *path = NULL;

	if (command_len == 0 || dir_len == 0)
		return (NULL);

	path = malloc(dir_len + command_len + 2);
	if (path == NULL)
		return (NULL);

	strcpy(path, dir);
	strcat(path, "/");
	strcat(path, command);

	return (path);
}

/**
 * get_full_path - Returns full path of command
 *
 * @path_dirs: pointer to array of paths
 * @command: The command to look for
 * Return: full path to command or NULL
 */
char *get_full_path(char **path_dirs, char *command)
{
	struct stat st;
	char *full_path = NULL;

	if (command == NULL)
		return (NULL);

	if (stat(command, &st) == 0)
	{
		full_path = strdup(command);
		return (full_path);
	}

	if (path_dirs == NULL)
		return (NULL);

	while (*path_dirs)
	{
		full_path = command_in_dir(*path_dirs, command);
		if (stat(full_path, &st) == 0)
			return (full_path);
		else if (full_path)
			free(full_path);
		path_dirs++;
	}
	return (NULL);
}
