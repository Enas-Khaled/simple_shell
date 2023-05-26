#include "shell.h"

/**
 * Sim_sh_add_alias_end - Sim_sh_add_alias_end
 * @head: head
 * @name: name
 * @value: value
 *
 * Return: NULL. or ptr
 */
alias_t *Sim_sh_add_alias_end(alias_t **head, char *name, char *value)
{
	alias_t *new_node = malloc(sizeof(alias_t));
	alias_t *last;

	if (!new_node)
		return (NULL);
	/* test */
	new_node->next = NULL;
	new_node->name = malloc(sizeof(char) * (_strlen(name) + 1));
	if (!new_node->name)
	{
		free(new_node);
		return (NULL);
	}
	new_node->value = value;
	_strcpy(new_node->name, name);
	/* test */
	if (*head)
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
	}
	else
		*head = new_node;

	return (new_node);
}

/**
 * Sim_sh_add_node_end - Sim_sh_add_node_end
 * @head: head
 * @dir: dir
 * Return: NULL.
 */
list_t *Sim_sh_add_node_end(list_t **head, char *dir)
{
	list_t *new_node = malloc(sizeof(list_t));
	list_t *last;

	if (!new_node)
		return (NULL);
	/* test */
	new_node->dir = dir;
	new_node->next = NULL;
	/* test */
	if (*head)
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
	}
	else
		*head = new_node;

	return (new_node);
}

/**
 * Sim_sh_free_alias_list - Sim_sh_free_alias_list
 * @head: head
 * Return: void
 */
void Sim_sh_free_alias_list(alias_t *head)
{
	alias_t *next;

	while (head)
	{
		/*test*/
		next = head->next;
		free(head->name);
		free(head->value);
		free(head);
		head = next;
	}
}

/**
 * Sim_sh_free_list - Sim_sh_free_list
 * @head: head
 * Return: void
 */
void Sim_sh_free_list(list_t *head)
{
	list_t *next;

	while (head)
	{
		/* test */
		next = head->next;
		free(head->dir);
		free(head);
		head = next;
	}
}
