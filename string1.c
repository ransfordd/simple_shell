#include "shell.h"

/**
 * _strcpy - this copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int r = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[r])
	{
		dest[r] = src[r];
		r++;
	}
	dest[r] = 0;
	return (dest);
}

/**
 * _strdup - this duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _puts - this prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int r = 0;

	if (!str)
		return;
	while (str[r] != '\0')
	{
		_putchar(str[r]);
		r++;
	}
}

/**
 * _putchar - this writes the character c to stdout
 * @c: it is the character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int r;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || r >= WRITE_BUF_SIZE)
	{
		write(1, buf, r);
		r = 0;
	}
	if (c != BUF_FLUSH)
		buf[r++] = c;
	return (1);
}
