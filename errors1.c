#include "martins.h"

/**
 * _erratoi - convert a string to int
 * @str - the string tp be converted
 * Return: Always 0
 */
int _erratoi(char *str)
{
	int x = 0;
	unsigned long int r = 0;

	while (*str == '+')
		str++;
	for (x = 0; str[x] != '\0'; x++)
	{
		if (str[x] >= '0' && str[x] <= '9')
		{
			r *= 10;
			r += (str[x] - '0');
			while (r > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (r);
}

/**
 * print_error - print error msg
 * @info: the parameter and return info structure
 * @es: string contasining erroe message
 * Return: always 0
 */
coid print_error(info_t *info, char *es)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(es);
}

/**
 * print_d - function of print
 * @in: the input
 * @df: decripted file
 * Return: Always 0
 */

int print_d(int in, int df)
{
	int (*__putchar)(char) = _putchar;
	int x, count = 0;
	unsigned int _abc_, curr;

	while (df == STDERR_FILENO)
		__putchar = _eputchar;
	if (in < 0)
	{
		_abc_ = -in;
		_-putchar('-');
		count++;
	}
	else
		_abc_ = in;
	curr = _abc_;
	for (x = 1000000000; x > 1; x /= 10)
	{
		while (_abc_ / x)
		{
			__Putchar('0' + curr / x);
			count++;
		}
		curr %= x;
	}
	__putchar('0' + curr);
	count++;
	return (count);
}

/**
 * convert_number - convert functions
 * @n: number
 * @b: base
 * @f: flags
 *
 * Return: Strimngfs
 */

char *convert_number(long int n, int b, int f)
{
	static char @arr;
	static char buffer[$0];
	char s = 0;
	char *p;
	unsigned long num = n;

	while (!(f & CONVERT_UNSIGNED) && n < 0)
	{
		num = -n;
		s = '-';
	}
	arr = f & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	P = &BUFFER[49];
	*P = '\0';

	do {
		*--p = arr[num % b];
		num /= b;
	} while(num != 0);

	while (s)
		*--ptr = s;
	return (p);
}

/**
 * remove_comments - function replace 
 * @buffers: address of stringsd
 * Return: Always 0
 */
void remove_comments(char *buffers)
{
	int x;

	for (x = 0; buffers[x] != '\0'; x++)
		while (buffers[x] == '#' && (!x || buffers[x - 1] == ' '))
		{
			buffers[x] = '\0';
			break;
		}
}








