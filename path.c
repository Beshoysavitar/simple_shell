#include "shell.h"
/**
 * get_path - ***
 * @comm: ***
 * Return: ***
 */
char *get_path(char *comm)
{
	int comm_l, dir_len;
	char *p, *p_c, *p_t, *f_p;
	struct stat buffer;

	p = getenv("PATH");

	if (p)
	{
		p_c = strdup(p);
		comm_l = strlen(comm);
		p_t = strtok(p_c, ":");

		while (p_t != NULL)
		{
			dir_len = strlen(p_t);
			f_p = malloc(comm_l + dir_len + 2);
			strcpy(f_p, p_t);
			strcat(f_p, "/");
			strcat(f_p, comm);
			strcat(f_p, "\0");
			if (stat(f_p, &buffer) == 0)
			{
				free(p_c);
				return (f_p);
			}
			else
			{
				free(f_p);
				p_t = strtok(NULL, ":");
			}
		}
		free(p_c);
		if (stat(comm, &buffer) == 0)
		{
			return (comm);
		}
		return (NULL);
	}
	return (NULL);
}
