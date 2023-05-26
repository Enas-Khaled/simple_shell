#include "shell.h"

/**
 * Sim_sh_get_pid - Sim_sh_get_pid.
 * Return: P_ID or NULL.
 */
char *Sim_sh_get_pid(void)
{
	size_t a = 0;
	char *Sbuffer;
	ssize_t Sfile;

	Sfile = open("/proc/self/stat", O_RDONLY);
	if (Sfile == -1)
	{
		perror("Cant read file");
		return (NULL);
	}
	Sbuffer = malloc(120);
	if (!Sbuffer)
	{
		close(Sfile);
		return (NULL);
	}
	read(Sfile, Sbuffer, 120);
	while (Sbuffer[a] != ' ')
		a++;
	Sbuffer[a] = '\0';

	close(Sfile);
	return (Sbuffer);
}


/**
 * Sim_sh_free_args - Sim_sh_free_args.
 * @args: args.
 * @front: front.
 */
void Sim_sh_free_args(char **args, char **front)
{
	size_t a;

	for (a = 0; args[a] || args[a + 1]; a++)
		free(args[a]);

	free(front);
}

/**
 * Sim_sh_get_env_value - Sim_sh_get_env_value.
 * @beginning: Tbeginning.
 * @len: Length.
 *
 * Return: enviro_var OR empty.
 */
char *Sim_sh_get_env_value(char *beginning, int len)
{
	char **Svar_addr;
	char *Sreplacement = NULL, *Stemp, *Svar;

	Svar = malloc(len + 1);
	if (!Svar)
		return (NULL);
	Svar[0] = '\0';
	_strncat(Svar, beginning, len);

	Svar_addr = Sim_sh_getenv(Svar);
	free(Svar);
	if (Svar_addr)
	{
		Stemp = *Svar_addr;
		while (*Stemp != '=')
			Stemp++;
		Stemp++;
		Sreplacement = malloc(_strlen(Stemp) + 1);
		if (Sreplacement)
			_strcpy(Sreplacement, Stemp);
	}

	return (Sreplacement);
}

/**
 * Sim_sh_variable_replacement - Sim_sh_variable_replacement.
 * @line: line.
 * @exe_ret: exe_ret
 */
void Sim_sh_variable_replacement(char **line, int *exe_ret)
{
	int Sj, Sk = 0, Slen;
	char *Sreplacement = NULL, *Sold_line = NULL, *Snew_line;

	Sold_line = *line;
	for (Sj = 0; Sold_line[Sj]; Sj++)
	{
		if (Sold_line[Sj] == '$' && Sold_line[Sj + 1] &&
				Sold_line[Sj + 1] != ' ')
		{
			if (Sold_line[Sj + 1] == '$')
			{
				Sreplacement = Sim_sh_get_pid();
				Sk = Sj + 2;
			}
			else if (Sold_line[Sj + 1] == '?')
			{
				Sreplacement = _itoa(*exe_ret);
				Sk = Sj + 2;
			}
			else if (Sold_line[Sj + 1])
			{
				for (Sk = Sj + 1; Sold_line[Sk] &&
						Sold_line[Sk] != '$' &&
						Sold_line[Sk] != ' '; Sk++)
					;
				Slen = Sk - (Sj + 1);
				Sreplacement = Sim_sh_get_env_value(&Sold_line[Sj + 1], Slen);
			}
			Snew_line = malloc(Sj + _strlen(Sreplacement)
					  + _strlen(&Sold_line[Sk]) + 1);
			if (!line)
				return;
			Snew_line[0] = '\0';
			_strncat(Snew_line, Sold_line, Sj);
			if (Sreplacement)
			{
				_strcat(Snew_line, Sreplacement);
				free(Sreplacement);
				Sreplacement = NULL;
			}
			_strcat(Snew_line, &Sold_line[Sk]);
			free(Sold_line);
			*line = Snew_line;
			Sold_line = Snew_line;
			Sj = -1;
		}
	}
}
