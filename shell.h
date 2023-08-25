#ifndef SHELL_H
#define SHELL_H


#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
struct buil
{
	char *env;
	char *exit;
} buil;
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);
struct forma
{
	int final_exit;
	int ln_count;
} forma;
int sc(char *e1, char *e2);
int sl(char *s);
int sn(char *e1, char *e2, int n);
char *sd(char *s);
char *sh(char *s, char c);
void exec(char *cp, char **p);
int ch(char **p, char *q);
void pro(void);
void ha(int m);
char **tok(char *l);
char *fin(void);
void fre(char **q);
char *te(char **w, char *y);
char *app(char *w, char *y);
int han(char **y, char *l);
void ex(char **y, char *l);
void pri(void);
int _putchar(char c);
struct fla
{
	bool interactive;
} fla;
#endif
