#include "shell.h"

/**
 * _c_ifo - ***
 * @naee: ***
 * @valooo: ***
 *
 * Return: ***
 */
char *_c_ifo(char *naee, char *valooo)
{
	int ln_naoo, ln_valoo, len;
	char *neoo;

	ln_naoo = sren(naee);
	ln_valoo = sren(valooo);
	len = ln_naoo + ln_valoo + 2;
	neoo = malloc(sizeof(char) * (len));
	stcp(neoo, naee);
	stca(neoo, "=");
	stca(neoo, valooo);
	stca(neoo, "\0");

	return (neoo);
}

/**
 * ___set_env - ***
 *
 * @naee: ***
 * @valooo: ***
 * @ash: ***
 * Return: ***
 */
void ___set_env(char *naee, char *valooo, d_sh *ash)
{
	char *vr_envoo, *nme_envoo;
	int x;

	for (x = 0; ash->_environ[x]; x++)
	{
		vr_envoo = stup(ash->_environ[x]);
		nme_envoo = sttok(vr_envoo, "=");
		if (srcm(nme_envoo, naee) == 0)
		{
			free(ash->_environ[x]);
			ash->_environ[x] = _c_ifo(nme_envoo, valooo);
			free(vr_envoo);
			return;
		}
		free(vr_envoo);
	}

	ash->_environ = relocdp(ash->_environ, x, sizeof(char *) * (x + 2));
	ash->_environ[x] = _c_ifo(naee, valooo);
	ash->_environ[x + 1] = NULL;
}

/**
 * ____setenv - ***
 * with ***
 * @ash: ***
 *
 * Return: ***
 */
int ____setenv(d_sh *ash)
{

	if (ash->args[1] == NULL || ash->args[2] == NULL)
	{
		_gt_errr(ash, -1);
		return (1);
	}
	___set_env(ash->args[1], ash->args[2], ash);

	return (1);
}

/**
 * ____unsetenv - ***
 * @ash: ***
 * Return: ***
 */
int ____unsetenv(d_sh *ash)
{
	char **rlloc_envooo;
	char *vr_envoo, *nme_envoo;
	int x, u, poee;

	if (ash->args[1] == NULL)
	{
		_gt_errr(ash, -1);
		return (1);
	}
	poee = -1;
	for (x = 0; ash->_environ[x]; x++)
	{
		vr_envoo = stup(ash->_environ[x]);
		nme_envoo = sttok(vr_envoo, "=");
		if (srcm(nme_envoo, ash->args[1]) == 0)
		{
			poee = x;
		}
		free(vr_envoo);
	}
	if (poee == -1)
	{
		_gt_errr(ash, -1);
		return (1);
	}
	rlloc_envooo = malloc(sizeof(char *) * (x));
	for (x = u = 0; ash->_environ[x]; x++)
	{
		if (x != poee)
		{
			rlloc_envooo[u] = ash->_environ[x];
			u++;
		}
	}
	rlloc_envooo[u] = NULL;
	free(ash->_environ[poee]);
	free(ash->_environ);
	ash->_environ = rlloc_envooo;
	return (1);
}
