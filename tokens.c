#include "shell.h"

/**
 * *sp - ***
 * @i: ***
 * Return: ***
 */

unsigned int sp(char *i)
{
	int x, l = 0;

	for (x = 0; i[x] != '\0'; x++)
	{
		if (i[x]  == ' ')
			l++;
	}

	return (l);
}


/**
  *Tokens - ***
  *@i: ***
  *Return: ***
  */
char **Tokens(char *i)
{
int x = 0;
const char sep[] = " ";
int sp = _spaces(i);
char **tokens = malloc(sizeof(char *) * (sp + 1));
char *token;

if (!tokens)
{
	fprintf(stderr, "sh: allocation error\n");
	exit(1);
}

token = strtok(i, sep);

while (token != NULL)
{
	tokens[x] = token;
	token = strtok(NULL, sep);
	x++;
}
tokens[x] = NULL;

return (tokens);
}
