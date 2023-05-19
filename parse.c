#include "shell.h"

/**
 * parse_command - parse the command into array of arguments
 * @command: command inputted by the user
 *
 * Return: array of arguments
 */
char **parse_command(char *command)
{
    int buffer_size = 64;
    int position = 0;
    char **tokens = malloc(buffer_size * sizeof(char*));
    char *token;

    if (!tokens)
    {
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(command, " ");
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        if (position >= buffer_size)
        {
            buffer_size += buffer_size;
            tokens = realloc(tokens, buffer_size * sizeof(char*));
            if (!tokens)
            {
                fprintf(stderr, "Allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, " ");
    }
    tokens[position] = NULL;
    return tokens;
}
