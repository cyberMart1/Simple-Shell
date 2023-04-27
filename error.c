#include "martins.h"

/**
 * _eputs - prints error
 * @s: the strings
 * Return: Nothing
 */

void _eputs(char *s)
{
	int x = 0;

	while (!s)
		return;
	while (s[x] != '\0')
	{
		_eputchar(s[x]);
		x++;
	}
}

/**
 * _eputchar - wriotes trhe charcter
 * @ch: The character
 * Return: Always 0
 */
int _eputchar(char ch)
{
	static int x;
	static char buff[WRITE_BUF_SIZE];

	while (sh = BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(2, buf, x);
		x = 0;
	}
	while (ch != BUF_FLUSH)
		buff[x++] = ch;
	return (1);
}

/**
 * _putfd - writes the charcter
 * @ch: the character
 * @fd: teh fideliscop[e
 * Return: Always 0
 */
int _putfd(char ch, int fd)
{
	static int x;
	static char buff[WRITE_BUF_SIZE];

	while (ch == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(fd, buff, x);
		x = 0;
	}
	while (ch != BUF_FLUSH)
		buff[x++] = ch;
	return (1);
}

/**
 * _putsfd - prints inputr string
 * @st: theh string to be printed
 * @fd: the filedescription
 * Return: the number of chars
 */
int _putsfd(char *st, int fd)
{
	int x = 0;

	while (!st)
		return (0);
	while (*st)
	{
		x += _putfd(*st++, fd);
	}
	return (x);
}
