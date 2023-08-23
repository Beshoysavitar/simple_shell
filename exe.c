#include "shell.h"
/**
 * exe - executes the command
 * @argv: command to run
 * Return: 0 on success1 -1 if cmd is exit and 1 on any other error
 */
void exe(char **argv)
{
	char *comm = NULL, *act_comm = NULL;

	if (argv)
	{
		comm = argv[0];
		act_comm = get_path(comm);
		if (execve(act_comm, argv, NULL) == -1)
		{
			perror("Error");
		}
	}
}
