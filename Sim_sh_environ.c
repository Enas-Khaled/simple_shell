#include "shell.h"

/**
 * Sim_sh_free_env - to free Enviro_copy.
 * Return: void
 */
void Sim_sh_free_env(void)
{
	int Sindex;

	for (Sindex = 0; environ[Sindex]; Sindex++)
		free(environ[Sindex]);
	free(environ);
}

/**
 * Sim_sh_copyenv - to create copy Of Enviro.
 *
 * Return: NULL on error.
 *         or 2ptrs to new_copy.
 */
char **Sim_sh_copyenv(void)
{
	char **Snew_environ;
	size_t Ssize;
	int Sindex;

	for (Ssize = 0; environ[Ssize]; Ssize++)
		;

	Snew_environ = malloc(sizeof(char *) * (Ssize + 1));
	if (!Snew_environ)
		return (NULL);

	for (Sindex = 0; environ[Sindex]; Sindex++)
	{
		Snew_environ[Sindex] = malloc(_strlen(environ[Sindex]) + 1);

		if (!Snew_environ[Sindex])
		{
			for (Sindex--; Sindex >= 0; Sindex--)
				free(Snew_environ[Sindex]);
			free(Snew_environ);
			return (NULL);
		}
		_strcpy(Snew_environ[Sindex], environ[Sindex]);
	}
	Snew_environ[Sindex] = NULL;

	return (Snew_environ);
}

/**
 * Sim_sh_getenv - to get enviro_var from PATH.
 * @var: Name of Enviro_var.
 *
 * Return: NULL if not_exist.
 *         or ptr to Enviro_var.
 */
char **Sim_sh_getenv(const char *var)
{
	int Sindex, Slen;

	Slen = _strlen(var);
	for (Sindex = 0; environ[Sindex]; Sindex++)
	{
		if (_strncmp(var, environ[Sindex], Slen) == 0)
			return (&environ[Sindex]);
	}

	return (NULL);
}
