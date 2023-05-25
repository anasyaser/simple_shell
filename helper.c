#include "header.h"

/**
 * _strchr - get char index in string
 *
 * @str: pointer to string
 * @chr: char to get its incdex
 * Return: pointer to required char in string
 */

char *_strchr(char *str, char chr)
{
	while (*str)
	{
		if (*str == chr)
			return (str);
		str++;
	}
	if (chr == '\0')
		return (str);
	return (NULL);
}

/**
 * print_paths - print paths linked list
 *
 * @path_list: pointer of head of LLS
 * Return: None
 */

void print_paths(path_t *path_list)
{
	while (path_list)
	{
		printf("%s\n", path_list->path);
		path_list = path_list->next;
	}
}

/**
 * free_paths - free paths linked list
 *
 * @head: head to linked list
 * Return: None
 */

void free_paths(path_t *head)
{
	path_t *tmp = head;

	if (head == NULL)
		return;

	free(head->path);
	while (tmp != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
