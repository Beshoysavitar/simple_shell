#include "shell.h"

/**
* sc - ***
* @e1: ***
* @e2: ***
*
* Return: ***
*/
int sc(char *e1, char *e2)
{
	int x = 0, ot;

	while (*(e1 + x) == *(e2 + x) && *(e1 + x) != '\0')
	{
		x++;
	}

	ot = (*(e1 + x) - *(e2 + x));

	return (ot);
}

/**
* sl - ***
* @s: ***
*
* Return: ***
*/
int sl(char *s)
{
	int co = 0;

	while (*s != '\0')
	{
		co++;
		s++;
	}
	return (co);
}

/**
* sn - ***
* @e1: ***
* @e2: ***
* @r: ***
*
* Return: ***
*/
int sn(char *e1, char *e2, int r)
{
	int x;

	for (x = 0; e1[x] && e2[x] && x < r; x++)
	{
		if (e1[x] != e2[x])
			return (e1[x] - e2[x]);
	}
	return (0);
}

/**
* sd - ***
* @s: ***
*
* Return: ***
*/
char *sd(char *s)
{
	char *pt;
	int x, le;

	if (s == NULL)
		return (NULL);

	le = sl(s);

	pt = malloc(sizeof(char) * (le + 1));
	if (!pt)
		return (NULL);
	for (x = 0; *s != '\0'; s++, x++)
		pt[x] = s[0];

	pt[x++] = '\0';
	return (pt);
}

/**
* sh - ***
* @s: ***
* @c: ***
*
* Return: ***
*/
char *sh(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (!c)
		return (s);
	return (NULL);
}
