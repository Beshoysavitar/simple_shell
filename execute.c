#include "shell.h"
/**
 * execute - ***
 * @args: ***
 *
 * Return: ***
 */
int execute(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		return (0);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		for (char **env = environ; *env != NULL; env++)
		{
			printf("%s\n", *env);
		}
		return (1);
	}
	else
	{
		return (execve(args[0], args, environ));
	}
}
