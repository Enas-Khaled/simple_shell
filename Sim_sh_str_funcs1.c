#include "shell.h"


/**
 * _strlen - _strlen
 * @s: _strlen
 *
 * Return: _strlen
 */
int _strlen(const char *s)
{
	int Slength = 0;

	if (!s)
		return (Slength);
	for (Slength = 0; s[Slength]; Slength++)
		;
	return (Slength);
}

/**
 * _strcpy - _strcpy
 * @dest: _strcpy
 * @src: _strcpy.
 *
 * Return: _strcpy
 */
char *_strcpy(char *dest, const char *src)
{
	size_t Si;

	for (Si = 0; src[Si] != '\0'; Si++)
		dest[Si] = src[Si];
	dest[Si] = '\0';
	return (dest);
}

/**
 * _strcat - _strcat
 * @dest: _strcat
 * @src: _strcat
 *
 * Return: _strcat
 */
char *_strcat(char *dest, const char *src)
{
	char *SdestTemp;
	const char *SsrcTemp;

	SdestTemp = dest;
	SsrcTemp =  src;

	while (*SdestTemp != '\0')
		SdestTemp++;

	while (*SsrcTemp != '\0')
		*SdestTemp++ = *SsrcTemp++;
	*SdestTemp = '\0';
	return (dest);
}

/**
 * _strncat - _strncat
 * @dest: _strncat
 * @src: _strncat
 * @n: _strncat
 *
 * Return: P_strncat
 */
char *_strncat(char *dest, const char *src, size_t n)
{
	size_t Sdest_len = _strlen(dest);
	size_t Si;

	for (Si = 0; Si < n && src[Si] != '\0'; Si++)
		dest[Sdest_len + Si] = src[Si];
	dest[Sdest_len + Si] = '\0';

	return (dest);
}
