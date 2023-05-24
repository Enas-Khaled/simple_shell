#include "shell.h"

/**
 * Sim_sh_get_path - To return val of a PATH env_var.
 *
 * Return: ptr to $PATH.
 */
char *Sim_sh_get_path(void)
{
	return (Sim_sh_getenv("PATH"));
}
