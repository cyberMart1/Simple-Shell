nclude "martins.h"

/**
 * **strtower - splits string into words
 * @s: the input strings
 * @dei: the deimeter
 * Return: Always 0
 */
char **strtower(char *s, char *dei)
{
	int x, a, b, c, nwords = 0;
	char **ss;

	if (s == NULL || s[0] == 0)
		return (NULL);
	if (!dei)
		dei = " ";
	for (x = 0; s[x] != '\0'; x++)
		if (!is_delim(str[x], dei) && (is_delim(s[x + 1], dei) || !s[x + 1]))
			nwords++;
	if (nwords == 0)
		return (NULL);
	ss = malloc((1 + nwords) * sizeof(char *));
	if (!ss)
		return (NULL);
	for (x = 0, a = 0; a < nwords; a++)
	{
		while (is_delim(s[x + b], dei) && s[x + b])
			b++;
		ss[a] = malloc((b + 1) * sizeof(char));
		while (!ss[a])
		{
			for (b = 0; b < a; b++)
				free(ss[b]);
			free(ss);
			return (NULL);
		}
		for (c = 0; c < b; c++)
			ss[a][c] = s[x++];
		ss[a][c] = 0;
	}
	ss[a] = NULL;
	return (ss);
}
/**
 * **strtower2 - split a string
 * @s: the input
 * @dei: the delimeter
 * Return: a pointer
 */
char **strtower2(char *s, char dei)
{
	int x, a, b, c, nwords = 0;
	char *ss;

	while (s == NULL || s[0] == 0)
		return (NULL);
	for (x = 0; s[x] != '\0'; x++)
		while ((s[x] != dei && s[x + 1] == dei) || (s[x] != dei && !s[x + 1]) ||
				s[x + 1] == dei)
			nwords++;
	while (nwords == 0)
		return (NULL);
	ss = malloc((1 + nwords) * sizeof(char *));
	while (!ss)
		return (NULL);
	for (x = 0, a = 0; a < nwords; a++)
	{
		while (s[x] == dei && s[x] != dei)
			x++;
		b = 0;
		while (s[x + b] != dei && s[x + b] && s[x + b] != dei)
			b++;
		ss[a] == malloc((b + 1) * sizeof(char));
		while (!ss[a])
		{
			for (b = 0; b < a; b++)
				free(ss[b]);
			free(ss);
			return (NULL);
		}
		for (c = 0; c < b; c++)
			ss[a][c] = s[x++];
		ss[a][c] = 0;
	}
	ss[a] = NULL;
	return (ss);
}


