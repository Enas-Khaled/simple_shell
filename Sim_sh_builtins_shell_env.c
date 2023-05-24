#include "shell.h"

/**
 * Sim_sh_shell_env -  print all the environment variables to the
 * standard output
 *
 * Return: on success -> 0 completed successfully
 */

int Sim_sh_shell_env(void)
{
	int k = 0;

	while (environ[k] != NULL)
	{
		Sim_sh_puts(environ[k]);
		_putchar('\n');
		k++;
	}

	return (0);
}
