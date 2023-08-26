#include "shell.h"

/**
 * swp_char - ***
 *
 * @input: ***
 * @iobolooi: ***
 * Return: ***
 */
char *swp_char(char *input, int iobolooi)
{
	int x;

	if (iobolooi == 0)
	{
		for (x = 0; input[x]; x++)
		{
			if (input[x] == '|')
			{
				if (input[x + 1] != '|')
					input[x] = 16;
				else
					x++;
			}

			if (input[x] == '&')
			{
				if (input[x + 1] != '&')
					input[x] = 12;
				else
					x++;
			}
		}
	}
	else
	{
		for (x = 0; input[x]; x++)
		{
			input[x] = (input[x] == 16 ? '|' : input[x]);
			input[x] = (input[x] == 12 ? '&' : input[x]);
		}
	}
	return (input);
}

/**
 * ad_noes - ***
 *
 * @head_s: ***
 * @head_l: ***
 * @input: ***
 * Return: ***
 */
void ad_noes(sep_list **head_s, lin_l **head_l, char *input)
{
	char *line;
	int x;

	input = swp_char(input, 0);

	for (x = 0; input[x]; x++)
	{
		if (input[x] == ';')
			add_se_end(head_s, input[x]);

		if (input[x] == '|' || input[x] == '&')
		{
			add_se_end(head_s, input[x]);
			x++;
		}
	}
	line = sttok(input, ";|&");
	do {
		line = swp_char(line, 1);
		a_l_n_e(head_l, line);
		line = sttok(NULL, ";|&");
	} while (line != NULL);
}

/**
 * go_nt - ***
 *
 * @list_s: ***
 * @list_l: ***
 * @ash: ***
 * Return: ***
 */
void go_nt(sep_list **list_s, lin_l **list_l, d_sh *ash)
{
	sep_list *ls_s;
	lin_l *ls_l;
	int loooisep;

	loooisep = 1;
	ls_s = *list_s;
	ls_l = *list_l;

	while (ls_s != NULL && loooisep)
	{
		if (ash->status == 0)
		{
			if (ls_s->separator == '&' || ls_s->separator == ';')
				loooisep = 0;
			if (ls_s->separator == '|')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		else
		{
			if (ls_s->separator == '|' || ls_s->separator == ';')
				loooisep = 0;
			if (ls_s->separator == '&')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		if (ls_s != NULL && !loooisep)
			ls_s = ls_s->next;
	}
	*list_s = ls_s;
	*list_l = ls_l;
}

/**
 * spl_conds - ***
 *
 * @ash: ***
 * @input: ***
 * Return: ***
 */
int spl_conds(d_sh *ash, char *input)
{

	sep_list *head_s, *list_s;
	lin_l *head_l, *list_l;
	int laoppoi;

	head_s = NULL;
	head_l = NULL;

	ad_noes(&head_s, &head_l, input);

	list_s = head_s;
	list_l = head_l;

	while (list_l != NULL)
	{
		ash->input = list_l->line;
		ash->args = spl_le(ash->input);
		laoppoi = exe_li(ash);
		free(ash->args);

		if (laoppoi == 0)
			break;

		go_nt(&list_s, &list_l, ash);

		if (list_l != NULL)
			list_l = list_l->next;
	}
	fre_se_l(&head_s);
	f_l_l(&head_l);

	if (laoppoi == 0)
		return (0);
	return (1);
}

/**
 * spl_le - ***
 *
 * @input: ***
 * Return: ***
 */
char **spl_le(char *input)
{
	char **toks;
	char *tok;
	size_t bize;
	size_t x;

	bize = TOK_BUFSIZE;
	toks = malloc(sizeof(char *) * (bize));
	if (toks == NULL)
	{
		write(STDERR_FILENO, ": allocation erroooi\n", 18);
		exit(EXIT_FAILURE);
	}

	tok = sttok(input, TOK_DELIM);
	toks[0] = tok;

	for (x = 1; tok != NULL; x++)
	{
		if (x == bize)
		{
			bize += TOK_BUFSIZE;
			toks = relocdp(toks, x, sizeof(char *) * bize);
			if (toks == NULL)
			{
				write(STDERR_FILENO, ": allocation erroooi\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		tok = sttok(NULL, TOK_DELIM);
		toks[x] = tok;
	}

	return (toks);
}
