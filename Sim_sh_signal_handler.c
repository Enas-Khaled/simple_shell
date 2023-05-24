#include "shell.h"
/**
 * Sim_sh_handle_sigquit - to handle -> (Ctrl+\)
 * @sig: num of signal
 *
 * Return: void_fun
 */
void Sim_sh_handle_sigquit(int sig)
{
	(void) sig;
	/* to std err */
	Sim_sh_puterror("Quit (core dumped)\n");
	exit(EXIT_SUCCESS);
}

/**
 * Sim_sh_handle_sigint - to handle -> Ctrl+C
 * @sig: num of signal
 *
 * Return: void_fun
 */
void Sim_sh_handle_sigint(int sig)
{
	(void) sig;
	/* new line */
	_putchar('\n');
	/* call prompt shell */
	Sim_sh_prompt();
}


/**
 * Sim_sh_handle_sigstp - to handle -> Ctrl+Z
 * @sig: num of signal
 *
 * Return: void_fun
 */
void Sim_sh_handle_sigstp(int sig)
{
	(void) sig;
	Sim_sh_puts("\n");
	/* call prompt fun */
	Sim_sh_prompt();
}
