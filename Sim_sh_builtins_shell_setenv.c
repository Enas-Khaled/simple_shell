#include "shell.h"

/**
 * set_env_var - Set the value of an environment variable.
 * @nom: Name of the environment variable.
 * @val: Value of the environment variable.
 *
 * This function sets the value of an environment variable.
 *
 * Return: 0 on success, -1 on failure.
 */
int set_env_var(const char *nom, const char *val)
{
	if (setenv(nom, val, 1) != 0)
	{
		Sim_sh_puterror("setenv");
		return (-1);
	}
	return (0);
}

/**
 * Sim_sh_shell_setenv - Set the value of an environment variable.
 * @args: Arguments (name and value of the environment variable).
 *
 * Return: 0 on success, -1 on failure.
 */
int Sim_sh_shell_setenv(char **args)
{
	char *nom, *val;

	if (args[1] == NULL || args[2] == NULL)
	{
		Sim_sh_puterror("Usage: setenv NOM VAL\n");
		return (-1);
	}
	nom = args[1];
	val = args[2];

	return (set_env_var(nom, val));
}

/**
 * Sim_sh_shell_unsetenv - Unset an environment variable.
 * @args: Arguments (name of the environment variable).
 *
 * This function unsets an environment variable
 * using the name provided as an argument.
 *
 * Return: 0 on success, -1 on failure.
 */

int Sim_sh_shell_unsetenv(char **args)
{
	if (args[1] == NULL)
	{
		Sim_sh_puterror("Usage: unsetenv NAME\n");
		return (-1);
	}
	if (unsetenv(args[1]) != 0)
	{
		Sim_sh_puterror("unsetenv");
		return (-1);
	}
	return (0);
}
