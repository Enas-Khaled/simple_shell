#ifndef _SHELL_H_
#define _SHELL_H_

/* library */
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
/* eof & exit */
#define EXIT -3
#define END_OF_FILE -2

/* Sim global var */
extern char **environ;
/* Sim global program name */
char *name;
/* Sim History_counter */
int hist;

/**
 * struct builtin_s - to define builtin_commands.
 * @name: name.
 * @f: ptr to builtin_command_fun.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(char **argv, char **front);
} builtin_t;

/**
 * struct list_s - to define linked_list.
 * @dir: PATH of dir.
 * @next: A ptr to next struct Sim_sh_list_s.
 */
typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

/**
 * struct alias_s -to define Aliases.
 * @name: name.
 * @value: val.
 * @next: A ptr to next struct Sim_sh_alias_s.
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
}alias_t;

/* Global aliases linked list */
alias_t *aliases;

/* Sim_sh_main_helpers */
list_t *Sim_sh_get_path_dir(char *path);
char *Sim_sh_fill_path_dir(char *path);
int Sim_sh_execute(char **args, char **front);
void Sim_sh_free_list(list_t *head);
char *_itoa(int num);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_strtok(char *line, char *delim);
char *Sim_sh_get_location(char *command);
int Sim_sh_num_len(int num);
int Sim_sh_token_len(char *str, char *delim);
int Sim_sh_count_tokens(char *str, char *delim);
void Sim_sh_sig_handler(int sig);
/* Sim_sh_input_helpers */
int Sim_sh_call_args(char **args, char **front, int *exe_ret);
int Sim_sh_run_args(char **args, char **front, int *exe_ret);
int Sim_sh_handle_args(int *exe_ret);
int Sim_sh_check_args(char **args);
void Sim_sh_handle_line(char **line, ssize_t read);
void Sim_sh_variable_replacement(char **args, int *exe_ret);
char *Sim_sh_get_args(char *line, int *exe_ret);
void Sim_sh_free_args(char **args, char **front);
char **Sim_sh_replace_aliases(char **args);

/* helper */

char *Sim_sh_get_args(char *line, int *exe_ret);
int Sim_sh_call_args(char **args, char **front, int *exe_ret);
int Sim_sh_run_args(char **args, char **front, int *exe_ret);
int Sim_sh_handle_args(int *exe_ret);
int Sim_sh_check_args(char **args);

/* Sim_sh_String_func */
int _strlen(const char *s);
int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, const char *src);
char *_strchr(char *s, char c);

void Sim_sh_handle_line(char **line, ssize_t read);
ssize_t Sim_sh_get_new_len(char *line);
void Sim_sh_logical_ops(char *line, ssize_t *new_len);

/* Sim_sh_builtins */
int Sim_sh_shellby_setenv(char **args, char __attribute__((__unused__)) **front);
int Sim_sh_shellby_unsetenv(char **args, char __attribute__((__unused__)) **front);
int Sim_sh_shellby_cd(char **args, char __attribute__((__unused__)) **front);
int (*Sim_sh_get_builtin(char *command))(char **args, char **front);
int Sim_sh_shellby_exit(char **args, char **front);
int Sim_sh_shellby_env(char **args, char __attribute__((__unused__)) **front);
int Sim_sh_shellby_alias(char **args, char __attribute__((__unused__)) **front);
int Sim_sh_shellby_help(char **args, char __attribute__((__unused__)) **front);
void Sim_sh_assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);

/* Sim_sh_Builtin_Helpers */
void Sim_sh_free_env(void);
char **Sim_sh_copyenv(void);
char **Sim_sh_getenv(const char *var);

/* Sim_sh_Error_Handling */
char *Sim_sh_error_2_exit(char **args);
char *Sim_sh_error_2_cd(char **args);
char *Sim_sh_error_2_syntax(char **args);
int Sim_sh_create_error(char **args, int err);
char *Sim_sh_error_env(char **args);
char *Sim_sh_error_1(char **args);
char *Sim_sh_error_126(char **args);
char *Sim_sh_error_127(char **args);

/* Sim_sh_Linkedlist_Helpers */
void Sim_sh_free_alias_list(alias_t *head);
list_t *Sim_sh_add_node_end(list_t **head, char *dir);
alias_t *Sim_sh_add_alias_end(alias_t **head, char *name, char *value);
int Sim_sh_proc_file_commands(char *file_path, int *exe_ret);
int Sim_sh_cant_open(char *file_path);
void Sim_sh_free_list(list_t *head);
void Sim_sh_help_all(void);
void Sim_sh_help_alias(void);
void Sim_sh_help_env(void);
void Sim_sh_help_setenv(void);
void Sim_sh_help_unsetenv(void);
void Sim_sh_help_history(void);
void Sim_sh_help_cd(void);
void Sim_sh_help_exit(void);
void Sim_sh_help_help(void);

void Sim_sh_free_args(char **args, char **front);
char *Sim_sh_get_pid(void);
char *Sim_sh_get_env_value(char *beginning, int len);
void Sim_sh_variable_replacement(char **args, int *exe_ret);

#endif /* _SHELL_H_ */
