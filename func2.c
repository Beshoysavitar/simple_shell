#include "shell.h"

/**
 * _gt_errr - ***
 * @ash: ***
 * @evaoo: ***
 * Return: ***
 */
int _gt_errr(d_sh *ash, int evaoo)
{
	char *errr;

	switch (evaoo)
	{
	case -1:
		errr = _err_envo(ash);
		break;
	case 126:
		errr = _err_pathrr(ash);
		break;
	case 127:
		errr = _err_no_foo(ash);
		break;
	case 2:
		if (srcm("exit", ash->args[0]) == 0)
			errr = _err_ex_shol(ash);
		else if (srcm("cd", ash->args[0]) == 0)
			errr = _err_g_ced(ash);
		break;
	}

	if (errr)
	{
		write(STDERR_FILENO, errr, sren(errr));
		free(errr);
	}

	ash->status = evaoo;
	return (evaoo);
}
/**
 * gt_helpooi - ***
 * @ash: ***
 * Return: ***
*/
int gt_helpooi(d_sh *ash)
{

	if (ash->args[1] == 0)
		_help_genoo();
	else if (srcm(ash->args[1], "setenv") == 0)
		_help_setoo();
	else if (srcm(ash->args[1], "env") == 0)
		_help_envoo();
	else if (srcm(ash->args[1], "unsetenv") == 0)
		_help_unsoo();
	else if (srcm(ash->args[1], "help") == 0)
		_helpoi();
	else if (srcm(ash->args[1], "exit") == 0)
		_help_exoo();
	else if (srcm(ash->args[1], "cd") == 0)
		_help_cdooi();
	else if (srcm(ash->args[1], "alias") == 0)
		_help_aliooo();
	else
		write(STDERR_FILENO, ash->args[0],
		      sren(ash->args[0]));

	ash->status = 0;
	return (1);
}
/**
 * get_builtin - ***
 * @cmd: ***
 * Return: ***
 */
int (*get_builtin(char *cmd))(d_sh *)
{
	bun_t builtin[] = {
		{ "env", ___env },
		{ "exit", ex_shol },
		{ "setenv", ____setenv },
		{ "unsetenv", ____unsetenv },
		{ "cd", ced_shol },
		{ "help", gt_helpooi },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; builtin[i].namiooi; i++)
	{
		if (srcm(builtin[i].namiooi, cmd) == 0)
			break;
	}

	return (builtin[i].f);
}
/**
 * ex_shol - ***
 *
 * @ash: ***
 * Return: ***
 */
int ex_shol(d_sh *ash)
{
	int is_ditooi;
	int ooistr_lenooi;
	int ioobig_numooi;
	unsigned int ustatusooi;

	if (ash->args[1] != NULL)
	{
		ustatusooi = atoo(ash->args[1]);
		is_ditooi = sdiit(ash->args[1]);
		ooistr_lenooi = sren(ash->args[1]);
		ioobig_numooi = ustatusooi > (unsigned int)INT_MAX;
		if (!is_ditooi || ooistr_lenooi > 10 || ioobig_numooi)
		{
			_gt_errr(ash, 2);
			ash->status = 2;
			return (1);
		}
		ash->status = (ustatusooi % 256);
	}
	return (0);
}
/**
 * exe_li - ***
 *
 * @ash: ***
 * Return: ***
 */
int exe_li(d_sh *ash)
{
	int (*builtin)(d_sh *ash);

	if (ash->args[0] == NULL)
	{
		return (1);
	}
	builtin = get_builtin(ash->args[0]);

	if (builtin != NULL)
	{
		return (builtin(ash));
	}
	return (cd_exe(ash));
}
