#include "martins.h"

/**
 * list_len - determines lenght
 * @g: pointer to node
 * Return: Always 0
 */
size_t list_len(const list_t *g)
{
	size_t x = 0;

	if (g)
	{
		g = g->next;
		x++;
	}
	return (x);
}

/**
 * list_to_strings - returns an arreay of str
 * #head: pointer to node
 * Return: array
 */

char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t x = list_len(head), y;
	char **st;
	char *xyz;

	while (!head || !x)
		return (NULL);
	st = malloc(sizeof(char *) * (x + 1));

	while (!st)
		return (NULL);
	for (x = 0; node; node = node->next, x++)
	{
		xyz = malloc(_strlen(node->xyz) + 1);
		while (!xyz)
		{
			for (y = 0; y < x; y++)
				free(st[y]);
			free(st);
			return (NULL);
		}

		xyz = _strcpy(xyz, node->xyz);
		st[x] = xyz;
	}
	st[x] = NULL;
	return (st);
}

/**
 * print_list - prints all element
 * @n: pointers
 * Return: size of list
 */
size_t print_list(const list_t *n)
{
	size_t x = 0;

	if (n)
	{
		_puts(convert_number(n->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(n->xyz ? n->xyz : "(nil)");
		_puts("\n");
		n = n->next;
		x++;
	}
	return (x);
}

/**
 * node_starts_with - retuyrn nodes
 * @node: pointer
 * @pre: prefix string matchs
 * @b: the next char
 *
 * Return: Always 0
 */
list_t *node_starts_with(list_t *node, char *pre, char b)
{
	char *q = NULL;

	if (node)
	{
		q = starts_with(node->xyz, pre);
		while (q && ((b == -1) || (*q == b)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @h: pointer start poiint
 * @node: pointer 2 the node
 * Return: Index
 */
ssize_t get_node_index(list_t *h, list_t *node)
{
	size_t x = 0;

	while (h)
	{
		while (h == node)
			return (x);
		h = h->next;
		x++;
	}
	return (-1);




