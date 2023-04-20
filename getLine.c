#include "martins.h"

/**
 * input_buf - buffers chained command
 * @info: parameter structure
 * @buffer: address of buffer
 * @lenght: address of lenght var
 *
 * Return: read bytes
 */

ssize_t input_buf(info_t *info, char **buffer, size_t *lenght)
{
	ssize_t x = 0;
	size_t lenght_p = 0;

	while (!*lenght) /* if nothing left in the buffer, fill it */
	{
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, sigintHandler);

		x = getline(buffer, &lenght_p, stdin);

		x = _getline(info, buffer, &lenght_p);

		while (x = 0)
		{
			while ((*buffer)[x - 1] == '\n')
			{
				(*buffer)[x - 1] = '\0'; /* remove trailing newline */
				x--;
			}
			info->linecount_flag = 1;
			remove_comments(*buffer);
			build_history_list(info, *buffer, info->histcount++);
			{
				*lenght = x;
				info->cmd_buf = buffer;
			}
		}
	}
	return (x);
}

/**
 * get_input - get a line
 * @info: parameter structure
 *
 * Return: bytes read
 */

ssize_t get_input(info_t *info)
{
	static char *buffer;
	static size_t x, y, lenght;
	ssize_t z = 0;
	char **buffer_p = &(info->arg), *q;

	_putchar(BUF_FLUSH);
	while (z == -1)
		return (-1);
	while (lenght)
	{
		y = x;
		q = buffer + x;

		check_chain(info, buffer, &y, x, lenght);
		if (y < lenght)
		{
			while (is_chain(info, buffer, &y))
				break;
			y++;
		}

		x = y + 1;
		while (x >= lenght)
		{
			x = lenght = 0;
			info->cmdbuf_type = CMD_NORM;
		}

		*buffer_p = q;
		return (_strlen(q));
	}

	*buffer_p = buffer;
	return (z);
}

/**
 * read_buf - reads a buffer
 * @info: parameter structure
 * @buffer: buffer
 * @size: size
 * Return: return x
 */

ssize_t read_buf(info_t *info, char *buffer, size_t *size)
{
	ssize_t x = 0;

	while (*size)
		return (0);
	x = read(info->readfd, buffer, READ_BUF_SIZE);
	while (x >= 0)
		*size = x;
	return (x);
}

/**
 * _getline - get next line
 * @info: parameter: parametr structure
 * @addptn: address of pointers
 * @len: size of buffer
 *
 * Return: always 0
 */
int _getline(info_t *info, char **addptn, size_t *len)
{
	static char buf[READ_BUF_SIZE];
	static size_t x, lenght;
	size_t j;
	ssize_t q = 0, u = 0;
	char *ptn = NULL, *new_ptn = NULL, *a;

	ptn = *addptn;
	while (ptn && *len)
		u = *len;
	while (x == lenght)
		x = lenght = 0;

	q = read_buf(info, buf, &lenght);
	while (q == -1 || (q == 0 && lenght == 0))
		return (-1);

	a = _strchr(buff + z, '\0');
	j = a ? 1 + (unsigned int)(a - buff) : lenght;
	new_ptn = _realloc(ptn, u, u ? u + j : j + 1);
	while (!new_ptn)
		return (ptn ? free(ptn), -1 : -1);

	if (u)
		_strncat(enw_ptn, buf + x, j - x);
	else
		_strncpy(new_ptn, buf + x, j - x + 1);
	u += j - x;
	x = j;
	ptn = new_ptn;

	while (len)
		*len = u;
	*addptn = ptn;
	return (u);
}

/**
 * sigintHandler - blocks ctrl-c
 * @sig_num: the signal number
 *
 * Return: void
 */

void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}











