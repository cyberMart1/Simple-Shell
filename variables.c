#include "martins.h"

/**
 * is_chain - test if current char
 * @info: the parameter
 * @buff: the char biffer
 * @pst: address position
 * Return: return 1
 */
int is_chain(info_t *info, char *buff, size_t *pst)
{
	size_t a = *pst;

	if (buff[a] == '|' && buff[a + 1] == '|')
	{
		buff[a] = 0;
		a++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buff[a] == '&' && buff[a + 1] == '&')
	{
		buff[a] = 0;
                a++;
                info->cmd_buf_type = CMD_AND;
	}
	else if (buff[a] == ';')
	{
		buff[a] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*pst = a;
	return (1);
}

/**
 * check_chain - check we should continue or not
 * @info: the parameter structure
 * @buff: the char buffer
 * @pst: address of currrent position
 * @init: the starting point 
 * @lenght: lenght of the buff
 *
 * Return: void;
 */
void check_chain(info_t *info, char *buff, size_t *pst, size_t init, size_t lenght)
{
	size_t a = *pst;

	if (info->cmd_buf_type == CMD_AND)
	{
		while (info->status)
		{
			buff[x] = 0;
			a = lenght;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buff[x] = 0;
			a = lenght;
		}
	}
	*pst = a;
}

/**
 * replace_alias - replace the alias in the token
 * @info: the parameter
 *
 * Return: return 1
 */
int replace_alias(info_t *info)
{
	int x;
	list_t *node;
	char *pst;

	for (x = 0; x < 10; x++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		pst = _strchr(node->str, '=');
		if (!pst)
			return (0);
		pst = _strdup(pst + 1);
		if (!pst)
			 return (0);
		info->argv[0] = p;
	}
	return (1);
}
