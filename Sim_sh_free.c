#include "shell.h"

/**
 * Sim_sh_free_error - this frees allocted ptrs
 *     that after sys_err
 * @argv:  this is a ptr refers to a ptr
 * to the arr of str
 * @arg:s this is a ptr refers to arr of chars.
 *
 * Return: nothing.
 */
void Sim_sh_free_error(char **argv, char *arg)
{
	int j = 0;

	while (argv[j] != NULL)
	{
		free(argv[j]);
		j++;
	}
	free(argv);
	free(arg);
	exit(EXIT_FAILURE);
}

/**
 * Sim_sh_free_tokens - this frees memory after dynamic allocated
 *
 * @ptr: this is ptr to the memory that already allocated.
 *
 * Return: its void_fun.
 */
void Sim_sh_free_tokens(char **ptr)
{
	int k = 0;

	while (ptr[k] != NULL)
	{
		free(ptr[k]);
		k++;
	}

	free(ptr);
}

/**
 * Sim_sh_free_path - this frees the variable  that contains
 *        a PATH env for var
 *
 * Return: Nothing_void
 */
void Sim_sh_free_path(void)
{
	if (environ != NULL)
	{
		size_t Sim_sh_index;

		for (Sim_sh_index = 0; environ[Sim_sh_index] != NULL; Sim_sh_index++)
		{
			if (_strncmp(environ[Sim_sh_index], "PATH=", 5) == 0)
			{
				free(environ[Sim_sh_index]);
				environ[Sim_sh_index] = NULL;
				break;
			}
		}
	}
}
