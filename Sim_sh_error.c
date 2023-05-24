#include "shell.h"

/**
 * Sim_sh_puterror - to print error message to the stderr.
 * @err: error message.
 *
 * Return: void_fun.
*/
void Sim_sh_puterror(char *err)
{
	char *Sim_sh_p = err;

	while (*Sim_sh_p != '\0')
	{
		if (write(STDERR_FILENO, Sim_sh_p, 1) == -1)
		{
			perror("write");
		return;
		}
		Sim_sh_p++;
	}
}
/**
 * Sim_sh_puts - this writes str to stdout
 *  dose not including null char.
 *   If an error occurs during the writing process
 *  , the function prints an error message
 *
 * @str:  str to be printed
 *
 * Return: void_fun
*/

void Sim_sh_puts(char *str)
{
	char *p = str;

	while (*p != '\0')
	{
		if (write(STDOUT_FILENO, p, 1) == -1)
		{
			perror("write");
			return;
		}
		p++;
	}
}
