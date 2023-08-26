#include "shell.h"

/**
 * ___cd_dot - ***
 *
 * @ash: ***
 *
 * Return: ***
 */
void ___cd_dot(d_sh *ash)
{
	char *dir, *cp_pwd, *cp_str_p_ooi;
	char pdoooooi[PATH_MAX];

	getcwd(pdoooooi, sizeof(pdoooooi));
	cp_pwd = stup(pdoooooi);
	___set_env("OLDPWD", cp_pwd, ash);
	dir = ash->args[1];
	if (srcm(".", dir) == 0)
	{
		___set_env("PWD", cp_pwd, ash);
		free(cp_pwd);
		return;
	}
	if (srcm("/", cp_pwd) == 0)
	{
		free(cp_pwd);
		return;
	}
	cp_str_p_ooi = cp_pwd;
	ev_stg(cp_str_p_ooi);
	cp_str_p_ooi = sttok(cp_str_p_ooi, "/");
	if (cp_str_p_ooi != NULL)
	{
		cp_str_p_ooi = sttok(NULL, "\0");

		if (cp_str_p_ooi != NULL)
			ev_stg(cp_str_p_ooi);
	}
	if (cp_str_p_ooi != NULL)
	{
		chdir(cp_str_p_ooi);
		___set_env("PWD", cp_str_p_ooi, ash);
	}
	else
	{
		chdir("/");
		___set_env("PWD", "/", ash);
	}
	ash->status = 0;
	free(cp_pwd);
}

/**
 * __ced_to - ***
 * @ash: ***
 * Return: ***
 */
void __ced_to(d_sh *ash)
{
		char *dir, *cp_pwd, *cp_dir;
	char pdoooooi[PATH_MAX];

	getcwd(pdoooooi, sizeof(pdoooooi));

	dir = ash->args[1];
	if (chdir(dir) == -1)
	{
		_gt_errr(ash, 2);
		return;
	}
	cp_pwd = stup(pdoooooi);
	___set_env("OLDPWD", cp_pwd, ash);

	cp_dir = stup(dir);
	___set_env("PWD", cp_dir, ash);

	free(cp_pwd);
	free(cp_dir);

	ash->status = 0;

	chdir(dir);
}

/**
 * ___ced_previous - ***
 *
 * @ash: ***
 * Return: ***
 */
void ___ced_previous(d_sh *ash)
{
	char pdoooooi[PATH_MAX];
	char *p_pwd, *p_oldpwd, *cp_pwd, *cp_oldpwd;

	getcwd(pdoooooi, sizeof(pdoooooi));
	cp_pwd = stup(pdoooooi);

	p_oldpwd = gtenv("OLDPWD", ash->_environ);

	if (p_oldpwd == NULL)
		cp_oldpwd = cp_pwd;
	else
		cp_oldpwd = stup(p_oldpwd);

	___set_env("OLDPWD", cp_pwd, ash);

	if (chdir(cp_oldpwd) == -1)
		___set_env("PWD", cp_pwd, ash);
	else
		___set_env("PWD", cp_oldpwd, ash);

	p_pwd = gtenv("PWD", ash->_environ);

	write(STDOUT_FILENO, p_pwd, sren(p_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_pwd);
	if (p_oldpwd)
		free(cp_oldpwd);

	ash->status = 0;

	chdir(p_pwd);
}

/**
 * ___ced_to_home - ***
 *
 * @ash: ***
 * Return: ***
 */
void ___ced_to_home(d_sh *ash)
{
	char *p_pwd, *home;
	char pdoooooi[PATH_MAX];

	getcwd(pdoooooi, sizeof(pdoooooi));
	p_pwd = stup(pdoooooi);

	home = gtenv("HOME", ash->_environ);

	if (home == NULL)
	{
		___set_env("OLDPWD", p_pwd, ash);
		free(p_pwd);
		return;
	}
	if (chdir(home) == -1)
	{
		_gt_errr(ash, 2);
		free(p_pwd);
		return;
	}
	___set_env("OLDPWD", p_pwd, ash);
	___set_env("PWD", home, ash);
	free(p_pwd);
	ash->status = 0;
}
/**
 * ced_shol - ***
 *
 * @ash: ***
 * Return: ***
 */
int ced_shol(d_sh *ash)
{
	char *dir;
	int ishome, ishome2, isddash;

	dir = ash->args[1];

	if (dir != NULL)
	{
		ishome = srcm("$HOME", dir);
		ishome2 = srcm("~", dir);
		isddash = srcm("--", dir);
	}
	if (dir == NULL || !ishome || !ishome2 || !isddash)
	{
		___ced_to_home(ash);
		return (1);
	}
	if (srcm("-", dir) == 0)
	{
		___ced_previous(ash);
		return (1);
	}
	if (srcm(".", dir) == 0 || srcm("..", dir) == 0)
	{
		___cd_dot(ash);
		return (1);
	}
	__ced_to(ash);

	return (1);
}
