#include "shell.h"

/**
 **_strncpy - this copies a string
 *@dest: it is the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int r, f;
	char *s = dest;

	r = 0;
	while (src[r] != '\0' && r < n - 1)
	{
		dest[r] = src[r];
		r++;
	}
	if (r < n)
	{
		f = r;
		while (f < n)
		{
			dest[f] = '\0';
			f++;
		}
	}
	return (s);
}

/**
 **_strncat - this concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int r, f;
	char *s = dest;

	r = 0;
	f = 0;
	while (dest[r] != '\0')
		r++;
	while (src[f] != '\0' && f < n)
	{
		dest[r] = src[f];
		r++;
		f++;
	}
	if (f < n)
		dest[r] = '\0';
	return (s);
}

/**
 **_strchr - this locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
