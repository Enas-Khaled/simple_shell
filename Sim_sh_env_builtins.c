#include "shell.h"
/**
 * Sim_sh_shellby_setenv - to change the Enviro Var to PATH.
 * @args: array_args Passed.
 * @front: 2ptrs to start of args.
 * Return: -1 on error.
 *         0 otherwise.
 */
int Sim_sh_shellby_setenv(char **args, char __attribute__((__unused__)) **front)
{
	char **Senv_var = NULL, **Snew_environ, *Snew_value;
	size_t Ssize;
	int Sindex;

	if (!args[0] || !args[1])
		return (Sim_sh_create_error(args, -1));
	/* debug point */
	Snew_value = malloc(_strlen(args[0]) + 1 + _strlen(args[1]) + 1);
	if (!Snew_value)
		return (Sim_sh_create_error(args, -1));
	_strcpy(Snew_value, args[0]);
	_strcat(Snew_value, "=");
	_strcat(Snew_value, args[1]);

	Senv_var = Sim_sh_getenv(args[0]);
	if (Senv_var)
	{
		free(*Senv_var);
		*Senv_var = Snew_value;
		return (0);
	}
	for (Ssize = 0; environ[Ssize]; Ssize++)
		;

	Snew_environ = malloc(sizeof(char *) * (Ssize + 2));
	if (!Snew_environ)
	{
		free(Snew_value);
		return (Sim_sh_create_error(args, -1));
	}

	for (Sindex = 0; environ[Sindex]; Sindex++)
		Snew_environ[Sindex] = environ[Sindex];

	free(environ);
	environ = Snew_environ;
	environ[Sindex] = Snew_value;
	environ[Sindex + 1] = NULL;

	return (0);
}

/**
 * Sim_sh_shellby_env - to print Current Enviro.
 * @args: arr_of_args Passed.
 * @front: 2ptrs to start of args.
 *
 * Return: -1 on error
 *	       0 otherwise.
 */
int Sim_sh_shellby_env(char **args, char __attribute__((__unused__)) **front)
{
	int Sindex;
	char Snc = '\n';

	if (!environ)
		return (-1);

	for (Sindex = 0; environ[Sindex]; Sindex++)
	{
		write(STDOUT_FILENO, environ[Sindex], _strlen(environ[Sindex]));
		write(STDOUT_FILENO, &Snc, 1);
	}

	(void)args;
	return (0);
}

/**
 * Sim_sh_shellby_unsetenv - to delete Enviro_var from PATH.
 * @args: arr_of_args Passed.
 * @front: 2ptr to start of args.
 * Return: -1 on error.
 *         0 otherwise.
 */
int Sim_sh_shellby_unsetenv(char **args, char __attribute__((__unused__)) **front)
{
	char **Senv_var, **Snew_environ;
	size_t Ssize;
	int Sindex, Sindex2;

	if (!args[0])
		return (Sim_sh_create_error(args, -1));
	Senv_var = Sim_sh_getenv(args[0]);
	if (!Senv_var)
		return (0);

	for (Ssize = 0; environ[Ssize]; Ssize++)
		;

	Snew_environ = malloc(sizeof(char *) * Ssize);
	if (!Snew_environ)
		return (Sim_sh_create_error(args, -1));

	for (Sindex = 0, Sindex2 = 0; environ[Sindex]; Sindex++)
	{
		if (*Senv_var == environ[Sindex])
		{
			free(*Senv_var);
			continue;
		}
		Snew_environ[Sindex2] = environ[Sindex];
		Sindex2++;
	}
	free(environ);
	environ = Snew_environ;
	environ[Ssize - 1] = NULL;

	return (0);
}
