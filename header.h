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
 * struct path_s - linked list of path directories
 * @path: string (malloc'ed string)
 * @next: pointer to next node
 *
 * Description: singly linked list node
 */
typedef struct path_s
{
	char *path;
	struct path_s *next;
} path_t;

/**
 * struct cmd_s - linked list of command info
 *
 * @user_input: user input
 * @user_args: array of user input arguments
 * @path_value: pointer to path value
 * @path_dirs: array of path directories
 * @cmd_full_path: command full path
 * Description: singly linked list node
 */
typedef struct cmd_s
{
	char *user_input;
	char **user_args;
	char *path_value;
	char **path_dirs;
	char *cmd_full_path;
} cmd_t;

/* read_input.c */
char *read_input(int is_interactive, cmd_t *cmd);

/* parse_input.c */
char **get_args(char *user_input);

/*command.c*/
cmd_t *run_intialize_cmd(int is_interactive);
void free_cmd(cmd_t *cmd);
void print_command(cmd_t *cmd);
/* execute.c */
char *get_path_value(void);
char **get_path_dir(char *path_value);
char *command_in_dir(char *dir, char *command);
path_t *create_path_list();
char *get_full_path(char **path_dir, char *cmd);
void execute_command(cmd_t *cmd);
void run_interactive(void);
void run_uninteractive(void);

/* environ.c */
int print_env(void);
void print_env2(void);
char *_getenv(const char *key);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

/* helper.c */
char *_strchr(char *str, char chr);
void print_paths(path_t *head);
void free_paths(path_t *head);

/* builtin.c */
int builtin_handle(cmd_t *cmd);
#endif

