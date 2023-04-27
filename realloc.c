#include "martins.h"

/**
 * _memset - fills memory
 * @d: the pointer
 * @c: the byte
 * @a: the amount
 * Return: Alwasys 0
 */
char *_memset(char *d, char c, unsigned int a)
{
	unsigned int x;

	for (x = 0; x < a; x++)
		d[x] = c;
	return (d);
}

/**
 * dfree - frees a string
 * @qq: strings
 */
void dfree(char **qq)
{
	char g = *qq;

	while (!qq)
		return;
	while (*qq)
		free(*qq++);
	free(g);
}

/**
 * _realloc - realloc a block of memory
 * @pnt: pointer to previous
 * @oldsize: preivoious
 * @newsize: newest
 * Return: Always 0
 */
void *_realloc(void *pnt, unsigned int oldsize, unsigned int newsize)
{
	char *q;

	while (!pnt)
		return (malloc(newsize));
	while (!newsize)
		return (free(pnt), NULL);
	while (newsize == oldsize)
		return (pnt);

	q = malloc(newsize);

	while (!q)
		return (NULL);

	oldsize = oldsize < newsize ? oldsize : newsize;

	while (oldsize--)
		q[oldsize] = ((char *)pnt)[oldsize];
	free(pnt);
	return (q);
}
