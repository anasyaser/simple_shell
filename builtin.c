#include "header.h"

/**
 * builtin_handle - execution helper
 *
 * @args: list of aruments
 * Return: None
 */

void builtin_handle(char *args[])
{
	if (strcmp(args[0], "exit") == 0)
		exit(EXIT_SUCCESS);
	else if (strcmp(args[0], "env") == 0)
	{
		print_env();
	} else if (strcmp(args[0], "setenv") == 0)
	{
		_setenv(args[1], args[2], 1);
		exit(EXIT_SUCCESS);
	} else if (strcmp(args[0], "unsetenv") == 0)
	{
		_unsetenv(args[1]);
		exit(EXIT_SUCCESS);
	}
}
