#include "shell.h"

/**
 * stca - ****
 * @dest: ***
 * @src: ***
 * Return: ***
 */
char *stca(char *dest, const char *src)
{
	int x;
	int yy;

	for (x = 0; dest[x] != '\0'; x++)
		;
	for (yy = 0; src[yy] != '\0'; yy++)
	{
		dest[x] = src[yy];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}
/**
 * *stcp - ***
 * @dest: ***
 * @src: ***
 * Return: ***
 */
char *stcp(char *dest, char *src)
{
	size_t wq;

	for (wq = 0; src[wq] != '\0'; wq++)
	{
		dest[wq] = src[wq];
	}
	dest[wq] = '\0';

	return (dest);
}
/**
 * srcm - ***
 * @s1: ***
 * @s2: ***
 * Return: ***
 */
int srcm(char *s1, char *s2)
{
	int x;

	for (x = 0; s1[x] == s2[x] && s1[x]; x++)
		;
	if (s1[x] > s2[x])
		return (1);
	if (s1[x] < s2[x])
		return (-1);
	return (0);
}
/**
 * srch - ***
 * @s: ***
 * @c: ***
 * Return: ***
 */
char *srch(char *s, char c)
{
	unsigned int x = 0;

	for (; *(s + x) != '\0'; x++)
		if (*(s + x) == c)
			return (s + x);
	if (*(s + x) == c)
		return (s + x);
	return ('\0');
}
/**
 * stpn - ***
 * @s: ***
 * @accept: ***
 * Return: ***
 */
int stpn(char *s, char *accept)
{
	int x, yy, iobolooi;

	for (x = 0; *(s + x) != '\0'; x++)
	{
		iobolooi = 1;
		for (yy = 0; *(accept + yy) != '\0'; yy++)
		{
			if (*(s + x) == *(accept + yy))
			{
				iobolooi = 0;
				break;
			}
		}
		if (iobolooi == 1)
			break;
	}
	return (x);
}
