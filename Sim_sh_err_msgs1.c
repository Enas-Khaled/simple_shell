#include "shell.h"

/**
 * Sim_sh_error_2_cd - to create Error_message (cd).
 * @args: Arr_of_args Passed.
 * Return: Error message.
 */
char *Sim_sh_error_2_cd(char **args)
{
	char *Serror, *Shist_str;
	int Slen;

	Shist_str = _itoa(hist);
	if (!Shist_str)
		return (NULL);

	if (args[0][0] == '-')
		args[0][2] = '\0';
	Slen = _strlen(name) + _strlen(Shist_str) + _strlen(args[0]) + 24;
	Serror = malloc(sizeof(char) * (Slen + 1));
	if (!Serror)
	{
		free(Shist_str);
		return (NULL);
	}

	_strcpy(Serror, name);
	_strcat(Serror, ": ");
	_strcat(Serror, Shist_str);
	if (args[0][0] == '-')
		_strcat(Serror, ": cd: Illegal option ");
	else
		_strcat(Serror, ": cd: can't cd to ");
	_strcat(Serror, args[0]);
	_strcat(Serror, "\n");

	free(Shist_str);
	return (Serror);
}

/**
 * Sim_sh_error_env - to create Error_message.
 * @args: Arr_of_args Passed.
 * Return: Error message.
 */
char *Sim_sh_error_env(char **args)
{
	char *Serror, *Shist_str;
	int Slen;

	Shist_str = _itoa(hist);
	if (!Shist_str)
		return (NULL);

	args--;
	Slen = _strlen(name) + _strlen(Shist_str) + _strlen(args[0]) + 45;
	Serror = malloc(sizeof(char) * (Slen + 1));
	if (!Serror)
	{
		free(Shist_str);
		return (NULL);
	}

	_strcpy(Serror, name);
	_strcat(Serror, ": ");
	_strcat(Serror, Shist_str);
	_strcat(Serror, ": ");
	_strcat(Serror, args[0]);
	_strcat(Serror, ": Unable to add/remove from environment\n");

	free(Shist_str);
	return (Serror);
}

/**
 * Sim_sh_error_1 - to create Error_message (alias).
 * @args: Arr_of_args Passed.
 * Return: Error message.
 */
char *Sim_sh_error_1(char **args)
{
	char *Serror;
	int Slen;

	Slen = _strlen(name) + _strlen(args[0]) + 13;
	Serror = malloc(sizeof(char) * (Slen + 1));
	if (!Serror)
		return (NULL);

	_strcpy(Serror, "alias: ");
	_strcat(Serror, args[0]);
	_strcat(Serror, " not found\n");

	return (Serror);
}

/**
 * Sim_sh_error_2_exit - to create Error_message (exit).
 * @args: Arr_of_args Passed.
 * Return: Error message.
 */
char *Sim_sh_error_2_exit(char **args)
{
	char *Serror, *Shist_str;
	int Slen;

	Shist_str = _itoa(hist);
	if (!Shist_str)
		return (NULL);

	Slen = _strlen(name) + _strlen(Shist_str) + _strlen(args[0]) + 27;
	Serror = malloc(sizeof(char) * (Slen + 1));
	if (!Serror)
	{
		free(Shist_str);
		return (NULL);
	}

	_strcpy(Serror, name);
	_strcat(Serror, ": ");
	_strcat(Serror, Shist_str);
	_strcat(Serror, ": exit: Illegal number: ");
	_strcat(Serror, args[0]);
	_strcat(Serror, "\n");

	free(Shist_str);
	return (Serror);
}

/**
 * Sim_sh_error_2_syntax - to create Error_message(syntax).
 * @args: Arr_of_args Passed.
 * Return: Error message.
 */
char *Sim_sh_error_2_syntax(char **args)
{
	char *Serror, *Shist_str;
	int Slen;

	Shist_str = _itoa(hist);
	if (!Shist_str)
		return (NULL);

	Slen = _strlen(name) + _strlen(Shist_str) + _strlen(args[0]) + 33;
	Serror = malloc(sizeof(char) * (Slen + 1));
	if (!Serror)
	{
		free(Shist_str);
		return (NULL);
	}

	_strcpy(Serror, name);
	_strcat(Serror, ": ");
	_strcat(Serror, Shist_str);
	_strcat(Serror, ": Syntax error: \"");
	_strcat(Serror, args[0]);
	_strcat(Serror, "\" unexpected\n");

	free(Shist_str);
	return (Serror);
}
