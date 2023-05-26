#include "shell.h"

/**
 * Sim_sh_get_args - Sim_sh_get_args
 * @line: line
 * @exe_ret: exe_ret
 *
 * Return: NULL. or ptr otherwise
 */
char *Sim_sh_get_args(char *line, int *exe_ret)
{
	size_t Sn = 0;
	ssize_t Sread;
	char *Sprompt = "$ ";

	if (line)
		free(line);

	Sread = _getline(&line, &Sn, STDIN_FILENO);
	if (Sread == -1)
		return (NULL);
	if (Sread == 1)
	{
		hist++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, Sprompt, 2);
		return (Sim_sh_get_args(line, exe_ret));
	}

	line[Sread - 1] = '\0';
	Sim_sh_variable_replacement(&line, exe_ret);
	Sim_sh_handle_line(&line, Sread);

	return (line);
}

/**
 * Sim_sh_call_args - Sim_sh_call_args
 * @args: args
 * @front: front
 * @exe_ret: exe_ret
 *
 * Return: Return
 */
int Sim_sh_call_args(char **args, char **front, int *exe_ret)
{
	int Sret, Sindex;

	if (!args[0])
		return (*exe_ret);
	for (Sindex = 0; args[Sindex]; Sindex++)
	{
		if (_strncmp(args[Sindex], "||", 2) == 0)
		{
			free(args[Sindex]);
			args[Sindex] = NULL;
			args = Sim_sh_replace_aliases(args);
			Sret = Sim_sh_run_args(args, front, exe_ret);
			if (*exe_ret != 0)
			{
				args = &args[++Sindex];
				Sindex = 0;
			}
			else
			{
				for (Sindex++; args[Sindex]; Sindex++)
					free(args[Sindex]);
				return (Sret);
			}
		}
		else if (_strncmp(args[Sindex], "&&", 2) == 0)
		{
			free(args[Sindex]);
			args[Sindex] = NULL;
			args = Sim_sh_replace_aliases(args);
			Sret = Sim_sh_run_args(args, front, exe_ret);
			if (*exe_ret == 0)
			{
				args = &args[++Sindex];
				Sindex = 0;
			}
			else
			{
				for (Sindex++; args[Sindex]; Sindex++)
					free(args[Sindex]);
				return (Sret);
			}
		}
	}
	args = Sim_sh_replace_aliases(args);
	Sret = Sim_sh_run_args(args, front, exe_ret);
	return (Sret);
}

/**
 * Sim_sh_run_args - Sim_sh_run_args
 * @args: args
 * @front: front
 * @exe_ret: exe_ret
 *
 * Return: last exec command
 */
int Sim_sh_run_args(char **args, char **front, int *exe_ret)
{
	int Sret, Si;
	int (*builtin)(char **args, char **front);

	builtin = Sim_sh_get_builtin(args[0]);

	if (builtin)
	{
		Sret = builtin(args + 1, front);
		if (Sret != EXIT)
			*exe_ret = Sret;
	}
	else
	{
		*exe_ret = Sim_sh_execute(args, front);
		Sret = *exe_ret;
	}

	hist++;

	for (Si = 0; args[Si]; Si++)
		free(args[Si]);

	return (Sret);
}

/**
 * Sim_sh_handle_args - Sim_sh_handle_args.
 * @exe_ret: exe_ret.
 *
 * Return: -2 or -1
 */
int Sim_sh_handle_args(int *exe_ret)
{
	int Sret = 0, Sindex;
	char **Sargs, *Sline = NULL, **Sfront;

	Sline = Sim_sh_get_args(Sline, exe_ret);
	if (!Sline)
		return (END_OF_FILE);

	Sargs = _strtok(Sline, " ");
	free(Sline);
	if (!Sargs)
		return (Sret);
	if (Sim_sh_check_args(Sargs) != 0)
	{
		*exe_ret = 2;
		Sim_sh_free_args(Sargs, Sargs);
		return (*exe_ret);
	}
	Sfront = Sargs;

	for (Sindex = 0; Sargs[Sindex]; Sindex++)
	{
		if (_strncmp(Sargs[Sindex], ";", 1) == 0)
		{
			free(Sargs[Sindex]);
			Sargs[Sindex] = NULL;
			Sret = Sim_sh_call_args(Sargs, Sfront, exe_ret);
			Sargs = &Sargs[++Sindex];
			Sindex = 0;
		}
	}
	if (Sargs)
		Sret = Sim_sh_call_args(Sargs, Sfront, exe_ret);

	free(Sfront);
	return (Sret);
}

/**
 * Sim_sh_check_args - Sim_sh_check_args
 * @args: 2ptr to args
 *
 * Return: - 2 or 0.
 */
int Sim_sh_check_args(char **args)
{
	size_t Si;
	char *Scur, *Snex;

	for (Si = 0; args[Si]; Si++)
	{
		Scur = args[Si];
		if (Scur[0] == ';' || Scur[0] == '&' || Scur[0] == '|')
		{
			if (Si == 0 || Scur[1] == ';')
				return (Sim_sh_create_error(&args[Si], 2));
			Snex = args[Si + 1];
			if (Snex && (Snex[0] == ';' || Snex[0] == '&' || Snex[0] == '|'))
				return (Sim_sh_create_error(&args[Si + 1], 2));
		}
	}
	return (0);
}
