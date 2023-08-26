#include "shell.h"

/**
 * is_cir - ***
 * @path: ***
 * @x: ***
 * Return: ***
 */
int is_cir(char *path, int *x)
{
	if (path[*x] == ':')
		return (1);

	while (path[*x] != ':' && path[*x])
	{
		*x += 1;
	}

	if (path[*x])
		*x += 1;

	return (0);
}

/**
 * is_whi - ***
 *
 * @cmd: ***
 * @_environ: ***
 * Return: ***
 */
char *is_whi(char *cmd, char **_environ)
{
	int len_dir, len_cmd, x;
	struct stat st;
	char *path, *p_poooi, *token_paoooi, *dir;

	path = gtenv("PATH", _environ);
	if (path)
	{
		p_poooi = stup(path);
		len_cmd = sren(cmd);
		token_paoooi = sttok(p_poooi, ":");
		x = 0;
		while (token_paoooi != NULL)
		{
			if (is_cir(path, &x))
				if (stat(cmd, &st) == 0)
					return (cmd);
			len_dir = sren(token_paoooi);
			dir = malloc(len_dir + len_cmd + 2);
			stcp(dir, token_paoooi);
			stca(dir, "/");
			stca(dir, cmd);
			stca(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(p_poooi);
				return (dir);
			}
			free(dir);
			token_paoooi = sttok(NULL, ":");
		}
		free(p_poooi);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &st) == 0)
			return (cmd);
	return (NULL);
}

/**
 * is_exe - ***
 *
 * @ash: ***
 * Return: ***
 */
int is_exe(d_sh *ash)
{
	struct stat st;
	int x;
	char *input;

	input = ash->args[0];
	for (x = 0; input[x]; x++)
	{
		if (input[x] == '.')
		{
			if (input[x + 1] == '.')
				return (0);
			if (input[x + 1] == '/')
				continue;
			else
				break;
		}
		else if (input[x] == '/' && x != 0)
		{
			if (input[x + 1] == '.')
				continue;
			x++;
			break;
		}
		else
			break;
	}
	if (x == 0)
		return (0);

	if (stat(input + x, &st) == 0)
	{
		return (x);
	}
	_gt_errr(ash, 127);
	return (-1);
}

/**
 * che_err_c - ***
 *
 * @dir: ***
 * @ash: ***
 * Return: ***
 */
int che_err_c(char *dir, d_sh *ash)
{
	if (dir == NULL)
	{
		_gt_errr(ash, 127);
		return (1);
	}

	if (srcm(ash->args[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			_gt_errr(ash, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(ash->args[0], X_OK) == -1)
		{
			_gt_errr(ash, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * cd_exe - ***
 *
 * @ash: ***
 * Return: ***
 */
int cd_exe(d_sh *ash)
{
	pid_t pd;
	pid_t wpd;
	int state;
	int exec;
	char *dir;
	(void) wpd;

	exec = is_exe(ash);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		dir = is_whi(ash->args[0], ash->_environ);
		if (che_err_c(dir, ash) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			dir = is_whi(ash->args[0], ash->_environ);
		else
			dir = ash->args[0];
		execve(dir + exec, ash->args, ash->_environ);
	}
	else if (pd < 0)
	{
		perror(ash->av[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	ash->status = state / 256;
	return (1);
}
