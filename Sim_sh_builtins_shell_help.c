#include "shell.h"

/**
 * print_shell_info - Print information about the shell.
 *
 * This function prints information about the shell,
 *	such as its version number and author.
 */
void print_shell_info(void)
{
	Sim_sh_puts("\nWelcome to MyShell!\n\n");
	Sim_sh_puts("Version: 1.0.0\n");
	Sim_sh_puts("Author: Test\n\n");
}

/**
 * print_help_info - Print help information for the shell.
 *
 * This function prints information about the available
 * commands in the shell.
 */
void print_help_info(void)
{
	Sim_sh_puts("\nAvailable commands:\n\n");
	Sim_sh_puts("cd [dir]\tChange the current working directory\n");
	Sim_sh_puts("env\t\tDisplay the environment variables\n");
	Sim_sh_puts("setenv\t\tSet an environment variable\n");
	Sim_sh_puts("unsetenv\tUnset an environment variable\n");
	Sim_sh_puts("exit\tExit the shell\n\n");
}

/**
 * Sim_sh_shell_help - Display help information for the shell.
 *
 * This function calls the print_shell_info and
 * print_help_info functions to display information
 * about the shell and its available commands.
 */

void Sim_sh_shell_help(void)
{
	print_shell_info();
	print_help_info();
}
