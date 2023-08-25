#include "shell.h"
/**
* print_s - ***
* @s: ***
*
* Return: ***
*/
int print_s(char *s)
{
	int x = 0;

	while (s[x] != '\0')
	{
		_putchar(s[x]);
		x++;
	}
	return (x);
}


/**
* pro - ***
* Return: ***
*/
void pro(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		fla.interactive = 1;
	if (fla.interactive)
		write(STDERR_FILENO, "$ ", 2);
}

/**
* te - ***
* @w: ***
* @y: ***
*
* Return: ***
*/
char *te(char **w, char *y)
{
	char *op;
	int x = 0;

	while (w[x])
	{
		op = app(w[x], y);
		if (access(op, F_OK | X_OK) == 0)
			return (op);
		free(op);
		x++;
	}
	return (NULL);
}


/**
* tok - ***
* @l: ***
*
* Return: ***
*/
char **tok(char *l)
{
	char **tks = NULL;
	int tksz = 1;
	char *q = NULL, *bufpo = NULL, *tk = NULL, *del = " :\t\r\n";
	size_t id = 0, flag = 0;

	q = sd(l);
	if (!q)
		return (NULL);
	bufpo = q;

	while (*bufpo)
	{
		if (sh(del, *bufpo) != NULL && flag == 0)
		{
			tksz++;
			flag = 1;
		}
		else if (sh(del, *bufpo) == NULL && flag == 1)
			flag = 0;
		bufpo++;
	}
	tks = malloc(sizeof(char *) * (tksz + 1));
	tk = strtok(q, del);
	while (tk)
	{
		tks[id] = sd(tk);
		if (tks[id] == NULL)
		{
			free(tks);
			return (NULL);
		}
		tk = strtok(NULL, del);
		id++;
	}
	tks[id] = '\0';
	free(q);
	return (tks);
}
