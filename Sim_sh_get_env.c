#include "shell.h"

/**
 * Sim_sh_getenv - Know a value of envir var
 * @name: env_vars
 *
 * Return:  ptr to val of env vars,
 *          NULL if failure
 */

char *Sim_sh_getenv(const char *name)
{
	char **my_envp = environ;
	size_t name_length = _strlen(name);
	char *env_var = NULL;

	while (*my_envp != NULL)
	{
		if (_strncmp(*my_envp, name, name_length) == 0)
		{
			if ((*my_envp)[name_length] == '=')
				env_var = &((*my_envp)[name_length + 1]);
			break;
		}

		my_envp++;
	}
	/* value of the environment variable if it was found*/
	return (env_var);
}
