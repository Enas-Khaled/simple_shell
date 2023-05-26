#include "shell.h"

void Sim_sh_set_alias(char *var_name, char *value);
void Sim_sh_print_alias(alias_t *alias);

/**
 * Sim_sh_shellby_alias - it is a command to 
 *    -> print or specific or set aliases.
 * @args: arr_of_args.
 * @front: ptr to ptr to begin_of_args.
 *
 * Return: -1 on error 0 Otherwise.
 */
int Sim_sh_shellby_alias(char **args, char __attribute__((__unused__)) **front)
{
	alias_t *temp = aliases;
	int Si, Sret = 0;
	char *Svalue;

	if (!args[0])
	{
		while (temp)
		{
			Sim_sh_print_alias(temp);
			temp = temp->next;
		}
		return (Sret);
	}
	for (Si = 0; args[Si]; Si++)
	{
		temp = aliases;
		Svalue = _strchr(args[Si], '=');
		if (!Svalue)
		{
			while (temp)
			{
				if (_strcmp(args[Si], temp->name) == 0)
				{
					Sim_sh_print_alias(temp);
					break;
				}
				temp = temp->next;
			}
			if (!temp)
				Sret = Sim_sh_create_error(args + Si, 1);
		}
		else
			Sim_sh_set_alias(args[Si], Svalue);
	}
	return (Sret);
}

/**
 * Sim_sh_set_alias - To set the alias_name -> new_value,
 *                  or create a new_alias.
 * @var_name: name.
 * @value: val
 */
void Sim_sh_set_alias(char *var_name, char *value)
{
	alias_t *temp = aliases;
	int Slen, a, b;
	char *Snew_value;

	/*debug point */
	*value = '\0';
	value++;
	Slen = _strlen(value) - _strspn(value, "'\"");
	Snew_value = malloc(sizeof(char) * (Slen + 1));
	if (!Snew_value)
		return;
	for (a = 0, b = 0; value[a]; a++)
	{
		if (value[a] != '\'' && value[a] != '"')
			Snew_value[b++] = value[a];
	}
	/*debug point */
	Snew_value[b] = '\0';
	while (temp)
	{
		if (_strcmp(var_name, temp->name) == 0)
		{
			free(temp->value);
			temp->value = Snew_value;
			break;
		}
		temp = temp->next;
	}
	if (!temp)
		Sim_sh_add_alias_end(&aliases, var_name, Snew_value);
}

/**
 * Sim_sh_print_alias - To print alias.
 * @alias: ptr to alias.
 */
void Sim_sh_print_alias(alias_t *alias)
{
	char *Salias_string;
	int Slen = _strlen(alias->name) + _strlen(alias->value) + 4;

	Salias_string = malloc(sizeof(char) * (Slen + 1));
	if (!Salias_string)
		return;
	_strcpy(Salias_string, alias->name);
	_strcat(Salias_string, "='");
	_strcat(Salias_string, alias->value);
	_strcat(Salias_string, "'\n");

	write(STDOUT_FILENO, Salias_string, Slen);
	free(Salias_string);
}
/**
 * Sim_sh_replace_aliases - to go through args to replace alias
 * @args: ptr to ptr to args.
 * Return: ptr to ptr to args.
 */
char **Sim_sh_replace_aliases(char **args)
{
	alias_t *temp;
	int a;
	char *Snew_value;

	if (_strcmp(args[0], "alias") == 0)
		return (args);
	for (a = 0; args[a]; a++)
	{
		temp = aliases;
		while (temp)
		{
			if (_strcmp(args[a], temp->name) == 0)
			{
				Snew_value = malloc(sizeof(char) * (_strlen(temp->value) + 1));
				if (!Snew_value)
				{
					Sim_sh_free_args(args, args);
					return (NULL);
				}
				_strcpy(Snew_value, temp->value);
				free(args[a]);
				args[a] = Snew_value;
				a--;
				break;
			}
			temp = temp->next;
		}
	}

	return (args);
}
