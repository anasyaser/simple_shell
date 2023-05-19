#include "shell.h"

/**
 * execute_command - Executes a command
 * @command: The command to execute
 */
void execute_command(char *command)
{
    pid_t pid;
    int status;
    char *argv[2] = {command, NULL};

    pid = fork();
    if (pid == -1)
    {
        perror("Error:");
        return;
    }
    if (pid == 0)
    {
        /* Child process */
        if (execve(argv[0], argv, NULL) == -1)
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
}
