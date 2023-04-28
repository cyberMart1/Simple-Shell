#include "martins.h"

/**
 * is_cmd - determines if a file is executable
 * @info: tyhe info struct
 * @path: path of the file
 * Return: Always 0
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);
	if (st.st_mode & S_IFREG)
		return (1);
	return (0);
}

/**
 * dup_chars - suplicate characters
 * @pathstr: the PAH
 * @start: startinmg point
 * @stop: stoppping index
 *
 * Return: Always 0
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buff[1024];
	int x = 0, y = 0;

	for (y = 0, x = start; x < stop; x++)
		if (pathstr[x] != ':')
			buff[y++] = pathstr[x];
	buff[y] = 0;
	return (buff);
}

/**
 * find_path - finds the cmd
 * @info: the struct
 * @pathstr: PATH string
 * @cmd: cmd to find
 * Return: full path
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int x = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[x] || pathstr[x] == ':')
		{
			path = dup_chars(pathstr, curr_pos, x);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[x])
				break;
			curr_pos = x;
		}
		x++;
	}
	return (NULL);
}

