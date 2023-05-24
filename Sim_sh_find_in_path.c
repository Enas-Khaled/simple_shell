#include "shell.h"

/**
 * Sim_sh_find_in_path - to look for a command
 *                var_env
 * @command: ptr to the command.
 *
 * Return: ptr to Full_path
 *        success -> found,
 *        NULL -> failure.
*/
char *Sim_sh_find_in_path(char *command)
{
	struct stat Sim_sh_st;
	char Sim_sh_buf[PATH_MAX_LENGTH];
	char *tpath, *tret, **tdir;
	int Sim_sh_stat_ret, j;
	/* put path */
	tpath = Sim_sh_get_path();
	if (!tpath)
		return (NULL);
		/* call tokinise function */
	tdir = Sim_sh_tokenize(tpath, PATH_SEPARATOR);
	if (!tdir)
		return (NULL);
	for (j = 0; tdir[j]; j++)
	{ /* mimic builtin functions */
		_memset(Sim_sh_buf, 0, PATH_MAX_LENGTH);
		_strcpy(Sim_sh_buf, tdir[j]);
		_strcat(Sim_sh_buf, "/");
		_strcat(Sim_sh_buf, command);
		/* debugging point */
		Sim_sh_stat_ret = stat(Sim_sh_buf, &Sim_sh_st);
		if (Sim_sh_stat_ret == 0 && S_ISREG(Sim_sh_st.st_mode)
				&& (Sim_sh_st.st_mode & S_IXUSR))
		{
			/* to free the tokens */
			Sim_sh_free_tokens(tdir);
			tret = malloc(sizeof(char) * (strlen(Sim_sh_buf) + 1));
			if (!tret)
				return (NULL);
				/* suppose to use _strcpy sorry */
			strcpy(tret, Sim_sh_buf);
			return (tret);
		}
	}
	/* check err */
	if (Sim_sh_stat_ret == -1)
		Sim_sh_free_tokens(tdir);
	return (NULL);
}
