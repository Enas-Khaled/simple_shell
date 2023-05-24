#include "shell.h"
/**
 * _calloc - to allocate memory for an array (with malloc)
 *
 * @nmemb: size of array
 * @size: size of each element
 *
 * Return: ptr with new allocated memory
 *         NULL if it faild
*/

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *t;

	if (nmemb == 0 || size == 0)
		return (NULL);

	t = malloc(nmemb * size);
	if (t == NULL)
		return (NULL);

	_memset(t, 0, nmemb * size);

	return (t);
}
/**
 * _atoi - to Convert a string to an integer.
 * @str: string
 *
 * Return: integer
 */
int _atoi(const char *str)
{
	int k, sim_sign;
	unsigned int sim_num;

	k = 0;
	sim_sign = 1;
	sim_num = 0;

	while (str[k] != '\0')
	{
		if (str[k] == '-')
			sim_sign *= -1;
		else if (str[k] >= '0' && str[k] <= '9')
			sim_num = (sim_num * 10) + (str[k] - '0');
		else
			break;
		k++;
	}
	return (sim_num * sim_sign);
}

/**
 * _realloc - to reallocate block in the memory
 * @ptr: ptr to previous alloc block
 * @old_size: the size of prev block
 * @new_size: the size of new block
 *
 * Return: ptr to alloc blocK.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *tp;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	tp = malloc(new_size);
	if (!tp)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		tp[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (tp);
}


/**
 **_memset - to fill memory with a constant byte
 *@s: ptr to the memory area
 *@b: byte to fill *s with
 *@n: the no of bytes to be filled
 *Return: ptr to the memory area
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int k;

	for (k = 0; k < n; k++)
		s[k] = b;
	return (s);
}

/**
 * _memcpy - to copy a memory area
 *
 * @dest: buffer will copy to
 * @src: what to copy
 * @n: bytes of src
 *
 * Return: 0 on Success
*/

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int k;

	for (k = 0; k < n; k++)
		dest[k] = src[k];
	return (dest);
}

