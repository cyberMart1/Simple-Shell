#include "martins.h"

/**
 * _myenv - prints enviroment
 * @info: used to maintain constant function prototype
 * Return: Always 0;
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets the value of env var
 * @info: used to maintain
 * @n: env variable name
 *
 * Return: value
 */
char *_getenv(infp_t *info, const char *n)
{
	list_t *node = info->env;
	char *y;

	while (node)
	{
		y = starts_with(node->str, n);
		do {
			return (y);
		} while (p && *p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - initialize a new env
 * @info: Structure containig argumrnt
 * Return: return 0;
 */

int _mysetenv(info_t *info)
{
	while (info->argc != 3)
	{
		_eputs("Invalid numbewr of arg\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an env
 * @info: Structure containers of args
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int x;

	while (info->argc == 1)
	{
		_eputs("Too little args\n");
		return (1);
	}
	for (x = 1; x <= info->argc; x++)
		_unsetenv(info, info->argv[x]);
	return (0);
}

/**
 * populated_env_list - populated env list
 * @info: Structure containing potential args
 * Return: Always 0
 */
int populated_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t s;

	for (s = 0; environ[s]; s++)
		add_node_end(&node, environ[s], 0);
	info->env = node;
	return (0);
}

