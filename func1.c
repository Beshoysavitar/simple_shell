#include "shell.h"

/**
* app - ***
* @w: ***
* @y: ***
*
* Return: ***
*/
char *app(char *w, char *y)
{
	char *q;
	size_t x = 0, j = 0;

	if (y == 0)
	{
		y = "";
	}
	if (w == 0)
	{
		w = "";
	}
	q = malloc(sizeof(char) * (sl(w) + sl(y) + 2));
	if (!q)
	{
		return (NULL);
	}
	while (w[x])
	{
		q[x] = w[x];
		x++;
	}
	if (w[x - 1] != '/')
	{
		q[x] = '/';
		x++;
	}
	while (y[j])
	{
		q[x + j] = y[j];
		j++;
	}
	q[x + j] = '\0';
	return (q);
}

/**
 *ch- ***
 *@p: ***
 *@q: ***
 *Return: ***
 */
int ch(char **p, char *q)
{
	if (han(p, q))
		return (1);
	else if (**p == '/')
	{
		exec(p[0], p);
		return (1);
	}
	return (0);
}


/**
 * exec - ***
 *@cp: ***
 *@p:***
 * Return: ***
 */
void exec(char *cp, char **p)
{
	pid_t c_p;
	int stat;
	char **env = environ;

	c_p = fork();
	if (c_p < 0)
	{
		perror(cp);
	}
	if (c_p == 0)
	{
		execve(cp, p, env);
		perror(cp);
		free(cp);
		fre(p);
		exit(98);
	}
	else
		wait(&stat);
}


/**
* ex - ***
* @y: ***
* @l: ***
*
* Return: ***
*/
void ex(char **y, char *l)
{
	free(l);
	fre(y);
	exit(0);
}

/**
* fre - ***
* @q: ***
*
* Return: ***
*/
void fre(char **q)
{
	int x = 0;

	if (!q || q == NULL)
		return;
	while (q[x])
	{
		free(q[x]);
		x++;
	}
	free(q);
}
