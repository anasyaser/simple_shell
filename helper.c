#include "header.h"

/**
 * _strchr - get char index in string
 *
 * @str: pointer to string
 * @chr: char to get its incdex
 * Return: (int) index of given char if not found return (strlen)
 */

int _strchr(char *str, char chr )
{
	int index = 0;

	while (*str)
	{
		if (*str == chr )
			return (index);
		str++;
		index++;
	}
	return (index);
}

/**
 * _memset - set value at memorty address
 * Discription: fill the nth bytes of memory area pointed
 * by pointer with constant value
 * @s: pointer to reallocate
 * @b: constant value used to fill a pointer
 * @n: number of addresses to fill pointer address
 * Return: Pointer to the modified memory area
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int inc = 0;

	while (inc < n)
	{
		s[inc] = b;
		inc++;
	}
	return (s);
}
