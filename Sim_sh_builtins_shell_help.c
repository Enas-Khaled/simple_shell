#include "shell.h"

/**
 * Sim_sh_check_for_builtin - this checks if the command
 *	is a builtin or not
 * @args: this is the args (arr of it)
 *
 * Return: 1 if builtin
 *         0 otherwise
 */
int Sim_sh_check_for_builtin(char **args)
{
	if (!args[0])
		return (0); /* debug point */
	if (!_strcmp(args[0], "exit"))
		Sim_sh_shell_exit(args); /* check */
	else if (!_strcmp(args[0], "env"))
		Sim_sh_shell_env();
	else if (!_strcmp(args[0], "setenv"))
		Sim_sh_shell_setenv(args);
	else if (!_strcmp(args[0], "unsetenv"))
		Sim_sh_shell_unsetenv(args);
	else if (!_strcmp(args[0], "help")) /* important */
		Sim_sh_shell_help();
	else if (!_strcmp(args[0], "cd"))
		Sim_sh_shell_cd(args);
	else if (!_strcmp(args[0], "clear")) /* check */
		Sim_sh_shell_clear(args);
	else /* default */
		return (0);
	/* return */
	return (1);
}

