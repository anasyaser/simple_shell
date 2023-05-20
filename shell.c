#include "header.h"

/**
 * print_list - print all elements of list_t
 *
 * @h: pointer to list_t
 * Return: number of nodes in list_t
 */

size_t print_list(const env_t *h)
{
	int cnt = 0;

	while (h != NULL)
	{
		printf("Current path: %s\n", h->path);
		cnt++;
		h = h->next;
	}
	return (cnt);
}

/**
 * main - Entry point
 *
 * @ac: arguments counter
 * @av: array of program arguments
 * @env: program environment
 * Return: always (0)
 */

int main(UNUSED int ac, UNUSED char **av,UNUSED char **env)
{
	/* char *user_input; */
	/* char **args; */

	/* while (1) */
	/* { */
	/* 	user_input = read_input(); */
	/* 	args = get_args(user_input); */
	/* 	/\* args = read_input_v2(); *\/ */
	/* 	input_exec(args, env); */

	/* 	while (*args) */
	/* 	{ */
	/* 		free(*args); */
	/* 		args++; */
	/* 	} */
	/* 	free(args); */
	/* } */
	char *envirr = _getenv("PATH");
	env_t *head = create_path_list(envirr);
	char *path = get_path(head, "ls");
	printf("abso path: %s\n", path);
	return (0);
}
