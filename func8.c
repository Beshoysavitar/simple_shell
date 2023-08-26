#include "shell.h"

/**
 * _help_envoo - ***
 * Return: ***
 */
void _help_envoo(void)
{
	char *hpoooii = "env: env [option] [namiooi=value] [command [args]]\n\t";

	write(STDOUT_FILENO, hpoooii, sren(hpoooii));
	hpoooii = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, hpoooii, sren(hpoooii));

}
/**
 * _help_setoo - ***
 * Return: ***
 */
void _help_setoo(void)
{

	char *hpoooii = "setenv: setenv (const char *namiooi, const char *value,";

	write(STDOUT_FILENO, hpoooii, sren(hpoooii));
	hpoooii = "int replace)\n\t";
	write(STDOUT_FILENO, hpoooii, sren(hpoooii));
	hpoooii = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, hpoooii, sren(hpoooii));
}
/**
 * _help_unsoo - ***
 * Return: ***
 */
void _help_unsoo(void)
{
	char *hpoooii = "unsetenv: unsetenv (const char *namiooi)\n\t";

	write(STDOUT_FILENO, hpoooii, sren(hpoooii));
	hpoooii = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, hpoooii, sren(hpoooii));
}


/**
 * _help_genoo - ***
 * Return: ***
 */
void _help_genoo(void)
{
	char *hpoooii = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, hpoooii, sren(hpoooii));
	hpoooii = "These commands are defined internally.Type 'hpoooii' to see the list";
	write(STDOUT_FILENO, hpoooii, sren(hpoooii));
	hpoooii = "Type 'hpoooii namiooi' to find out more about the function 'namiooi'.\n\n ";
	write(STDOUT_FILENO, hpoooii, sren(hpoooii));
	hpoooii = " alias: alias [namiooi=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, hpoooii, sren(hpoooii));
	hpoooii = "[dir]\nexit: exit [n]\n  env: env [option] [namiooi=value] [command ";
	write(STDOUT_FILENO, hpoooii, sren(hpoooii));
	hpoooii = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, hpoooii, sren(hpoooii));
	hpoooii = "unsetenv [variable]\n";
	write(STDOUT_FILENO, hpoooii, sren(hpoooii));
}
/**
 * _help_exoo - ***
 * Return: ***
 */
void _help_exoo(void)
{
	char *hpoooii = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, hpoooii, sren(hpoooii));
	hpoooii = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, hpoooii, sren(hpoooii));
	hpoooii = "statusis that of the last command executed\n";
	write(STDOUT_FILENO, hpoooii, sren(hpoooii));
}
