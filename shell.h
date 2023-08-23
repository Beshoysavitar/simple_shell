#ifndef _SHELL_
#define _SHELL_


#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned int sp(char *s);
char **Tokens(char *str);
int _strlen(const char *q);
char *_strcpy(char *i, const char *s);


#endif
