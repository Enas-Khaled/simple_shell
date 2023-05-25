#include "shell.h"

/**
 * main - entery point
 *
 * Return: on exit -> EXIT_SUCCESS.
 */
int main(void)
{
	/*test*/
	char *Sim_sh_input;
	char **Sim_sh_args;
	int Sim_sh_status;

	/* to register the handler of the signal */
	signal(SIGINT, Sim_sh_handle_sigint);
	signal(SIGQUIT, Sim_sh_handle_sigquit);
	signal(SIGTSTP, Sim_sh_handle_sigstp);

	do {
		Sim_sh_input = Sim_sh_get_input();
		/* to detect end of file and stop */
		if (!Sim_sh_input || !*Sim_sh_input)
			break;
		/* debug point */
		Sim_sh_args = Sim_sh_tokenize_input(Sim_sh_input);
		if (!Sim_sh_args || !*Sim_sh_args)
		{
			free(Sim_sh_input);
			Sim_sh_free_tokens(Sim_sh_args);
			continue;
		}
		/* debug point */
		Sim_sh_status = Sim_sh_execute(Sim_sh_args);
		free(Sim_sh_input);
		Sim_sh_free_tokens(Sim_sh_args);

		/* debug point */
		Sim_sh_status = 1;
	} while (Sim_sh_status);

	return (EXIT_SUCCESS);
}
