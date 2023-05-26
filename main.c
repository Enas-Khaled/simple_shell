#include "shell.h"


/**
 * Sim_sh_sig_handler - Sim_sh_sig_handler
 * @sig: Signal.
 * Return: void
 */
void Sim_sh_sig_handler(int sig)
{
	char *Snew_prompt = "\n$ ";

	(void)sig;
	signal(SIGINT, Sim_sh_sig_handler);
	write(STDIN_FILENO, Snew_prompt, 3);
}

/**
 * Sim_sh_execute - Sim_sh_execute
 * @args: args
 * @front: front
 * Return: CODE
 */
int Sim_sh_execute(char **args, char **front)
{
	pid_t Schild_pid;
	int Sstatus, Sflag = 0, Sret = 0;
	char *Scommand = args[0];

	if (Scommand[0] != '/' && Scommand[0] != '.')
	{
		Sflag = 1;
		Scommand = Sim_sh_get_location(Scommand);
	}
	if (!Scommand || (access(Scommand, F_OK) == -1))
	{
		if (errno == EACCES)
			Sret = (Sim_sh_create_error(args, 126));
		else
			Sret = (Sim_sh_create_error(args, 127));
	}
	else
	{
		Schild_pid = fork();
		if (Schild_pid == -1)
		{
			if (Sflag)
				free(Scommand);
			perror("Error child:");
			return (1);
		}
		if (Schild_pid == 0)
		{
			execve(Scommand, args, environ);
			if (errno == EACCES)
				Sret = (Sim_sh_create_error(args, 126));
			Sim_sh_free_env();
			Sim_sh_free_args(args, front);
			Sim_sh_free_alias_list(aliases);
			_exit(Sret);
		}
		else
		{
			wait(&Sstatus);
			Sret = WEXITSTATUS(Sstatus);
		}
	}
	if (Sflag)
		free(Scommand);
	return (Sret);
}

/**
 * main - Eentery point.
 * @argc: no. og args
 * @argv: arr_arguments.
 * Return: Last_executed_command.
 */
int main(int argc, char *argv[])
{
	int Sret = 0, Sretn;
	int *Sexe_ret = &Sretn;
	char *Sprompt = "$ ", *Snew_line = "\n";

	name = argv[0];
	hist = 1;
	aliases = NULL;
	signal(SIGINT, Sim_sh_sig_handler);
	*Sexe_ret = 0;
	environ = Sim_sh_copyenv();
	if (!environ)
		exit(-100);
	if (argc != 1)
	{
		Sret = Sim_sh_proc_file_commands(argv[1], Sexe_ret);
		Sim_sh_free_env();
		Sim_sh_free_alias_list(aliases);
		return (*Sexe_ret);
	}
	if (!isatty(STDIN_FILENO))
	{
		while (Sret != END_OF_FILE && Sret != EXIT)
			Sret = Sim_sh_handle_args(Sexe_ret);
		Sim_sh_free_env();
		Sim_sh_free_alias_list(aliases);
		return (*Sexe_ret);
	}
	while (1)
	{
		write(STDOUT_FILENO, Sprompt, 2);
		Sret = Sim_sh_handle_args(Sexe_ret);
		if (Sret == END_OF_FILE || Sret == EXIT)
		{
			if (Sret == END_OF_FILE)
				write(STDOUT_FILENO, Snew_line, 1);
			Sim_sh_free_env();
			Sim_sh_free_alias_list(aliases);
			exit(*Sexe_ret);
		}
	}
	Sim_sh_free_env();
	Sim_sh_free_alias_list(aliases);
	return (*Sexe_ret);
}
