#include "shell.h"
/**
 * _strlen - ***
 * @q: ***
 * Return: ***
*/


int _strlen(const char *q)
{
int x = 0;
while (q[x])
	x++;

return (x);
}


/**
 * *_strcpy -  ***
 * @i: ***
 * @s: ***
 * Description: ***
 * Return: ***
 */

char *_strcpy(char *i, const char *s)
{
	int x = -1;

	do {
		x++;
		i[x] = s[x];
	} while (s[x] != '\0');

	return (i);
}
