#include "shell.h"


/**
 * Sim_sh_token_len - Sim_sh_token_len
 * @str: str.
 * @delim: delim
 *
 * Return: index
 */
int Sim_sh_token_len(char *str, char *delim)
{
	int Sindex = 0, Slen = 0;

	while (*(str + Sindex) && *(str + Sindex) != *delim)
	{
		Slen++;
		Sindex++;
	}

	return (Slen);
}

/**
 * Sim_sh_count_tokens - Sim_sh_count_tokens
 * @str: Sim_sh_count_tokens
 * @delim: Sim_sh_count_tokens
 *
 * Return: Sim_sh_count_tokens
 */
int Sim_sh_count_tokens(char *str, char *delim)
{
	int Sindex, Stokens = 0, Slen = 0;

	for (Sindex = 0; *(str + Sindex); Sindex++)
		Slen++;

	for (Sindex = 0; Sindex < Slen; Sindex++)
	{
		if (*(str + Sindex) != *delim)
		{
			Stokens++;
			Sindex += Sim_sh_token_len(str + Sindex, delim);
		}
	}

	return (Stokens);
}

/**
 * _strtok - _strtok
 * @line: _strtok
 * @delim: _strtok
 *
 * Return: _strtok
 */
char **_strtok(char *line, char *delim)
{
	char **Sptr;
	int Sindex = 0, Stokens, St, Sletters, Sl;

	Stokens = Sim_sh_count_tokens(line, delim);
	if (Stokens == 0)
		return (NULL);

	Sptr = malloc(sizeof(char *) * (Stokens + 2));
	if (!Sptr)
		return (NULL);

	for (St = 0; St < Stokens; St++)
	{
		while (line[Sindex] == *delim)
			Sindex++;

		Sletters = Sim_sh_token_len(line + Sindex, delim);

		Sptr[St] = malloc(sizeof(char) * (Sletters + 1));
		if (!Sptr[St])
		{
			for (Sindex -= 1; Sindex >= 0; Sindex--)
				free(Sptr[Sindex]);
			free(Sptr);
			return (NULL);
		}

		for (Sl = 0; Sl < Sletters; Sl++)
		{
			Sptr[St][Sl] = line[Sindex];
			Sindex++;
		}

		Sptr[St][Sl] = '\0';
	}
	Sptr[St] = NULL;
	Sptr[St + 1] = NULL;

	return (Sptr);
}
