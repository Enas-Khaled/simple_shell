#include "shell.h"

/**
 * Sim_sh_get_location - Sim_sh_get_location
 * @command: command
 *
 * Return:  NULL.
 */
char *Sim_sh_get_location(char *command)
{
	char **Spath, *Stemp;
	list_t *Sdirs, *Shead;
	struct stat Sst;

	Spath = Sim_sh_getenv("PATH");
	if (!Spath || !(*Spath))
		return (NULL);

	Sdirs = Sim_sh_get_path_dir(*Spath + 5);
	Shead = Sdirs;

	while (Sdirs)
	{
		Stemp = malloc(_strlen(Sdirs->dir) + _strlen(command) + 2);
		if (!Stemp)
			return (NULL);

		_strcpy(Stemp, Sdirs->dir);
		_strcat(Stemp, "/");
		_strcat(Stemp, command);

		if (stat(Stemp, &Sst) == 0)
		{
			Sim_sh_free_list(Shead);
			return (Stemp);
		}

		Sdirs = Sdirs->next;
		free(Stemp);
	}

	Sim_sh_free_list(Shead);

	return (NULL);
}

/**
 * Sim_sh_fill_path_dir - Sim_sh_fill_path_dir
 * @path: path
 *
 * Return: Copy_of_path
 */
char *Sim_sh_fill_path_dir(char *path)
{
	int Si, Slength = 0;
	char *Spath_copy, *Spwd;

	Spwd = *(Sim_sh_getenv("PWD")) + 4;
	for (Si = 0; path[Si]; Si++)
	{
		if (path[Si] == ':')
		{
			if (path[Si + 1] == ':' || Si == 0 || path[Si + 1] == '\0')
				Slength += _strlen(Spwd) + 1;
			else
				Slength++;
		}
		else
			Slength++;
	}
	Spath_copy = malloc(sizeof(char) * (Slength + 1));
	if (!Spath_copy)
		return (NULL);
	Spath_copy[0] = '\0';
	for (Si = 0; path[Si]; Si++)
	{
		if (path[Si] == ':')
		{
			if (Si == 0)
			{
				_strcat(Spath_copy, Spwd);
				_strcat(Spath_copy, ":");
			}
			else if (path[Si + 1] == ':' || path[Si + 1] == '\0')
			{
				_strcat(Spath_copy, ":");
				_strcat(Spath_copy, Spwd);
			}
			else
				_strcat(Spath_copy, ":");
		}
		else
		{
			_strncat(Spath_copy, &path[Si], 1);
		}
	}
	return (Spath_copy);
}

/**
 * Sim_sh_get_path_dir - TSim_sh_get_path_dir
 * @path: path
 *
 * Return: ptr
 */
list_t *Sim_sh_get_path_dir(char *path)
{
	int Sindex;
	char **Sdirs, *Spath_copy;
	list_t *Shead = NULL;

	Spath_copy = Sim_sh_fill_path_dir(path);
	if (!Spath_copy)
		return (NULL);
	Sdirs = _strtok(Spath_copy, ":");
	free(Spath_copy);
	if (!Sdirs)
		return (NULL);

	for (Sindex = 0; Sdirs[Sindex]; Sindex++)
	{
		if (Sim_sh_add_node_end(&Shead, Sdirs[Sindex]) == NULL)
		{
			Sim_sh_free_list(Shead);
			free(Sdirs);
			return (NULL);
		}
	}

	free(Sdirs);

	return (Shead);
}
