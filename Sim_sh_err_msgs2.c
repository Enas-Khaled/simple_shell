#include "shell.h"
/**
 * Sim_sh_error_127 - to create Error_message(not_found).
 * @args: Arr_of_Args Passed.
 * Return: error message
 */
char *Sim_sh_error_127(char **args)
{
	char *Serror, *Shist_str;
	int Slen;

	Shist_str = _itoa(hist);
	if (!Shist_str)
		return (NULL);

	Slen = _strlen(name) + _strlen(Shist_str) + _strlen(args[0]) + 16;
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
	_strcat(Serror, ": not found\n");

	free(Shist_str);
	return (Serror);
}
/**
 * Sim_sh_error_126 - to create Error_message(permission_denied).
 * @args: Arr_of_Args Passed.
 * Return: error message.
 */
char *Sim_sh_error_126(char **args)
{
	char *Serror, *Shist_str;
	int Slen;

	Shist_str = _itoa(hist);
	if (!Shist_str)
		return (NULL);

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
	_strcat(Serror, ": ");
	_strcat(Serror, args[0]);
	_strcat(Serror, ": Permission denied\n");

	free(Shist_str);
	return (Serror);
}


