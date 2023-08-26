#include "shell.h"

/**
 * add_se_end - ***
 * @hd: ***
 * @sep: ***
 * Return: ***
 */
sep_list *add_se_end(sep_list **hd, char sep)
{
	sep_list *neoooi, *temooi;

	neoooi = malloc(sizeof(sep_list));
	if (neoooi == NULL)
	{
		return (NULL);
	}
	neoooi->separator = sep;
	neoooi->next = NULL;
	temooi = *hd;

	if (temooi == NULL)
	{
		*hd = neoooi;
	}
	else
	{
		while (temooi->next != NULL)
			temooi = temooi->next;
		temooi->next = neoooi;
	}

	return (*hd);
}

/**
 * fre_se_l - ***
 * @hd: ***
 * Return: ***
 */
void fre_se_l(sep_list **hd)
{
	sep_list *temooi;
	sep_list *curr;

	if (hd != NULL)
	{
		curr = *hd;
		while ((temooi = curr) != NULL)
		{
			curr = curr->next;
			free(temooi);
		}
		*hd = NULL;
	}
}

/**
 * a_l_n_e - ***
 * @hd: ***
 * @line: ***
 * Return: ***
 */
lin_l *a_l_n_e(lin_l **hd, char *line)
{
	lin_l *neoooi, *temooi;

	neoooi = malloc(sizeof(lin_l));
	if (neoooi == NULL)
	{
		return (NULL);
	}
	neoooi->line = line;
	neoooi->next = NULL;
	temooi = *hd;

	if (temooi == NULL)
	{
		*hd = neoooi;
	}
	else
	{
		while (temooi->next != NULL)
			temooi = temooi->next;
		temooi->next = neoooi;
	}

	return (*hd);
}

/**
 * f_l_l - ***
 * @hd: ***
 * Return: ***
 */
void f_l_l(lin_l **hd)
{
	lin_l *temooi;
	lin_l *curr;

	if (hd != NULL)
	{
		curr = *hd;
		while ((temooi = curr) != NULL)
		{
			curr = curr->next;
			free(temooi);
		}
		*hd = NULL;
	}
}
/**
 * _helpoi - ***
 * Return: ***
 */
void _helpoi(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help, sren(help));
	help = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, help, sren(help));
	help = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, help, sren(help));
}
