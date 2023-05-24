#include "shell.h"

/**
 * _strspn - to get the length of a prefix
 *
 * @s: pointer to str input
 * @accept: substr prefix
 *
 * Return: a nums of bytes in the init segment
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int k, a;

	for (k = 0; s[k]; k++)
	{
		for (a = 0; accept[a]; a++)
		{
			if (s[k] == accept[a])
				break;
		}
		if (!accept[a])
			return (k);
	}

	return (k);
}
/**
 * _strcpy - to copy string
 * @dest: dest
 * @src: src
 *
 * Return: ptr to dest
 */
char *_strcpy(char *dest, char *src)
{
	int k = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[k])
	{
		dest[k] = src[k];
		k++;
	}
	dest[k] = 0;
	return (dest);
}
/**
 *_putchar - to write the char to stdout
 * @c: char
 * Return: 1 (success).
 *         -1 On error,
 *          errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strdup - to duplicate any str
 * @str: string
 *
 * Return: pointer to duplicated str
 */
char *_strdup(const char *str)
{
	int sim_length = 0;
	char *sim_ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		sim_length++;
	sim_ret = malloc(sizeof(char) * (sim_length + 1));
	if (!sim_ret)
		return (NULL);
	for (sim_length++; sim_length--;)
		sim_ret[sim_length] = *--str;
	return (sim_ret);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, const char *src)
{
	char *sim_ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (sim_ret);
}
