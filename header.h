#ifndef SHELL

#define SHELL
#define UNUSED __attribute__((unused))

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *read_input();
char **get_args(char *user_input);
void input_exec(char **args, char **env);

ssize_t _getline(char **buff, size_t *n,FILE *stream);
char *_strtok(char *str, const char *delim);
#endif
	
