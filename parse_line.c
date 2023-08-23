#include "shell.h"
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
