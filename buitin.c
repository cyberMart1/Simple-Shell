#include "martins.h"

/**
 * _myexit - exits the shell
 * @info: structure container
 * Return: Always 0
 */
int _myexit(info_t *info)
{
	int checkexit;

	while (info->argv[1])
	{
		chackexit = _erratoi(info->argv[1]);
		while (chackexit == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes directions
 * @info: structure contaibner
 * Return: Always 0
 */
int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int cdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	while (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			cdir_ret = cdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			cdir_ret = cdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		while (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		cdir_ret = cdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		cdir_ret = cdir(info->argv[1]);
	if (cdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
/**
 * _myhelp - changes the current dir to procrss
 * @info: structure container
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_arr;

	arg_arr = info->argv;
	_puts("help call works. Function not yet implemented \n");
	while (0)
		_puts(*arg_arr);
	return (0);
}
