#include "shell.h"

/**
 * stup - ***
 * @s: ***
 * Return: ***
 */
char *stup(const char *s)
{
	char *neooi;
	size_t lnooi;

	lnooi = sren(s);
	neooi = malloc(sizeof(char) * (lnooi + 1));
	if (neooi == NULL)
	{
		return (NULL);
	}
	mmcy(neooi, s, lnooi + 1);
	return (neooi);
}

/**
 * sren - ***
 * @s: ***
 * Return: ***
 */
int sren(const char *s)
{
	int lnooi;

	for (lnooi = 0; s[lnooi] != 0; lnooi++)
	{
	}
	return (lnooi);
}

/**
 * cp_chrs - ***
 * @str: ***
 * @delim: ***
 *
 * Return: ***
 */
int cp_chrs(char str[], const char *delim)
{
	unsigned int x, yy, uu;

	for (x = 0, uu = 0; str[x]; x++)
	{
		for (yy = 0; delim[yy]; yy++)
		{
			if (str[x] == delim[yy])
			{
				uu++;
				break;
			}
		}
	}
	if (x == uu)
		return (1);
	return (0);
}

/**
 * sttok - ***
 * @str: ***
 * @delim: ***
 *
 * Return: ***
 */
char *sttok(char str[], const char *delim)
{
	char *str_start;
	unsigned int x, iobolooi;
	static char *slitooi, *str_end;

	if (str != NULL)
	{
		if (cp_chrs(str, delim))
			return (NULL);
		slitooi = str;
		x = sren(str);
		str_end = &str[x];
	}
	str_start = slitooi;
	if (str_start == str_end)
		return (NULL);
	for (iobolooi = 0; *slitooi; slitooi++)
	{
		if (slitooi != str_start)
			if (*slitooi && *(slitooi - 1) == '\0')
				break;
		for (x = 0; delim[x]; x++)
		{
			if (*slitooi == delim[x])
			{
				*slitooi = '\0';
				if (slitooi == str_start)
					str_start++;
				break;
			}
		}
		if (iobolooi == 0 && *slitooi)
			iobolooi = 1;
	}
	if (iobolooi == 0)
		return (NULL);
	return (str_start);
}

/**
 * sdiit - ***
 *
 * @s: ***
 * Return: ***
 */
int sdiit(const char *s)
{
	unsigned int x;

	for (x = 0; s[x]; x++)
	{
		if (s[x] < 48 || s[x] > 57)
			return (0);
	}
	return (1);
}
