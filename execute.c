#include "header.h"

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
