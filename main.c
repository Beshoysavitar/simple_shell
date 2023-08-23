#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void get_line(char *line, size_t size);
void parse_line(char *line, char **args);
int execute(char **args);
/**
 * main - ***
 *
 * Return: ***
 */
int main()
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

	return 0;
}
/**
 * get_line - ***
 * @line: ***
 * @size: ***
 *
 * Return: ***
 */
void get_line(char *line, size_t size)
{
	printf("$ ");
	getline(line, &size, stdin);
}
/**
 * parse_line - ***
 * @line: ***
 * @args: ***
 *
 * Return: ***
 */
void parse_line(char *line, char **args)
{
	int i = 0;
	for (char *token = strtok(line, " "); token != NULL; token = strtok(NULL, " "))
	{
		args[i] = token;
		i++;
	}
	args[i] = NULL;
}
/**
 * main - ***
 * @args: ***
 *
 * Return: ***
 */
int execute(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		return 0;
	}
	else if (strcmp(args[0], "env") == 0)
	{
		for (char **env = environ; *env != NULL; env++)
		{
			printf("%s\n", *env);
		}
		return 1;
	}
	else
	{
		return execve(args[0], args, environ);
	}
}
