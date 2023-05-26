#include "shell.h"

/**
 * Sim_sh_assign_lineptr - to reassign lineptr_var.
 * @lineptr: Buffer for Storing input_str.
 * @n: lineptr's size.
 * @buffer: Str to assign.
 * @b: Buff's size.
 */
void Sim_sh_assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b)
{
	if (*lineptr == NULL)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else if (*n < b)
	{
		/* debug point */
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else
	{
		/* debug point */
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}

/**
 * _getline - to read input from std_stream.
 * @lineptr: Buffer for Storing input_str.
 * @n: lineptr's size.
 * @stream: std_stream.
 *
 * Return: Num_of_bytes that have read.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t Sinput;
	ssize_t Sret;
	char Sc = 'x', *Sbuffer;
	int Sr;

	if (Sinput == 0)
		fflush(stream);
	else
		return (-1);
	Sinput = 0;

	Sbuffer = malloc(sizeof(char) * 120);
	if (!Sbuffer)
		return (-1);

	while (Sc != '\n')
	{
		Sr = read(STDIN_FILENO, &Sc, 1);
		if (Sr == -1 || (Sr == 0 && Sinput == 0))
		{
			free(Sbuffer);
			return (-1);
		}
		if (Sr == 0 && Sinput != 0)
		{
			Sinput++;
			break;
		}

		if (Sinput >= 120)
			Sbuffer = _realloc(Sbuffer, Sinput, Sinput + 1);

		Sbuffer[Sinput] = Sc;
		Sinput++;
	}
	Sbuffer[Sinput] = '\0';

	Sim_sh_assign_lineptr(lineptr, n, Sbuffer, Sinput);

	Sret = Sinput;
	if (Sr != 0)
		Sinput = 0;
	return (Sret);
}

/**
 * _realloc - to reallocate memory_block.
 * @ptr: ptr to memory Prev_allocated.
 * @old_size: Size of Allocated_space for ptr(byte).
 * @new_size: Size of New_memory_block(byte).
 *
 * Return: ptr to Reallocated_memory_block
 *         or NULL or ptr.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *Smem;
	char *Sptr_copy, *Sfiller;
	unsigned int Sindex;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		Smem = malloc(new_size);
		if (Smem == NULL)
			return (NULL);

		return (Smem);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	Sptr_copy = ptr;
	Smem = malloc(sizeof(*Sptr_copy) * new_size);
	if (Smem == NULL)
	{
		free(ptr);
		return (NULL);
	}

	Sfiller = Smem;

	for (Sindex = 0; Sindex < old_size && Sindex < new_size; Sindex++)
		Sfiller[Sindex] = *Sptr_copy++;

	free(ptr);
	return (Smem);
}

