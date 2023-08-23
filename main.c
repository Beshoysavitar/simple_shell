#include "shell.h"

/**
 * get_line - Get a line from the user.
 * @prompt: The prompt to display to the user.
 * @line: The buffer to store the line in.
 * @q: The size of the buffer.
 *
 * Return: the number of characters read, or -1 on error.
 */
static ssize_t get_line(const char *prompt, char *line, size_t q)
{
	ssize_t nchars_read;

	printf("%s", prompt);
	nchars_read = getline(&line, &q, stdin);
	if (nchars_read == -1)
	{
		perror("error");
		return (-1);
	}

	return (nchars_read);
}

/**
 * parse_line - Parse a line into an array of arguments.
 * @line: The line to parse.
 * @d: The delimiter.
 *
 * Return: an array of arguments, or NULL on error.
 */
static char **parse_line(char *line, const char *d)
{
	int x;
	int num_t = 0;
	char *t;
	char **args;

	t = strtok(line, d);
	while (t != NULL)
	{
		num_t++;
		t = strtok(NULL, d);
	}
	num_t++;
	args = malloc(sizeof(char *) * num_t);
	if (args == NULL)
	{
		perror("error");
		return (NULL);
	}

	t = strtok(line, d);
	while (t != NULL)
	{
		args[x] = malloc(sizeof(char) * strlen(t));
		strcpy(args[x], t);
		x++;
		t = strtok(NULL, d);
	}

	args[num_t - 1] = NULL;

	return (args);
}

/**
 * main - The main function of the shell.
 * @ac: The number of arguments.
 * @argv: The arguments.
 *
 * Return: 0 on success, or -1 on error.
 */
int main(int ac, char **argv)
{
	char *lin = NULL;
	char **args;
	ssize_t nchars_read;

	(void)ac;
	(void)argv;
	while (1)
	{
		nchars_read = get_line("$ ", lin, 1024);
		if (nchars_read == -1)
		{
			printf("Exiting\n");
			return (-1);
		}

		args = parse_line(lin, " \n");
		if (args == NULL)
		{
			perror("error");
			return (-1);
		}

		exe(args);

		free(args);
		free(lin);
	}

	return (0);
}
