#include "shell.h"

/**
 * wout_comm - ***
 * @in: ***
 * Return: ***
 */
char *wout_comm(char *in)
{
	int x, u_tooooi;

	u_tooooi = 0;
	for (x = 0; in[x]; x++)
	{
		if (in[x] == '#')
		{
			if (x == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[x - 1] == ' ' || in[x - 1] == '\t' || in[x - 1] == ';')
				u_tooooi = x;
		}
	}
	if (u_tooooi != 0)
	{
		in = reloc(in, x, u_tooooi + 1);
		in[u_tooooi] = '\0';
	}
	return (in);
}

/**
 * shell_loop - ***
 * @ash: ***
 *
 * Return: ***
 */
void shell_loop(d_sh *ash)
{
	char *npooi;
	int loooi, x_eoooi;

	loooi = 1;
	while (loooi == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		npooi = rea_line(&x_eoooi);
		if (x_eoooi != -1)
		{
			npooi = wout_comm(npooi);
			if (npooi == NULL)
				continue;

			if (cck_synta_err(ash, npooi) == 1)
			{
				ash->status = 2;
				free(npooi);
				continue;
			}
			npooi = rep_va(npooi, ash);
			loooi = spl_conds(ash, npooi);
			ash->counter += 1;
			free(npooi);
		}
		else
		{
			loooi = 0;
			free(npooi);
		}
	}
}
/**
 * cmp_env_name - ***
 * @nvooi: ***
 * @namiooi: ***
 *
 * Return: ***
 */
int cmp_env_name(const char *nvooi, const char *namiooi)
{
	int x;

	for (x = 0; nvooi[x] != '='; x++)
	{
		if (nvooi[x] != namiooi[x])
		{
			return (0);
		}
	}
	return (x + 1);
}

/**
 * gtenv - ***
 * @namiooi: ***
 * @_environ: ***
 *
 * Return: ***
 */
char *gtenv(const char *namiooi, char **_environ)
{
	int x, movooi;
	char *pr_envppoi;

	pr_envppoi = NULL;
	movooi = 0;
	for (x = 0; _environ[x]; x++)
	{
		movooi = cmp_env_name(_environ[x], namiooi);
		if (movooi)
		{
			pr_envppoi = _environ[x];
			break;
		}
	}
	return (pr_envppoi + movooi);
}

/**
 * ___env - ***
 *
 * @ash: ***
 * Return: ***
 */
int ___env(d_sh *ash)
{
	int x, y;

	for (x = 0; ash->_environ[x]; x++)
	{

		for (y = 0; ash->_environ[x][y]; y++)
			;

		write(STDOUT_FILENO, ash->_environ[x], y);
		write(STDOUT_FILENO, "\n", 1);
	}
	ash->status = 0;

	return (1);
}
