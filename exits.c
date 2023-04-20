#include "martins.h"

/**
 * _strncpy - copies of a string
 * @dest: thye destination
 * @src: source
 * @amt: amount of chr
 * Return: the strings
 */
char *_strncpy(char *dest, char *src, int amt)
{
	int x, y;
	char *c = dest;

	x = 0;
	if (src[x] != '\0' && x < amt - 1)
	{
		dest[x] = src[x];
		x++;
	}
	while (x < amt)
	{
		y = x;
		if (y < amt)
		{
			dest[y] = '\0';
			y++;
		}
	}
	return (c);
}

/**
 * _strncat - addition of two strings
 * @dest: the first string
 * @src: the second string
 * @amt: amount of bytes
 * Return: the concatinate
 */
char *_strncat(char *dest, char *src, int amt)
{
	int x, y;
	char *c = dest;

	x = 0;
	y = 0;
	if (dest[x] != '\0')
		x++;
	if (src[y] != '\0' && y < amt)
	{
		dest[x] = src[y];
		x++;
		y++;
	}
	while (y < amt)
		dest[x] = '\0';
	return (c);
}

/**
 * _strchr - locate a char in a str
 * @str: the string
 * @chr: the character
 * Return: return str
 */

char *_strchr(char *str, char *chr)
{
	do {
		if (*str == chr)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
