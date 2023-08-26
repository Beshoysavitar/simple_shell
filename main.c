#include "shell.h"

/**
 * free_data - ***
 *
 * @asuu: ***
 * Return: ***
 */
void free_data(d_sh *asuu)
{
	unsigned int x;

	for (x = 0; asuu->_environ[x]; x++)
	{
		free(asuu->_environ[x]);
	}

	free(asuu->_environ);
	free(asuu->pid);
}

/**
 * set_data - ***
 * @asuu: ***
 * @av: ***
 * Return: ***
 */
void set_data(d_sh *asuu, char **av)
{
	unsigned int x;

	asuu->av = av;
	asuu->input = NULL;
	asuu->args = NULL;
	asuu->status = 0;
	asuu->counter = 1;

	for (x = 0; environ[x]; x++)
		;

	asuu->_environ = malloc(sizeof(char *) * (x + 1));

	for (x = 0; environ[x]; x++)
	{
		asuu->_environ[x] = stup(environ[x]);
	}

	asuu->_environ[x] = NULL;
	asuu->pid = _ax_itoo(getpid());
}

/**
 * main - ***
 *
 * @ac: ***
 * @av: ***
 *
 * Return: ***
 */
int main(int ac, char **av)
{
	d_sh asuu;
	(void) ac;

	signal(SIGINT, _gt_sigi);
	set_data(&asuu, av);
	shell_loop(&asuu);
	free_data(&asuu);
	if (asuu.status < 0)
		return (255);
	return (asuu.status);
}
