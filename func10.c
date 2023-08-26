#include "shell.h"

/**
 * mmcy - ***
 * @nwptrooi: ***
 * @ptrooiii: ***
 * @siziooiii: ***
 *
 * Return: **
 */
void mmcy(void *nwptrooi, const void *ptrooiii, unsigned int siziooiii)
{
	char *char_newptr = (char *)nwptrooi;
	unsigned int x;
	char *cr_ptrooi = (char *)ptrooiii;

	for (x = 0; x < siziooiii; x++)
		char_newptr[x] = cr_ptrooi[x];
}

/**
 * reloc - ***
 * @ptrooiii: ***
 * @od_siziooiii: ***
 * @nw_siziooiii: ***
 *
 * Return: ***
 */
void *reloc(void *ptrooiii, unsigned int od_siziooiii, unsigned int nw_siziooiii)
{
	void *nwptrooi;

	if (ptrooiii == NULL)
		return (malloc(nw_siziooiii));
	if (nw_siziooiii == 0)
	{
		free(ptrooiii);
		return (NULL);
	}
	if (nw_siziooiii == od_siziooiii)
	{
		return (ptrooiii);
	}
	nwptrooi = malloc(nw_siziooiii);
	if (nwptrooi == NULL)
	{
		return (NULL);
	}
	if (nw_siziooiii < od_siziooiii)
	{
		mmcy(nwptrooi, ptrooiii, nw_siziooiii);
	}
	else
	{
		mmcy(nwptrooi, ptrooiii, od_siziooiii);
	}

	free(ptrooiii);
	return (nwptrooi);
}

/**
 * relocdp - ***
 * @ptrooiii: ***
 * @od_siziooiii: ***
 * @nw_siziooiii: ***
 *
 * Return: ***
 */
char **relocdp(char **ptrooiii, unsigned int od_siziooiii, unsigned int nw_siziooiii)
{
	unsigned int x;
	char **nwptrooi;

	if (ptrooiii == NULL)
	{
		return (malloc(sizeof(char *) * nw_siziooiii));
	}
	if (nw_siziooiii == od_siziooiii)
	{
		return (ptrooiii);
	}
	nwptrooi = malloc(sizeof(char *) * nw_siziooiii);
	if (nwptrooi == NULL)
	{
		return (NULL);
	}
	for (x = 0; x < od_siziooiii; x++)
	{
		nwptrooi[x] = ptrooiii[x];
	}
	free(ptrooiii);

	return (nwptrooi);
}
/**
 * a_rvar_n - ***
 * @hd: ***
 * @lvar: ***
 * @val: ***
 * @lval: ***
 * Return: ***
 */
r_var *a_rvar_n(r_var **hd, int lvar, char *val, int lval)
{
	r_var *new, *temooi;

	new = malloc(sizeof(r_var));
	if (new == NULL)
	{
		return (NULL);
	}
	new->len_var = lvar;
	new->val = val;
	new->len_val = lval;

	new->next = NULL;
	temooi = *hd;

	if (temooi == NULL)
	{
		*hd = new;
	}
	else
	{
		while (temooi->next != NULL)
			temooi = temooi->next;
		temooi->next = new;
	}
	return (*hd);
}

/**
 * f_rvar_l - ***
 * @hd: ***
 * Return: ***
 */
void f_rvar_l(r_var **hd)
{
	r_var *temooi;
	r_var *currooi;

	if (hd != NULL)
	{
		currooi = *hd;
		while ((temooi = currooi) != NULL)
		{
			currooi = currooi->next;
			free(temooi);
		}
		*hd = NULL;
	}
}
