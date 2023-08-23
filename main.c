#include "shell.h"
/**
 * main - ***
 *
 * Return: ***
 */
int main(void)
{
	char *line;
	char **args;
	int status;

	while (1)
	{
		get_line(line, 1024);
		if (line == NULL)
		{
			break;
		}

		parse_line(line, args);
		status = execute(args);

		free(line);
		free(args);
	}

	return (0);
}
