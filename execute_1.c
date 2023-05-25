/**
 * execute_command - execute user input command
 *
 * @args: array of arguments
 * @path_list: linked list of paths dirs
 * Return: None
 */

void execute_command(char *args[], env_t *path_list)
{
	pid_t child_process;
	int status, flag = 0, ret = 0;
	char *command = args[0];

	if (!*args)
		return;

	if (builtin_handle(args) == 0)
		exit(EXIT_SUCCESS);

	if (command[0] != '/' && command[0] != '.')
	{
		flag = 1;
		command = get_full_path(path_list, args[0]);
	}

	if (!command || (access(command, F_OK) == -1))
	{
		if (errno == EACCES)
			ret = (create_error(args, 126));
		else
			ret = (create_error(args, 127));
	}
	else
	{
		child_process = fork();
		if (child_process == -1)
		{
			if (flag)
				free(command);
			perror("Error:");
			return;
		}
		if (child_process == 0)
		{
			execve(command, args, environ);
			if (errno == EACCES)
				ret = (create_error(args, 126));
			free_env();
			free_args(args);
			free_alias_list(aliases);
			free(command);
			_exit(ret);
		}
		else
		{
			wait(&status);
			ret = WEXITSTATUS(status);
		}
	}
	if (flag)
		free(command);
}

