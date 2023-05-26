#include "shell.h"

/**
 * Sim_sh_help_unsetenv - to displays info of 'unsetenv'.
 * Return: void
 */
void Sim_sh_help_unsetenv(void)
{
	char *Smsg = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
	Smsg = "environmental variable.\n\n\tUpon failure, prints a ";
	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
	Smsg = "message to stderr.\n";
	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
}
/**
 * Sim_sh_help_env - to display info of 'env'.
 * Return: void
 */
void Sim_sh_help_env(void)
{
	char *Smsg = "env: env\n\tPrints the current environment.\n";

	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
}

/**
 * Sim_sh_help_setenv - to displays info of 'setenv'.
 * Return: void
 */
void Sim_sh_help_setenv(void)
{
	char *Smsg = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
	Smsg = "environment variable, or modifies an existing one.\n\n";
	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
	Smsg = "\tUpon failure, prints a message to stderr.\n";
	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
}

