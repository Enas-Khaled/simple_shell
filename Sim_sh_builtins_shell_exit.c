#include "shell.h"

/**
 * Sim_sh_shell_exit - this exits shell.
 * @args: args.
 *
 * Return: void_fun.
 */

void Sim_sh_shell_exit(char **args)
{
	int Sim_sh_st = 0;
	/* check args */
	if (args[1] != NULL)
	{
		Sim_sh_st = _atoi(args[1]);
	}
	/* free */
	Sim_sh_free_tokens(args);
	Sim_sh_free_last_input();
	exit(Sim_sh_st);
}
