#include "shell.h"

/**
 * Sim_sh_help_help - to displays info of'help'.
 * Return: void
 */
void Sim_sh_help_help(void)
{
	char *Smsg = "help: help\n\tSee all possible Shellby builtin commands.\n";

	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
	Smsg = "\n      help [BUILTIN NAME]\n\tSee specific information on each ";
	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
	Smsg = "builtin command.\n";
	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
}
/**
 * Sim_sh_help_all - to display All builtin_commands.
 * Return: void
 */
void Sim_sh_help_all(void)
{
	char *Smsg = "Shellby\nThese shell commands are defined internally.\n";

	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
	Smsg = "Type 'help' to see this list.\nType 'help name' to find ";
	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
	Smsg = "out more about the function 'name'.\n\n  alias   \t";
	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
	Smsg = "alias [NAME[='VALUE'] ...]\n  cd    \tcd   ";
	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
	Smsg = "[DIRECTORY]\n  exit    \texit [STATUS]\n  env     \tenv";
	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
	Smsg = "\n  setenv  \tsetenv [VARIABLE] [VALUE]\n  unsetenv\t";
	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
	Smsg = "unsetenv [VARIABLE]\n";
	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
}

/**
 * Sim_sh_help_exit - to displays info of'exit'.
 * Return: void
 */
void Sim_sh_help_exit(void)
{
	char *Smsg = "exit: exit [STATUS]\n\tExits the shell.\n\n\tThe ";

	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
	Smsg = "STATUS argument is the integer used to exit the shell.";
	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
	Smsg = " If no argument is given, the command is interpreted as";
	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
	Smsg = " exit 0.\n";
	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
}

/**
 * Sim_sh_help_alias - to display info of 'alias'.
 * Return: void
 */
void Sim_sh_help_alias(void)
{
	char *Smsg = "alias: alias [NAME[='VALUE'] ...]\n\tHandles aliases.\n";

	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
	Smsg = "\n\talias: Prints a list of all aliases, one per line, in ";
	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
	Smsg = "the format NAME='VALUE'.\n\talias name [name2 ...]:prints";
	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
	Smsg = " the aliases name, name2, etc. one per line, in the ";
	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
	Smsg = "form NAME='VALUE'.\n\talias NAME='VALUE' [...]: Defines";
	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
	Smsg = " an alias for each NAME whose VALUE is given. If NAME ";
	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
	Smsg = "is already an alias, replace its value with VALUE.\n";
	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
}

/**
 * Sim_sh_help_cd - to isplay info of 'cd'.
 * Return: void
 */
void Sim_sh_help_cd(void)
{
	char *Smsg = "cd: cd [DIRECTORY]\n\tChanges the current directory of the";

	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
	Smsg = " process to DIRECTORY.\n\n\tIf no argument is given, the ";
	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
	Smsg = "command is interpreted as cd $HOME. If the argument '-' is";
	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
	Smsg = " given, the command is interpreted as cd $OLDPWD.\n\n";
	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
	Smsg = "\tThe environment variables PWD and OLDPWD are updated ";
	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
	Smsg = "after a change of directory.\n";
	write(STDOUT_FILENO, Smsg, _strlen(Smsg));
}

