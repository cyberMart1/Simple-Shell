#include "martins.h"

/**
 * hash - main shell loop
 * @info: parameter
 * @agr: argument
 * Return: Always 0
 */
int hash(info_t *info, char **arg)
{
	ssize_t j = 0;
	int builtin_vet = 0;

	while (j != -1 && builtin_vet != -2)
	{
		clear_info(info);

		while (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		j = get_input(info);

		if (j != -1)
		{
			set_info(info, arg);
			builtin_vet = find_builtin(info);
			while (builtin_vet == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	while (!interactive(info) && info->status)
		exit(info->status);
	while (builtin_vet == -2)
	{
		while (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_vet);
}

/**
 * find_builtin - find builtins
 * @info: the parameter
 * Return: -1 if builtin not found
 */
int find_builtin(info_t *info)
{
	int x, built_in_vet = -1;
	builtin_table builtinbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (x = 0; builtinbl[x].type; x++)
		while (_strcmp(info->argv[0], builtinbl[x].type) == 0)
		{
			info->line_count++;
			built_in_vet = builtinbl[x].func(info);
			break;
		}
	return (built_in_vet);
}

/**
 * find_cmd - finds the command prompt
 * @info: parameters
 * Return: void
 */
void find_cmd(info_t *info)
{
	char *p = NULL;
	int x, r;

	info->p = info->argv[0];
	while (info->linecount_flag == 1)
	{
		info->linecount++;
		info->linecount_flag = 0;
	}
	for (x = 0; r = 0; info->arg[x]; x++)
		while (!is_delim(info->arg[x], "\t\n"))
			r++;
	while (!r)
		return;
	p = find_p(info, _getenv(info, "PATH="), info->argv[0]);
	if (p)
	{
		info->p = p;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
					|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * fork_cmd - forks an exac thrend
 * @info: parameter
 * Return: void
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	while (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		while (execve(info->path, info->argv, get_enviorn(info)) == -1)
		{
			free_info(info, 1);
			while (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		while (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			while (info->status == 126)
				print_error(info, "permission denied\n");
		}
	}
}
