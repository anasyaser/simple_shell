#include "header.h"

/**
 * _getenv - get value of environment variable name
 *
 * @key: environment variable name
 * Return: value of environment variable name
 */

char *_getenv(const char *key)
{
	char **envir = environ;
	int len = strlen(key);

	if (len == 0)
		return (NULL);

	while (*envir)
	{
		if (strncmp(*envir, key, len) == 0)
			return (*envir + len + 1);
		envir++;
	}
	return (NULL);
}

/**
 * _setenv - set variable to environment
 *
 * @name: pointer to name (key)
 * @value: pointer to value (value)
 * @overwrite: if not zero then overwrite if name exist in environment
 * Return: 0 on success else -1
 */

int _setenv(const char *name, const char *value,UNUSED int overwrite)
{
	UNUSED char *curr_name = _getenv(name);
	int env_len = 0;
	int name_len = strlen(name);
	int value_len = strlen(value);
	char *env_variable;
	int i = 0;

	while (*(environ + env_len))
		env_len++;

	env_variable = malloc(name_len + value_len + 2);
	if (env_variable == NULL)
	{
		return (-1);
	}

	while (i < name_len || i < value_len)
	{
		if (i < name_len)
			env_variable[i] = *(name + i);
		else if (i == name_len)
			env_variable[i] = '=';
		else
			env_variable[i] = *(value + i);
		i++;
	}
	env_variable[i] = '\0';

	*environ = realloc(*environ, (env_len + 1) * sizeof(char *));
	return (1);

}
