#include "shell.h"

/**
 * ch_ev - ***
 *
 * @h: ***
 * @in: ***
 * @data: ***
 * Return: ***
 */
void ch_ev(r_var **h, char *in, d_sh *data)
{
	char **_envr;
	int rowooi, crooi, y, lvlooi;

	_envr = data->_environ;
	for (rowooi = 0; _envr[rowooi]; rowooi++)
	{
		for (y = 1, crooi = 0; _envr[rowooi][crooi]; crooi++)
		{
			if (_envr[rowooi][crooi] == '=')
			{
				lvlooi = sren(_envr[rowooi] + crooi + 1);
				a_rvar_n(h, y, _envr[rowooi] + crooi + 1, lvlooi);
				return;
			}

			if (in[y] == _envr[rowooi][crooi])
				y++;
			else
				break;
		}
	}
	for (y = 0; in[y]; y++)
	{
		if (in[y] == ' ' || in[y] == '\t' || in[y] == ';' || in[y] == '\n')
			break;
	}
	a_rvar_n(h, y, NULL, 0);
}
/**
 * ch_vars - ***
 *
 * @h: ***
 * @in: ***
 * @st: ***
 * @data: ***
 * Return: ***
 */
int ch_vars(r_var **h, char *in, char *st, d_sh *data)
{
	int x, ltooi, ldooi;

	ltooi = sren(st);
	ldooi = sren(data->pid);

	for (x = 0; in[x]; x++)
	{
		if (in[x] == '$')
		{
			if (in[x + 1] == '?')
				a_rvar_n(h, 2, st, ltooi), x++;
			else if (in[x + 1] == '$')
				a_rvar_n(h, 2, data->pid, ldooi), x++;
			else if (in[x + 1] == '\n')
				a_rvar_n(h, 0, NULL, 0);
			else if (in[x + 1] == '\0')
				a_rvar_n(h, 0, NULL, 0);
			else if (in[x + 1] == ' ')
				a_rvar_n(h, 0, NULL, 0);
			else if (in[x + 1] == '\t')
				a_rvar_n(h, 0, NULL, 0);
			else if (in[x + 1] == ';')
				a_rvar_n(h, 0, NULL, 0);
			else
				ch_ev(h, in + x, data);
		}
	}
	return (x);
}
/**
 * rep_it - ***
 *
 * @hd: ***
 * @input: ***
 * @nw_inpuooi: ***
 * @enooi: ***
 * Return: ***
 */
char *rep_it(r_var **hd, char *input, char *nw_inpuooi, int enooi)
{
	r_var *inxooi;
	int x, y, uy;

	inxooi = *hd;
	for (y = x = 0; x < enooi; x++)
	{
		if (input[y] == '$')
		{
			if (!(inxooi->len_var) && !(inxooi->len_val))
			{
				nw_inpuooi[x] = input[y];
				y++;
			}
			else if (inxooi->len_var && !(inxooi->len_val))
			{
				for (uy = 0; uy < inxooi->len_var; uy++)
					y++;
				x--;
			}
			else
			{
				for (uy = 0; uy < inxooi->len_val; uy++)
				{
					nw_inpuooi[x] = inxooi->val[uy];
					x++;
				}
				y += (inxooi->len_var);
				x--;
			}
			inxooi = inxooi->next;
		}
		else
		{
			nw_inpuooi[x] = input[y];
			y++;
		}
	}

	return (nw_inpuooi);
}

/**
 * rep_va - ***
 *
 * @input: ***
 * @ash: ***
 * Return: ***
 */
char *rep_va(char *input, d_sh *ash)
{
	r_var *hd, *inxooi;
	char *status, *nw_inpuooi;
	int olen, enooi;

	status = _ax_itoo(ash->status);
	hd = NULL;

	olen = ch_vars(&hd, input, status, ash);

	if (hd == NULL)
	{
		free(status);
		return (input);
	}
	inxooi = hd;
	enooi = 0;

	while (inxooi != NULL)
	{
		enooi += (inxooi->len_val - inxooi->len_var);
		inxooi = inxooi->next;
	}
	enooi += olen;

	nw_inpuooi = malloc(sizeof(char) * (enooi + 1));
	nw_inpuooi[enooi] = '\0';

	nw_inpuooi = rep_it(&hd, input, nw_inpuooi, enooi);

	free(input);
	free(status);
	f_rvar_l(&hd);

	return (nw_inpuooi);
}
/**
 * bri_li - ***
 * @liptrooooi: ***
 * @buffer: ***
 * @n: ***
 * @y: ***
 */
void bri_li(char **liptrooooi, size_t *n, char *buffer, size_t y)
{

	if (*liptrooooi == NULL)
	{
		if  (y > BUFSIZE)
			*n = y;

		else
			*n = BUFSIZE;
		*liptrooooi = buffer;
	}
	else if (*n < y)
	{
		if (y > BUFSIZE)
			*n = y;
		else
			*n = BUFSIZE;
		*liptrooooi = buffer;
	}
	else
	{
		stcp(*liptrooooi, buffer);
		free(buffer);
	}
}
