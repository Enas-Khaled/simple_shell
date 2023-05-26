#include "shell.h"

/**
 * Sim_sh_shellby_help - to displays info of builtin_commands.
 * @args: arr_args.
 * @front: ptr to start of args.
 * Return: -1 on error.
 *          0 otherwise.
 */
int Sim_sh_shellby_help(char **args, char __attribute__((__unused__)) **front)
{
	if (!args[0])
		Sim_sh_help_all();
	else if (_strcmp(args[0], "alias") == 0)
		Sim_sh_help_alias();
	else if (_strcmp(args[0], "cd") == 0)
		Sim_sh_help_cd();
	else if (_strcmp(args[0], "exit") == 0)
		Sim_sh_help_exit();
	else if (_strcmp(args[0], "env") == 0)
		Sim_sh_help_env();
	else if (_strcmp(args[0], "setenv") == 0)
		Sim_sh_help_setenv();
	else if (_strcmp(args[0], "unsetenv") == 0)
		Sim_sh_help_unsetenv();
	else if (_strcmp(args[0], "help") == 0)
		Sim_sh_help_help();
	else
		write(STDERR_FILENO, name, _strlen(name));

	return (0);
}
/**
 * Sim_sh_get_builtin - to matche command builtin_fun.
 * @command: Command.
 * Return: fun_ptr to builtin_fun.
 */
int (*Sim_sh_get_builtin(char *command))(char **args, char **front)
{
	builtin_t Sfuncs[] = {
		{ "exit", Sim_sh_shellby_exit },
		{ "env", Sim_sh_shellby_env },
		{ "setenv", Sim_sh_shellby_setenv },
		{ "unsetenv", Sim_sh_shellby_unsetenv },
		{ "cd", Sim_sh_shellby_cd },
		{ "alias", Sim_sh_shellby_alias },
		{ "help", Sim_sh_shellby_help },
		{ NULL, NULL }
	};
	int a;

	for (a = 0; Sfuncs[a].name; a++)
	{
		if (_strcmp(Sfuncs[a].name, command) == 0)
			break;
	}
	return (Sfuncs[a].f);
}

/**
 * Sim_sh_shellby_exit - To terminat the process
 * @args: args of exit Values.
 * @front: 2ptr to the start of args.
 * Return: -3 no arguments.
 *         -2 invalid value.
 *         exits otherwise.
 */
int Sim_sh_shellby_exit(char **args, char **front)
{
	int a, Slen_of_int = 10;
	unsigned int Snum = 0, Smax = 1 << (sizeof(int) * 8 - 1);

	if (args[0])
	{
		if (args[0][0] == '+')
		{
			a = 1;
			Slen_of_int++;
		}
		for (; args[0][a]; a++)
		{
			if (a <= Slen_of_int && args[0][a] >= '0' && args[0][a] <= '9')
				Snum = (Snum * 10) + (args[0][a] - '0');
			else
				return (Sim_sh_create_error(--args, 2));
		}
	}
	else
	{
		return (-3);
	}
	if (Snum > Smax - 1)
		return (Sim_sh_create_error(--args, 2));
	args -= 1;
	Sim_sh_free_args(args, front);
	Sim_sh_free_env();
	Sim_sh_free_alias_list(aliases);
	exit(Snum);
}

/**
 * Sim_sh_shellby_cd - to change directory.
 * @args: arr_of_args.
 * @front: 2ptrs to start of args.
 *
 * Return: -2 if not Directory.
 *         -1 on error.
 *         0 otherwise.
 */
int Sim_sh_shellby_cd(char **args, char __attribute__((__unused__)) **front)
{
	struct stat dir;
	char **Sdir_info, *Snew_line = "\n";
	char *Soldpwd = NULL, *Spwd = NULL;

	Soldpwd = getcwd(Soldpwd, 0);
	if (!Soldpwd)
		return (-1);

	if (args[0])
	{
		if (*(args[0]) == '-' || _strcmp(args[0], "--") == 0)
		{
			if ((args[0][1] == '-' && args[0][2] == '\0') ||
					args[0][1] == '\0')
			{
				if (Sim_sh_getenv("OLDPWD") != NULL)
					(chdir(*Sim_sh_getenv("OLDPWD") + 7));
			}
			else
			{
				free(Soldpwd);
				return (Sim_sh_create_error(args, 2));
			}
		}
		else
		{
			if (stat(args[0], &dir) == 0 && S_ISDIR(dir.st_mode)
					&& ((dir.st_mode & S_IXUSR) != 0))
				chdir(args[0]);
			else
			{
				free(Soldpwd);
				return (Sim_sh_create_error(args, 2));
			}
		}
	}
	else
	{
		if (Sim_sh_getenv("HOME") != NULL)
			chdir(*(Sim_sh_getenv("HOME")) + 5);
	}

	Spwd = getcwd(Spwd, 0);
	if (!Spwd)
		return (-1);

	Sdir_info = malloc(sizeof(char *) * 2);
	if (!Sdir_info)
		return (-1);

	Sdir_info[0] = "OLDPWD";
	Sdir_info[1] = Soldpwd;
	if (Sim_sh_shellby_setenv(Sdir_info, Sdir_info) == -1)
		return (-1);

	Sdir_info[0] = "PWD";
	Sdir_info[1] = Spwd;
	if (Sim_sh_shellby_setenv(Sdir_info, Sdir_info) == -1)
		return (-1);
	if (args[0] && args[0][0] == '-' && args[0][1] != '-')
	{
		write(STDOUT_FILENO, Spwd, _strlen(Spwd));
		write(STDOUT_FILENO, Snew_line, 1);
	}
	free(Soldpwd);
	free(Spwd);
	free(Sdir_info);
	return (0);
}
