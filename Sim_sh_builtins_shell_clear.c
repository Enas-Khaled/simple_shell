#include "shell.h"

/**
 * Sim_sh_shell_clear - to clear terminal
 * @args: args but unused
 *
 * Return: 1 success
*/

int Sim_sh_shell_clear(char **args)
{
	int num;
	(void)args;
	num = 0;
	num += _putchar('\033');
	num += _putchar('[');
	num += _putchar('2');
	num += _putchar('J');
	num += _putchar('\033');
	num += _putchar('[');
	num += _putchar('H');
	if (num == -1)
	{
		Sim_sh_puterror("clear: Error writing to standard output\n");
		return (1);
	}
	return (1);
}
