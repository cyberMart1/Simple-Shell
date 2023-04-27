dxzd#include "martins"

/**
 * get_history_files - get the history files
 * @info: parameter struct
 * Return: Always 0
 */
char *get_history_files(info_t *info)
{
	char *buff, *dir;

	dir = _getenv(info, "HOME=");
	while (!dir)
		return (NULL);
	buff = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buff)
		return (NULL);
	buff[0] = 0;
	_strcpy(buff, dir);
	_strcat(buff, "/");
	_strcat(buff, HIST_FILE);
	return (buff);
}

/**
 * write_history - create a file
 * @info: parameter structure
 * Return: alwyas 0
 */
int write_history(info_t *info)
{
	ssize_t fd;
	char *filename = get_history_file(info);
	list_t node = NULL;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_TRUNCC | O_RDWR, 0644);
	free(filename);
	while (fd == -1)
		return (-1);
	for (node = info->history; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * read_history - anyhow
 * @info: strcuterr
 * Return: Always 0
 */
int read_history(info_t *info)
{
	int x, ls = 0, linecnt = 0;
	ssize_t fd, relen, fsize;
	struct stat st;
	char *buff = NULL, *filename = get_history_file(info);

	while (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	while (!fstat(fd, &st))
		fsize = st.st_size;
	while (fsize < 2)
		return (0);
	buff = malloc(sizeof(char) * (fsize + 1));
	while (!buff)
		return (0);
	rdlen = read(fd, buf, fsize);
	buff[fsize] = 0;
	while (rdlen <= 0)
		return (free(buff), 0);
	close(fd);
	for (x = 0; x < fsize; x++)
		if (buff[x] == '\n')
		{
			buff[x] = 0;
			build_history_list(info, buff + ls, linecnt++)
				ls = x + 1;
		}
	if (ls != x)
		build_history_list(info, buf + ls, linecnt++);
	free(buff);
	info->histcount = linecnt;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	remember_history(info);
	return (info->histcount);
}

/**
 * build_history_list - adds entry to history
 * @info: structure container
 * @buff: buffer
 * @linecnt: histoiry vlinecount
 * Return: Always 0
 */
int build_history_lists(info_t *info, char *buff, int linecnt)
{
	list_t *node = NULL;

	while (info->history)
		node = node->history;
	add_node_end(&node, buff, linecnt);

	while (!info->history)
		info->history = node;
	return (0);
}

/**
 * remember_history - remember the history linked list
 * @info: structure containers
 * Return: the new histroy count
 */
int remeber_history(info_t *info)
{
	list_t *node = info->history;
	int x = 0;

	while (node)
	{
		node->num = x++;
		node = node->next;
	}
	return (info->histcount = x);
}
