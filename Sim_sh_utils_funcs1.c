#include "shell.h"
/**
 * _strcmp - this compares two strings.
 * @s1: first string.
 * @s2: second string.
 * Return: 0 equal,
 *         a negative if s1 is less than s2,
 *         a positive if s1 is greater than s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return ((int) (*s1) - (*s2));
}

/**
 * _strlen - length of a string
 * @s: a string to check
 *
 * Return: the length (int)
 */
int _strlen(const char *s)
{
	int k = 0;

	if (!s)
		return (0);

	while (*s++)
		k++;
	return (k);
}



/**
 * _strstr - this is to check if needle starts with haystack
 * @haystack: it searches for a string
 * @needle: it is substr to be finded
 *
 * Return: the address of char
 *         or NULL
 */
char *_strstr(char *haystack, char *needle)
{
	int k;

	/*  loop */
	for (k = 0; haystack[k] != '\0'; k++)
	{
		/* check */
		if (haystack[k] == needle[0])
		{
			int j;

			for (j = 0; needle[j] != '\0'; j++)
			{
				if (haystack[k + j] != needle[j])
				{
					break;
				}
			}
			/* check new line */
			if (needle[j] == '\0')
			{
				return (&haystack[k]);
			}
		}
	}
	return (NULL);
}

/**
 * _strncmp - Compare two strings with a limited length.
 * @s1: first string .
 * @s2: second string to compare.
 * @n: max of limited chars.
 *
 * Return: 0 if equal up to n,
 *         negative if s1 is less than s2,
 *         positive if s1 is greater than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char ch1, ch2;

	while (n-- > 0)
	{
		ch1 = (unsigned char) *s1++;
		ch2 = (unsigned char) *s2++;

		/* check equality */
		if (ch1 != ch2)
			return (ch1 - ch2);
		if (ch1 == '\0')
			break;
	}

	return (0);
}

/**
 * _strchr - to locate a char in a string
 *
 * @s: pointer to string array input
 * @c: char to find in input array
 *
 * Return: first occurence of the char
 *         or Null if not exist
*/

char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	/* check */
	if (*s == c)
		return (s);

	return (NULL);
}
