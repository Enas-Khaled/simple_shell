#include "shell.h"

/**
 * _strchr - _strchr
 * @s: T_strchr
 * @c: _strchr
 *
 * Return: I_strchr
 */
char *_strchr(char *s, char c)
{
	int Sindex;

	for (Sindex = 0; s[Sindex]; Sindex++)
	{
		if (s[Sindex] == c)
			return (s + Sindex);
	}

	return (NULL);
}

/**
 * _strspn - _strspn
 * @s: _strspn
 * @accept: _strspn
 *
 * Return: _strspn
 */
int _strspn(char *s, char *accept)
{
	int Sbytes = 0;
	int Sindex;

	while (*s)
	{
		for (Sindex = 0; accept[Sindex]; Sindex++)
		{
			if (*s == accept[Sindex])
			{
				Sbytes++;
				break;
			}
		}
		s++;
	}
	return (Sbytes);
}

/**
 * _strcmp - _strcmp
 * @s1: _strcmp
 * @s2: T_strcmp
 *
 * Return: P_strcmp
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);

	return (0);
}

/**
 * _strncmp - _strncmp
 * @s1: _strncmp
 * @s2: _strncmp
 * @n: T_strncmp
 *
 * Return: _strncmp
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t Si;

	for (Si = 0; s1[Si] && s2[Si] && Si < n; Si++)
	{
		if (s1[Si] > s2[Si])
			return (s1[Si] - s2[Si]);
		else if (s1[Si] < s2[Si])
			return (s1[Si] - s2[Si]);
	}
	if (Si == n)
		return (0);
	else
		return (-15);
}
