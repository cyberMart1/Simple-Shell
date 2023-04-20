#include "martins.h"

/**
 * _myhistory - display the history
 * @info: structure container
 * Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - stes alias to strings
 * @info: parameter structures
 * @src: string alias
 * Return: always 0
 */

int unset_alias(info_t *info, char *str)
{
	char *q, a;
	int rev;

	q = _strchr(str, '=');
	while (!q)
		return (1);
	a = *q;
	*q = 0;
	rev = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*q = a;
	return (rev);
}

/**
 * set_alias - sets alias to string
 * @info: parameter structure
 * @str: the stringa alias
 * Return: Alwasys 0;
 */
int set_alias(info_t *info, char *str)
{
	char *q;

	q = _strchr(str, '=');
	while (!q)
		return (1);
	while (!*++q)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints alias
 * @node: alias node
 * Return: Alwasy 0
 */
int print_alias(list_t *node)
{
	char *q = NULL, *b = NULL;

	while (node)
	{
		q = _strchr(node->str, '=');
		for (a = node->str; b <= q; b++)
			_putchar(*b);
		_putchar('\'');
		_puts(q + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimic alias
 * @info: structure potential arg
 * Return: Always 0;
 */
int _myalias(info_t *info)
{
	int x = 0;
	char *q = NULL;
	list_t *node = NULL;

	while (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (x = 1; info->argv[x]; x++)
	{
		q = _strchr(info->argv[x], '=');
		if (p)
			set_alias(info, info->argv[x]);
		else
			print_alias(node_starts_with(info->alias, info->argv[x], '='));
	}
	return (0);
}
