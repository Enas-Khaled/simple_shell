#include "shell.h"

/**
 * Sim_sh_get_line - to read the input from  stdinput.
 *
 * Return: string from user.
*/
void *Sim_sh_get_line(void)
{
	int Sim_sh_input_len = 0;
	char *Sim_sh_input_str = NULL;
	char Sim_sh_current_char;
	static char Sim_sh_buffer[BUFFER_SIZE];
	static int Sim_sh_buf_pos, Sim_sh_buf_size;

	while (1)
	{
		/* check position */
		if (Sim_sh_buf_pos >= Sim_sh_buf_size)
		{
			/* bedug point */
			Sim_sh_buf_size = read(STDIN_FILENO, Sim_sh_buffer, BUFFER_SIZE);
			Sim_sh_buf_pos = 0;
			/* check */
			if (Sim_sh_buf_size == 0)
				return (Sim_sh_input_str);
			else if (Sim_sh_buf_size < 0)
			{
				perror("read");
				/* err */
				return (NULL);
			}
		}
		Sim_sh_current_char = Sim_sh_buffer[Sim_sh_buf_pos];/* debug point */
		Sim_sh_buf_pos++;/*update pos */
		if (Sim_sh_current_char == '\n')/* check if new line */
		{
			/* suppose _realloc() */
			Sim_sh_input_str = realloc(Sim_sh_input_str, Sim_sh_input_len + 1);
			Sim_sh_input_str[Sim_sh_input_len] = '\0';
			return (Sim_sh_input_str);
		}
		else
		{
			Sim_sh_input_str = realloc(Sim_sh_input_str, Sim_sh_input_len + 1);
			Sim_sh_input_str[Sim_sh_input_len] = Sim_sh_current_char;
			Sim_sh_input_len++;/* update len */
		}
	}
}
