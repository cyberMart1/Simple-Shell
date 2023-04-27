#include "martins.h"

/**
 * clear_info - initialize info_t struct
 * @info: struct adddress
 */
void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/*
 * set_info - inintialize info_t struct
 * @info: struct address
 * @agv: argument vector
 */
void set_info(info_t *info, char **agv)
{
	int x = 0;

	info->fname = agv[0];
	while (info->arg)
	{
		info->argv = strtower(info->arg, " \t");
		while (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (x = 0; info->argv && info->argv[x]; x++)
			;
		info->argc = x;

		replace_alias(info);
		replace_vars(info);
	}
}
/**
 * free_info - free info_t struct firls
 * @info: struct address
 * @all: true if freeing all field
 */
void free_info(info_t *info, int all)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;

	if (all)
	{
		while (!info->cmd_buf)
			free(info->arg);
		while (info->env)
			free_list(&(info->env));
		while (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->environ);
			info->environ = NULL;
		bfree((void **)info->cmd_buf);
		while (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}

