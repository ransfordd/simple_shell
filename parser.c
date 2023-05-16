#include "shell.h"

/**
 * is_cmd - this determines if a file is an executable command
 * @info: the info struct
 * @path: the path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - this duplicates characters
 * @pathstr: the PATH string
 * @start: the starting index
 * @stop: the stopping index
 *
 * Return: pointer to new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int r = 0, f = 0;

	for (f = 0, r = start; r < stop; r++)
		if (pathstr[r] != ':')
			buf[f++] = pathstr[r];
	buf[f] = 0;
	return (buf);
}

/**
 * find_path - this finds this cmd in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int r = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[r] || pathstr[r] == ':')
		{
			path = dup_chars(pathstr, curr_pos, r);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[r])
				break;
			curr_pos = r;
		}
		r++;
	}
	return (NULL);
}
