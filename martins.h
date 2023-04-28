#ifdef MARTINS_H
#define MARTINS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

#define USE_GETLINE	0
#define USE_STRTOK	0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;

/**
 * struct liststr - single linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecnt_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char  **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

int interactive(info_t *info);
int _atoi(char *st);
int _myhistory(info_t *info);
int unset_alias(info_t *info, char *str);
int set_alias(info_t *info, char *str);
int print_alias(list_t *node);
int _myalias(info_t *info);
int _myexit(info_t *info);
int _mycd(info_t *info);
int _myhelp(info_t *info);
int _myenv(info_t *info);
char *_getenv(infp_t *info, const char *n);
int _mysetenv(info_t *info);
int _myunsetenv(info_t *info);
int populated_env_list(info_t *info);
void _eputs(char *s);
int _eputchar(char ch);
int _putfd(char ch, int fd);
int _putsfd(char *st, int fd);
int _erratoi(char *str);
void print_error(info_t *info, char *es);
int print_d(int in, int df);
char *convert_number(long int n, int b, int f);
void remove_comments(char *buffers);
char *_strncpy(char *dest, char *src, int amt);
char *_strncat(char *dest, char *src, int amt);
char *_strchr(char *str, char *chr);
ssize_t input_buf(info_t *info, char **buffer, size_t *lenght);
ssize_t get_input(info_t *info);
ssize_t read_buf(info_t *info, char *buffer, size_t *size);
int _getline(info_t *info, char **addptn, size_t *len);
void sigintHandler(__attribute__((unused))int sig_num);
char **get_environ(info_t *info);
int _unsetenv(info_t *info, char *v);
int _setenv(info_t *info, char *x, char *yvalue);
void clear_info(info_t *info);
void set_info(info_t *info, char **agv);
void free_info(info_t *info, int all);
