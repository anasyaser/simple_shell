#include "header.h"

/**
 * print_env - print current environment
 *
 * Return: None
 */
void print_env(void)
{
	char **cpy = environ;

	while (*cpy)
	{
		printf("%s\n", *cpy);
		cpy++;
	}
}

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

int _setenv(const char *name, const char *value, int overwrite)
{
	int name_len = strlen(name), value_len = strlen(value), env_len = 0;
	char *env_variable;
	char *var_value = _getenv(name);
	char *curr_var;
	char **new_env;

	if (!*name || strchr(name, '='))
		return (-1);

	if (var_value && !overwrite)
		return (0);

	env_variable = malloc(name_len + value_len + 2);
	if (env_variable == NULL)
		return (-1);
	strcpy(env_variable, name);
	strcat(env_variable, "=");
	strcat(env_variable, value);

	while (*(environ + env_len))
	{
		curr_var = *(environ + env_len);
		if (strncmp(curr_var, env_variable, name_len + 1) == 0 &&
		    overwrite)
		{
			*(environ + env_len) = env_variable;
			return (0);
		}
		env_len++;
	}

	new_env = malloc((env_len + 2) * sizeof(char *));
	if (new_env == NULL)
		return (-1);
	memcpy(new_env, environ, env_len * sizeof(char *));
	new_env[env_len] = env_variable;
	new_env[env_len + 1] = NULL;
	environ = new_env;
	return (0);
}

/**
 * _unsetenv - remove variable from enviroment
 *
 * @name: variable name
 * Return: 0 on success else -1
 */

int _unsetenv(const char *name)
{
	int env_len = 0;
	char *var_value = _getenv(name);
	int name_len = strlen(name);
	char *current_var;
	char **new_env;
	int n = 0, o = 0;

	if (!*name || strchr(name, '='))
		return (-1);

	if (var_value == NULL)
		return (0);

	while (*(environ + env_len))
		env_len++;

	new_env = malloc((env_len + 1) * sizeof(char *));
	if (new_env == NULL)
		return (-1);

	for (o = 0; o < env_len; o++)
	{
		current_var = *(environ + o);
		if (strncmp(current_var, name, name_len) == 0 &&
		    current_var[name_len] == '=')
			continue;
		new_env[n] = environ[o];
		n++;
	}
	new_env[n] = NULL;
	environ = new_env;

	return (0);
}
