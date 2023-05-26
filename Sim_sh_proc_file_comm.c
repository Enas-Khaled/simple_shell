#include "shell.h"

/**
 * Sim_sh_cant_open - Sim_sh_cant_open
 * @file_path: file_path
 *
 * Return: 127.
 */

int Sim_sh_cant_open(char *file_path)
{
	char *Serror, *Shist_str;
	int Slen;

	Shist_str = _itoa(hist);
	if (!Shist_str)
		return (127);

	Slen = _strlen(name) + _strlen(Shist_str) + _strlen(file_path) + 16;
	Serror = malloc(sizeof(char) * (Slen + 1));
	if (!Serror)
	{
		free(Shist_str);
		return (127);
	}

	_strcpy(Serror, name);
	_strcat(Serror, ": ");
	_strcat(Serror, Shist_str);
	_strcat(Serror, ": Can't open ");
	_strcat(Serror, file_path);
	_strcat(Serror, "\n");

	free(Shist_str);
	write(STDERR_FILENO, Serror, Slen);
	free(Serror);
	return (127);
}

/**
 * Sim_sh_proc_file_commands - Sim_sh_proc_file_commands
 * @file_path: file_path
 * @exe_ret: exe_ret
 *
 * Return: 127
 */
int Sim_sh_proc_file_commands(char *file_path, int *exe_ret)
{
	ssize_t Sfile, Sb_read, Si;
	unsigned int Sline_size = 0;
	unsigned int Sold_size = 120;
	char *Sline, **Sargs, **Sfront;
	char Sbuffer[120];
	int Sret;

	hist = 0;
	Sfile = open(file_path, O_RDONLY);
	if (Sfile == -1)
	{
		*exe_ret = Sim_sh_cant_open(file_path);
		return (*exe_ret);
	}
	Sline = malloc(sizeof(char) * Sold_size);
	if (!Sline)
		return (-1);
	do {
		Sb_read = read(Sfile, Sbuffer, 119);
		if (Sb_read == 0 && Sline_size == 0)
			return (*exe_ret);
		Sbuffer[Sb_read] = '\0';
		Sline_size += Sb_read;
		Sline = _realloc(Sline, Sold_size, Sline_size);
		_strcat(Sline, Sbuffer);
		Sold_size = Sline_size;
	} while (Sb_read);
	for (Si = 0; Sline[Si] == '\n'; Si++)
		Sline[Si] = ' ';
	for (; Si < Sline_size; Si++)
	{
		if (Sline[Si] == '\n')
		{
			Sline[Si] = ';';
			for (Si += 1; Si < Sline_size && Sline[Si] == '\n'; Si++)
				Sline[Si] = ' ';
		}
	}
	Sim_sh_variable_replacement(&Sline, exe_ret);
	Sim_sh_handle_line(&Sline, Sline_size);
	Sargs = _strtok(Sline, " ");
	free(Sline);
	if (!Sargs)
		return (0);
	if (Sim_sh_check_args(Sargs) != 0)
	{
		*exe_ret = 2;
		Sim_sh_free_args(Sargs, Sargs);
		return (*exe_ret);
	}
	Sfront = Sargs;

	for (Si = 0; Sargs[Si]; Si++)
	{
		if (_strncmp(Sargs[Si], ";", 1) == 0)
		{
			free(Sargs[Si]);
			Sargs[Si] = NULL;
			Sret = Sim_sh_call_args(Sargs, Sfront, exe_ret);
			Sargs = &Sargs[++Si];
			Si = 0;
		}
	}

	Sret = Sim_sh_call_args(Sargs, Sfront, exe_ret);

	free(Sfront);
	return (Sret);
}
