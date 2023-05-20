#ifndef SHELL

#define SHELL
#define UNUSED __attribute__((unused))

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/**
 * struct env_s - linked list of path directories
 * @path: string (malloc'ed string)
 * @next: pointer to next node
 *
 * Description: singly linked list node
 */
typedef struct env_s
{
	char *path;
	struct env_s *next;
} env_t;
/* read_input.c */
char *read_input();
/* parse_input.c */
char **get_args(char *user_input);
/* execute.c */
char *_getenv(const char *key);
env_t *create_path_list(char *env_value);
char *get_path(env_t *head, char *cmd);
void input_exec(char **args, char **env);
/* ------------ */
ssize_t _getline(char **buff, size_t *n,FILE *stream);
char **read_input_v2();
/* helper.c */
int _strchr(char *str, char chr);
/* environ.c */
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
#endif
	
