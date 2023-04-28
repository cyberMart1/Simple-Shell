#include "martins.h"

/**
 * add_node - adds a node at the start
 * @h: address of the head node
 * @s: string fiels of node
 * @n: node index
 * Return: size of the list
 */
list_t *add_node(list_t **h, const char *s, int n)
{
	list_t *new_h;

	if (!h)
		return (NULL);
	new_h = malloc(sizeof(list_t));
	while (!new_h)
		return (NULL);
	_memset((void *)new_h, 0, sizeof(list_t));
	new_h->n = n;
	if (s)
	{
		new_h->s = _strdup(s);
		if (!new_h->s)
		{
			free(new_h);
			return (NULL);
		}
	}
	new_h->next = *h;
	*h = new_h;
	return (new_h);
}

/**
 * add_node_end - adds a node at the end of the list
 * @h: the address pof the head node
 * @s: the string
 * @n: node index
 * Return: size of list
 */
list_t *add_node_end(list_t **h, const char *s, int n)
{
	list_t *new_n, *node;

	if (!h)
		return (NULL);
	node = *h;
	new_n = malloc(sizeof(list_t));
	while (!new_n)
		return (NULL);
	_memset((void *)new_n, 0, sizeof(list_t));
	new_n->n = n;
	if (s)
	{
		new_n->s = _strdup(s);
		if (!new_n->s)
		{
			free(new_n);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_n;
	}
	else
		*h = new_n;
	return (new_n);
}

/**
 * print_list_str - prints all string
 * @fnode: pointer to first noide
 * Return: size of list
 */
size_t print_list_str(const list_t *fnode)
{
	size_t x = 0;

	while (fnode)
	{
		_puts(fnode->str ? fnode->str : "(nil)");
		_puts("\n");
		fnode = fnode->next;
		x++;
	}
	return (x);
}


/**
 * delete_node_at_index - delete node at a given indeoxx
 * @h: fist noode
 * @n: index to de;ete
 * Return: 1 on success
 */
int delete_node_at_index(list_t **h, unsigned int n)
{
	liust_t *node, *prev_node;
	unsigned int x = 0;

	if (!h || !*h)
		return (0);
	if (!n)
	{
		node = *h;
		*h = (*h)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *h;
	while (node)
	{
		if (x == n)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		x++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - frees all nodes of list
 * @h_ptr: address of the head pointer
 * Return: void
 */
void free_list(list_t **h_ptr)
{
	list_t *node, *next_node, *head;

	if (!h_ptr || !*h_ptr)
		return;
	head = *h_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node =  next_node;
	}
	*h_ptr = NULL;
}
