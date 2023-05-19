#include "shell.h"

/**
 * command_in_dir - Checks if command is in dir
 * @dir: The directory to check
 * @command: The command to look for
 *
 * Return: full path to command or NULL
 */
char *command_in_dir(char *dir, char *command)
{
    char *path = malloc(strlen(dir) + strlen(command) + 2);
    struct stat st;

    if (!path)
    {
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
    }

    strcpy(path, dir);
    strcat(path, "/");
    strcat(path, command);

    if (stat(path, &st) == 0)
    {
        return path;
    }

    free(path);
    return NULL;
}

/**
 * get_full_path - Returns full path of command
 * @command: The command to look for
 *
 * Return: full path to command or NULL
 */
char *get_full_path(char *command)
{
    char *path = getenv("PATH");
    char *dir = strtok(path, ":");

    while (dir)
    {
        char *full_path = command_in_dir(dir, command);

        if (full_path)
        {
            return full_path;
        }

        dir = strtok(NULL, ":");
    }

    return NULL;
}

/**
 * execute_command - Executes a command
 * @args: The arguments to pass to execve
 */
void execute_command(char **args)
{
    pid_t pid;
    int status;
    char *full_path;

    /* Check for the "exit" command */
    if (strcmp(args[0], "exit") == 0)
    {
        exit(EXIT_SUCCESS);
    }

    /* Check if command exists in current dir or in PATH */
    full_path = command_in_dir(".", args[0]);
    if (!full_path)
    {
        full_path = get_full_path(args[0]);
        if (!full_path)
        {
            fprintf(stderr, "%s: command not found\n", args[0]);
            return;
        }
    }

    pid = fork();
    if (pid == -1)
    {
        perror("Error:");
        free(full_path);
        return;
    }
    if (pid == 0)
    {
        /* Child process */
        args[0] = full_path;
        if (execve(args[0], args, NULL) == -1)
        {
            perror("Error:");
        }
        exit(EXIT_FAILURE);
    }
    else
    {
        /* Parent process */
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    free(full_path);
}

