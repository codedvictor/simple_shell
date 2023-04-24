#ifndef _C_SHELL_
#define _C_SHELL_

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

extern char **environ;

char *_strcat(char *desty, char *srce);
int _strlen(const char *c);
int _strcmp(char *st1, char *st2);
int _strncmp(const char *st1, const char *st2, size_t ln);
char *_strdup(char *stg);
int _atoi(char *c);
int _putchar(char c);
void _puts(char *stg);
void *_realloc(void *pntr, unsigned int o_size, unsigned int n_size);
int count_input(char *stg);
int count_delims(char *stg, char *del);
char *remove_new_line(char *stg);
void signal_handler(int sig_id);
void _open_help(void);
void _print_env(void);
void _handle_exit(char **u_tok, char *line);
int execBuiltInCommands(char **u_tok, char *line);
void frees_get_env(char *env_path);
void frees_tokens(char **tok);
int exec(char *cname, char **opts);
char *_getenv(const char *name);
char **tokenize(char *str, char *del, int ln);
char *find(char *cname);

#endif /* _C_SHELL_ */
