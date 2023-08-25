#include "shell.h"

/**
* han - ***
* @y: ***
* @l: ***
*
* Return: ***
*/
int han(char **y, char *l)
{
	struct buil buil = {"env", "exit"};

	if (sc(*y, buil.env) == 0)
	{
		pri();
		return (1);
	}
	else if (sc(*y, buil.exit) == 0)
	{
		ex(y, l);
		return (1);
	}
	return (0);
}

/**
 *ha- ***
 *@m: ***
 *Return: ***
 */

void ha(int m)
{
	(void)m;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}


/**
* fin - ***
* Return: ***
*/
char *fin(void)
{
	int x;
	char **env = environ, *w = NULL;

	while (*env)
	{
		if (sn(*env, "PATH=", 5) == 0)
		{
			w = *env;
			while (*w && x < 5)
			{
				w++;
				x++;
			}
			return (w);
		}
		env++;
	}
	return (NULL);
}


/**
* pri - ***
*
* Return: ***
*/
void pri(void)
{
	int x = 0;
	char **env = environ;

	while (env[x])
	{
		write(STDOUT_FILENO, (const void *)env[x], sl(env[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}

/**
* _putchar - ***
* @c: ***
*
* Return: ***
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
