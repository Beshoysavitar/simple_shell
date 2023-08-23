#include "shell.h"
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
