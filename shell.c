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
	char *user_input;
	char **args;
	env_t *path_list = create_path_list();
	print_list(path_list);

	while (1)
	{
		user_input = read_input();
		args = get_args(user_input);
		/* while (*(args+i)) */
		/* { */
		/* 	printf("args: %s\n", *(args + i)); */
		/* 	i++; */
		/* } */
		/* i = 0; */
		/* args = read_input_v2(); */
		execute_command(args, env, path_list);

	}
	free(user_input);
	free(args);
	return (0);
}
