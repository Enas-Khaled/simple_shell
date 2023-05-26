#include "shell.h"

/**
 * _itoa - to convert int to str.
 * @num: int.
 *
 * Return: str.
 */
char *_itoa(int num)
{
	char *Sbuffer;
	int Slen = Sim_sh_num_len(num);
	unsigned int Snum1;

	Sbuffer = malloc(sizeof(char) * (Slen + 1));
	if (!Sbuffer)
		return (NULL);

	Sbuffer[Slen] = '\0';

	if (num < 0)
	{
		Snum1 = num * -1;
		Sbuffer[0] = '-';
	}
	else
	{
		Snum1 = num;
	}

	Slen--;
	do {
		Sbuffer[Slen] = (Snum1 % 10) + '0';
		Snum1 /= 10;
		Slen--;
	} while (Snum1 > 0);

	return (Sbuffer);
}

/**
 * Sim_sh_num_len - to count Length Of Num.
 * @num: Number.
 *
 * Return: Length.
 */
int Sim_sh_num_len(int num)
{
	unsigned int Snum1;
	int Slen = 1;

	if (num < 0)
	{
		Slen++;
		Snum1 = num * -1;
	}
	else
	{
		Snum1 = num;
	}
	while (Snum1 > 9)
	{
		Slen++;
		Snum1 /= 10;
	}

	return (Slen);
}


/**
 * Sim_sh_create_error - to write Error_message for stderr.
 * @args: arr_of_args.
 * @err: Err_val.
 *
 * Return: Err_value.
 */
int Sim_sh_create_error(char **args, int err)
{
	char *Serror;

	switch (err)
	{
	case -1:
		Serror = Sim_sh_error_env(args);
		break;
	case 1:
		Serror = Sim_sh_error_1(args);
		break;
	case 2:
		if (*(args[0]) == 'e')
			Serror = Sim_sh_error_2_exit(++args);
		else if (args[0][0] == ';' || args[0][0] == '&' || args[0][0] == '|')
			Serror = Sim_sh_error_2_syntax(args);
		else
			Serror = Sim_sh_error_2_cd(args);
		break;
	case 126:
		Serror = Sim_sh_error_126(args);
		break;
	case 127:
		Serror = Sim_sh_error_127(args);
		break;
	}
	write(STDERR_FILENO, Serror, _strlen(Serror));

	if (Serror)
		free(Serror);
	return (err);

}
