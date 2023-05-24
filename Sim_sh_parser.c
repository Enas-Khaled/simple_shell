#include "shell.h"

/**
 * Sim_sh_tokenize - to parse the input to args
 * @str: str for tokening it.
 * @delim: for splitting.
 *
 * Return: arr of ptrs to tokens,
 *         NULL on errors.
 */
char **Sim_sh_tokenize(char *str, const char *delim)
{
	int k = 0;
	char *t_token = NULL;
	char **t_ret = NULL;

	/* parse token */
	t_token = strtok(str, delim);
	while (t_token)
	{
		t_ret = realloc(t_ret, sizeof(char *) * (k + 1));
		/* check for err */
		if (t_ret == NULL)
			return (NULL);
		/* allocate */
		t_ret[k] = malloc(_strlen(t_token) + 1);
		if (!(t_ret[k]))
			return (NULL);
		/* copy token and update to next */
		_strcpy(t_ret[k], t_token);
		t_token = strtok(NULL, delim);
		k++;
	}
	/* need to update with new size of arr*/
	t_ret = realloc(t_ret, (k + 1) * sizeof(char *));
	/* check for err */
	if (!t_ret)
		return (NULL);

	t_ret[k] = NULL;
	return (t_ret);
}

/**
 * Sim_sh_tokenize_input - to split input to tokens
 *                using tokenize fun.
 * @input: input
 *
 * Return: arr of ptrs to tokens
 *         NULL on errors
 */
char **Sim_sh_tokenize_input(char *input)
{
	char *s_tmp = NULL;
	char **s_tokens = NULL;

	/* dulicate input */
	s_tmp = _strdup(input);
	if (s_tmp == NULL)
	{
		/* error */
		Sim_sh_puts("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	/* debug point */
	s_tokens = Sim_sh_tokenize(s_tmp, " \t\r\n\a");
	free(s_tmp);
	/* return tokens */
	return (s_tokens);
}
