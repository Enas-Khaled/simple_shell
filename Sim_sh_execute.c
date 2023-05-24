#include "shell.h"

/**
 * Sim_sh_execute - this executes the command with its args.
 * @argv: array containing ( command and its arguments).
 *
 * Return: Exit status of that command.
 */
int Sim_sh_execute(char **argv)
{
	int Sim_sh_status = 0;
	pid_t id;
	char *Sim_sh_cmd_path, *Sim_sh_envp[2];
	/* check */
	if (argv == NULL || *argv == NULL)
		return (Sim_sh_status);
	if (Sim_sh_check_for_builtin(argv))
		return (Sim_sh_status);
	id = fork(); /* child p */
	if (id < 0)
	{
		Sim_sh_puterror("fork");
		return (1);
	}
	/* check */
	if (id == -1)
		perror(argv[0]), Sim_sh_free_tokens(argv), Sim_sh_free_last_input();
	if (id == 0)
	{
		Sim_sh_envp[0] = Sim_sh_get_path();
		Sim_sh_envp[1] = NULL;
		Sim_sh_cmd_path = NULL;
		/* debug point */
		if (argv[0][0] != '/')
			Sim_sh_cmd_path = Sim_sh_find_in_path(argv[0]);
		if (Sim_sh_cmd_path == NULL)
			Sim_sh_cmd_path = argv[0];
		if (execve(Sim_sh_cmd_path, argv, Sim_sh_envp) == -1)
		{
			perror(argv[0]);
			Sim_sh_free_tokens(argv);
			Sim_sh_free_last_input();
			exit(EXIT_FAILURE);
		}
	} else

		do {
			waitpid(id, &Sim_sh_status, WUNTRACED);
		} while (!WIFEXITED(Sim_sh_status) && !WIFSIGNALED(Sim_sh_status));
	return (Sim_sh_status);
}
