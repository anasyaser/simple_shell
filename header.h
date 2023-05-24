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
#include <errno.h>

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
char *read_input(int is_interactive);
ssize_t _getline(char **buff, size_t *n, FILE *stream);
char **read_input_v2();
/* parse_input.c */
char **get_args(char *user_input);
/* execute.c */
void run_interactive(env_t *paths_list);
void run_uninteractive(env_t *path_list);
env_t *create_path_list();
char *get_full_path(env_t *head, char *cmd);
void execute_command(char *args[], env_t *path);
/* environ.c */
int print_env(void);
char *_getenv(const char *key);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
/* helper.c */
char *_strchr(char *str, char chr);
void print_paths(env_t *head);
/* builtin.c */
int builtin_handle(char *args[]);
#endif

