#include "header.h"

/**
 * builtin_handle - execution helper
 *
 * @args: list of aruments
 * Return: None
 */

int builtin_handle(cmd_t *cmd)
{
	int stat = -1;
	char **args = cmd->user_args;

	if (strcmp(args[0], "exit") == 0)
	{
		free_cmd(cmd);
		if (feof(stderr))
			exit(2);
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(args[0], "env") == 0)
		stat = print_env();
	else if (strcmp(args[0], "setenv") == 0)
		stat = _setenv(args[1], args[2], 1);
	else if (strcmp(args[0], "unsetenv") == 0)
		stat = _unsetenv(args[1]);

	return (stat);
}
