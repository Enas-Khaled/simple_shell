#include "shell.h"

/**
 * Sim_sh_prompt - this prints prompt of the shell
 *                 to stdin_stream.
 *
 * Return: nothing.
 */
void Sim_sh_prompt(void)
{
	/* debug point */
	Sim_sh_puts(PROMPT);
	fflush(stdout);
}
