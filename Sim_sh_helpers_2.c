#include "shell.h"

/**
 * Sim_sh_handle_line - Sim_sh_handle_line
 * @line: line
 * @read: Length
 */
void Sim_sh_handle_line(char **line, ssize_t read)
{
	char *Sold_line, *Snew_line;
	char Sprevious, Scurrent, Snext;
	size_t Si, Sj;
	ssize_t Snew_len;

	Snew_len = Sim_sh_get_new_len(*line);
	if (Snew_len == read - 1)
		return;
	Snew_line = malloc(Snew_len + 1);
	if (!Snew_line)
		return;
	Sj = 0;
	Sold_line = *line;
	for (Si = 0; Sold_line[Si]; Si++)
	{
		Scurrent = Sold_line[Si];
		Snext = Sold_line[Si + 1];
		if (Si != 0)
		{
			Sprevious = Sold_line[Si - 1];
			if (Scurrent == ';')
			{
				if (Snext == ';' && Sprevious != ' ' && Sprevious != ';')
				{
					Snew_line[Sj++] = ' ';
					Snew_line[Sj++] = ';';
					continue;
				}
				else if (Sprevious == ';' && Snext != ' ')
				{
					Snew_line[Sj++] = ';';
					Snew_line[Sj++] = ' ';
					continue;
				}
				if (Sprevious != ' ')
					Snew_line[Sj++] = ' ';
				Snew_line[Sj++] = ';';
				if (Snext != ' ')
					Snew_line[Sj++] = ' ';
				continue;
			}
			else if (Scurrent == '&')
			{
				if (Snext == '&' && Sprevious != ' ')
					Snew_line[Sj++] = ' ';
				else if (Sprevious == '&' && Snext != ' ')
				{
					Snew_line[Sj++] = '&';
					Snew_line[Sj++] = ' ';
					continue;
				}
			}
			else if (Scurrent == '|')
			{
				if (Snext == '|' && Sprevious != ' ')
					Snew_line[Sj++]  = ' ';
				else if (Sprevious == '|' && Snext != ' ')
				{
					Snew_line[Sj++] = '|';
					Snew_line[Sj++] = ' ';
					continue;
				}
			}
		}
		else if (Scurrent == ';')
		{
			if (Si != 0 && Sold_line[Si - 1] != ' ')
				Snew_line[Sj++] = ' ';
			Snew_line[Sj++] = ';';
			if (Snext != ' ' && Snext != ';')
				Snew_line[Sj++] = ' ';
			continue;
		}
		Snew_line[Sj++] = Sold_line[Si];
	}
	Snew_line[Sj] = '\0';

	free(*line);
	*line = Snew_line;
}

/**
 * Sim_sh_get_new_len - Sim_sh_get_new_len
 * @line: line
 *
 * Return: Length.
 */

ssize_t Sim_sh_get_new_len(char *line)
{
	size_t Si;
	ssize_t Snew_len = 0;
	char Scurrent, Snext;

	for (Si = 0; line[Si]; Si++)
	{
		Scurrent = line[Si];
		Snext = line[Si + 1];
		if (Scurrent == '#')
		{
			if (Si == 0 || line[Si - 1] == ' ')
			{
				line[Si] = '\0';
				break;
			}
		}
		else if (Si != 0)
		{
			if (Scurrent == ';')
			{
				if (Snext == ';' && line[Si - 1] != ' ' && line[Si - 1] != ';')
				{
					Snew_len += 2;
					continue;
				}
				else if (line[Si - 1] == ';' && Snext != ' ')
				{
					Snew_len += 2;
					continue;
				}
				if (line[Si - 1] != ' ')
					Snew_len++;
				if (Snext != ' ')
					Snew_len++;
			}
			else
				Sim_sh_logical_ops(&line[Si], &Snew_len);
		}
		else if (Scurrent == ';')
		{
			if (Si != 0 && line[Si - 1] != ' ')
				Snew_len++;
			if (Snext != ' ' && Snext != ';')
				Snew_len++;
		}
		Snew_len++;
	}
	return (Snew_len);
}
/**
 * Sim_sh_logical_ops - Sim_sh_logical_ops.
 * @line: line
 * @new_len: new_len
 */
void Sim_sh_logical_ops(char *line, ssize_t *new_len)
{
	char Sprevious, Scurrent, Snext;

	Sprevious = *(line - 1);
	Scurrent = *line;
	Snext = *(line + 1);

	if (Scurrent == '&')
	{
		if (Snext == '&' && Sprevious != ' ')
			(*new_len)++;
		else if (Sprevious == '&' && Snext != ' ')
			(*new_len)++;
	}
	else if (Scurrent == '|')
	{
		if (Snext == '|' && Sprevious != ' ')
			(*new_len)++;
		else if (Sprevious == '|' && Snext != ' ')
			(*new_len)++;
	}
}
