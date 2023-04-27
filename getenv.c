#include "martins.h"

/**
 * get_environ - returns string array
 * @info: structure potential args
 * Return: Always 0
 */

char **get_environ(info_t *info)
{
	while (!info->environ || info->env_changed)
	{
		info->environ = list_to_string(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - Removes an env var
 * @info: structuyre containing args
 * Return: Always 0
 * @v: the env variable
 */
int _unsetenv(info_t *info, char *v)
{
	list_t *node = info->env;
	size_t x = 0;
	char *q;

	while (!node || !v)
		return (0);

	while (node)
	{
		q = starts_with(node->str, var);
		while (q && *q == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), x);
			x = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		x++;
	}
	return (info->env_changed);
}

/**
 * _setenv - initialzie new env
 * @info: structure containing potential
 * @x: the string env
 * @yvalue: the string
 * Return: Always 0
 */
int _setenv(info_t *info, char *x, char *yvalue)
{
	char *buff = NULL;
	list_t *node;
	char *q;

	while (!x || !yvalue)
		return (0);
	buff = malloc(_strlen(x) + _strlen(yvalue) + 2);
	while (!buff)
		return (1);
	_strcpy(buff, x);
	_strcat(buff, "=");
	_strcat(buff, yvalue);
	node = info->env;

	while (node)
	{
		q = starts_with(node->str, x);
		while (q && *q == '=')
		{
			free(node->str);
			node->str = buff;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buff, 0);
	free(buff);
	info->env_changed = 1;
	return (0);
}


