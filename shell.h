#ifndef _SHELL_H_
#define _SHELL_H_
/* GNU */
#define _GNU_SOURCE

#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>

/*macros*/
#define MAX_TOKENS 1024
#define BUFFER_SIZE 1024
#define PATH_MAX_LENGTH 4096
#define PATH_SEPARATOR ":"
#define PROMPT "$ "

/* free */
void Sim_sh_free_last_input(void);
/* Sim_sh_get_line.c*/
void *Sim_sh_get_line(void);
/* Sim_sh_prompt.c */
void Sim_sh_prompt(void);

/* Sim_sh_get_input.c */
char *Sim_sh_get_input(void);
/* Sim_sh_print */
void Sim_sh_print_help_info(void);
void Sim_sh_print_shell_info(void);
int Sim_sh_set_env_var(const char *name, const char *value);
/* Sim_sh_built-in funcs */
int Sim_sh_shell_setenv(char **args);
int Sim_sh_shell_unsetenv(char **args);
int Sim_sh_shell_env(void);
int Sim_sh_shell_clear(char **args);
int Sim_sh_check_for_builtin(char **args);
int Sim_sh_execute_buitlin(char *cmd, char **args);
void Sim_sh_shell_help(void);
void Sim_sh_shell_exit(char **args);
void Sim_sh_shell_cd(char **args);

/* Sim_sh_signal_handler.c */
void Sim_sh_handle_sigstp(int sig);
void Sim_sh_handle_sigint(int sig);
void Sim_sh_handle_sigquit(int sig);

/* Sim_sh_execute.c */
int Sim_sh_execute(char **args);

/* Sim_sh_parser.c */
char **Sim_sh_tokenize(char *str, const char *delim);
char **Sim_sh_tokenize_input(char *input);

/* Sim_sh_get_env.c */
char *Sim_sh_getenv(const char *name);

/* Sim_sh_get_path.c */
char *Sim_sh_get_path(void);

/* Sim_sh_find_in_path.c */
char *Sim_sh_find_in_path(char *command);

/* Sim_sh_free.c */
void Sim_sh_free_path(void);
void Sim_sh_free_error(char **argv, char *arg);
void Sim_sh_free_tokens(char **ptr);


/* Sim_sh_error.c */
void Sim_sh_puts(char *str);
void Sim_sh_puterror(char *err);

/* Sim_sh_utils_funcs1.c */
int _strlen(const char *);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
/* Sim_sh_utils_funcs1.c */
char *_strstr(char *haystack, char *needle);
char *_strchr(char *s, char c);

/* Sim_sh_utils_funcs2.c */
char *_strcpy(char *, char *);
int _putchar(char);
unsigned int _strspn(char *s, char *accept);
char *_strcat(char *, const char *);
char *_strdup(const char *);


/* Sim_sh_utils_funcs3.c */
void *_realloc(void *, unsigned int, unsigned int);
void *_calloc(unsigned int nmemb, unsigned int size);
int _atoi(const char *str);
char *_memset(char *, char, unsigned int);
char *_memcpy(char *dest, char *src, unsigned int n);

#endif
