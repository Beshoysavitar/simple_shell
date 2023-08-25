#include "shell.h"
/**
* main - ***
* @ac: ***
* @av: ***
* @envp: ***
* Return: ***
*/

int main(int ac, char **av, char *envp[])
{
	char *l = NULL, *pat = NULL, *w = NULL;
	char **y = NULL, **pats = NULL;
	size_t bufsize = 0;
	ssize_t linesize = 0;
	(void)envp, (void)av;
	if (ac < 1)
		return (-1);
	signal(SIGINT, ha);
	while (1)
	{
		fre(y);
		fre(pats);
		free(pat);
		pro();
		linesize = getline(&l, &bufsize, stdin);
		if (linesize < 0)
			break;
		forma.ln_count++;
		if (l[linesize - 1] == '\n')
			l[linesize - 1] = '\0';
		y = tok(l);
		if (y == NULL || *y == NULL || **y == '\0')
			continue;
		if (ch(y, l))
			continue;
		w = fin();
		pats = tok(w);
		pat = te(pats, y[0]);
		if (!pat)
			perror(av[0]);
		else
			exec(pat, y);
	}
	if (linesize < 0 && fla.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(l);
	return (0);
}
