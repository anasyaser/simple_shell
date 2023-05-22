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
