#include "shell.h"

/**
 * exe - ***
 * @x: ***
 * Return: ***
 */
int exe(char **x)
{

	pid_t i;
	int stat;

	if (strncmp("exit", x[0], 4) == 0)
		return (-1);

	i = fork();

	if (i == -1)
	{
		perror("Error");
		return (1);
	}
	else if (i == 0)
	{
		if (execve(x[0], x, NULL) == -1)
		{
			perror("Error");
			exit(-1);
		}
	}
	else
		wait(&stat);

	return (0);
}


/**
 * main - ***
 * @argc: ***
 * @argv: ***
 * Return: ***
 */

int main(int argc, char **argv)
{

	int i;
	char **tok;
	size_t buf = BUFSIZ;
	int p = 0;
	char *b;

	if (argc >= 2)
	{
		if (execve(argv[1], argv, NULL) == -1)
		{
			perror("Error");
			exit(-1);
		}
		return (0);
	}

	b = (char *)malloc(buf * sizeof(char));
	if (b == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}

	do {
		if (isatty(fileno(stdin)))
		{
			p = 1;
			puts("cisfun$: ");
		}

		getline(&b, &buf, stdin);
		b[_strlen(b) - 1] = '\0';
		tok = Tokens(b);
		i = exe(tok);
	} while (p && i != -1);

	return (0);
}
