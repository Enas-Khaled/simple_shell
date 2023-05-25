#include "shell.h"

static char *Sim_sh_last_input;
/**
 * Sim_sh_get_input - to read line from stdinput.
 *
 * Return: ptr to buf of user's input.
*/
char *Sim_sh_get_input(void)
{
	ssize_t tnread;
	char *tinput = NULL;
	size_t tinput_size = 0;
	/* call prompt function to print */
	do {
		/*Sim_sh_prompt();*/
		/* important debug point to read from user */
		tnread = getline(&tinput, &tinput_size, stdin);
		/* this checks if end of the file */
		if (tnread == -1)
		{
			free(tinput);
			Sim_sh_puts("\n");
			return (NULL);
		}
		/* to delete new_line trailing */
		tinput[tnread - 1] = '\0';

	} while (tinput[0] == '\0' || isspace(tinput[0]));
	/* to put last input and update it - hope to work */
	Sim_sh_last_input = tinput;
	return (tinput);
}

/**
 * Sim_sh_free_last_input - to free last input from user.
 *
 * Return: void_fun
 */
void Sim_sh_free_last_input(void)
{
	free(Sim_sh_last_input);
	Sim_sh_last_input = NULL;
}
