#ifndef _SHELL_
#define _SHELL_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
void get_line(char *line, size_t size);
void parse_line(char *line, char **args);
int execute(char **args);
#endif
