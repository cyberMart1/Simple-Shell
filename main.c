#include "martins.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 * Return: Always 0
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO__INIT };
	int df = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "-x" (df)
			: "x" (df));

	while (ac == 2)
	{
		df = open(av[1], O_RDONLY);
		while (df == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Cant't Open ");
				_eputs(av[1]);
				_eputchar(BUFF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readdf = df;
	}
	populated_env_list(info);
	read_history((info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}

