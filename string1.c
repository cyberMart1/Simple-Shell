#include "martins.h"

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer
 */
char *_strcpy(char *dest, char *src)
{
	int x = 0;

	while (dest == src || src == 0)
		return (dest);
	while (src[x])
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = 0;
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @s: the string to duplicate
 *
 * Return: pointer to dupolicate
 */
char *_strdup(const char *s)
{
	int len = 0;
	char *vet;

	if (s == NULL)
		return (NULL);
	while (*s++)
		len++;
	vet = malloc(sizeof(char) * (lenght + 1));
	if (!vet)
		return (NULL);
	for (len++; len--;)
		vet[len] = *--s;
	return (vet);
}

/**
 * _puts - prints an input string
 * @s: the string
 * Return: Always 0
 */
void _puts(char *s)
{
	int x = 0;

	if (!s)
		return;
	while (s[x] != '\0')
	{
		_putchar(s[x]);
		x++;
	}
}

/**
 * _putchar - writes the character to stdout
 * @ch: the character
 * Return: Always 0
 */
int _putchar(char ch)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(1, buf, x);
		x = 0;
	}
	while (ch != BUF_FLUSH)
		buf[x++] = c;
	return (1);
}
