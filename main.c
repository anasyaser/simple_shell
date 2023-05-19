#include "shell.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    char *command = NULL;
    size_t command_len = 0;
    ssize_t getline_status;

    while (1)
    {
        printf("$ ");
        getline_status = getline(&command, &command_len, stdin);
        if (getline_status == -1)
        {
            free(command);
            exit(EXIT_SUCCESS);
        }
        /* remove trailing newline */
        command[getline_status - 1] = '\0';
        execute_command(command);
    }
    free(command);
    return (EXIT_SUCCESS);
}
