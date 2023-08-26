#include "shell.h"

/**
 * _stat_ced - ***
 *
 * @ash: ***
 * @sgooi: ***
 * @erroooi: ***
 * @vr_stooi: ***
 * Return: ***
 */
char *_stat_ced(d_sh *ash, char *sgooi, char *erroooi, char *vr_stooi)
{
	char *illooi_flaooi;

	stcp(erroooi, ash->av[0]);
	stca(erroooi, ": ");
	stca(erroooi, vr_stooi);
	stca(erroooi, ": ");
	stca(erroooi, ash->args[0]);
	stca(erroooi, sgooi);
	if (ash->args[1][0] == '-')
	{
		illooi_flaooi = malloc(3);
		illooi_flaooi[0] = '-';
		illooi_flaooi[1] = ash->args[1][1];
		illooi_flaooi[2] = '\0';
		stca(erroooi, illooi_flaooi);
		free(illooi_flaooi);
	}
	else
	{
		stca(erroooi, ash->args[1]);
	}

	stca(erroooi, "\n");
	stca(erroooi, "\0");
	return (erroooi);
}

/**
 * _err_g_ced - ***
 * @ash: ***
 * Return: ***
 */
char *_err_g_ced(d_sh *ash)
{
	char *erroooi, *vr_stooi, *sgooi;
	int lenooiii, ln_idoi;

	vr_stooi = _ax_itoo(ash->counter);
	if (ash->args[1][0] == '-')
	{
		sgooi = ": Illegal option ";
		ln_idoi = 2;
	}
	else
	{
		sgooi = ": can't cd to ";
		ln_idoi = sren(ash->args[1]);
	}
	lenooiii = sren(ash->av[0]) + sren(ash->args[0]);
	lenooiii += sren(vr_stooi) + sren(sgooi) + ln_idoi + 5;
	erroooi = malloc(sizeof(char) * (lenooiii + 1));

	if (erroooi == 0)
	{
		free(vr_stooi);
		return (NULL);
	}
	erroooi = _stat_ced(ash, sgooi, erroooi, vr_stooi);

	free(vr_stooi);

	return (erroooi);
}

/**
 * _err_no_foo - ***
 * @ash: ***
 * Return: ***
 */
char *_err_no_foo(d_sh *ash)
{
	char *erroooi;
	char *vr_stooi;
	int lenooiii;

	vr_stooi = _ax_itoo(ash->counter);
	lenooiii = sren(ash->av[0]) + sren(vr_stooi);
	lenooiii += sren(ash->args[0]) + 16;
	erroooi = malloc(sizeof(char) * (lenooiii + 1));
	if (erroooi == 0)
	{
		free(erroooi);
		free(vr_stooi);
		return (NULL);
	}
	stcp(erroooi, ash->av[0]);
	stca(erroooi, ": ");
	stca(erroooi, vr_stooi);
	stca(erroooi, ": ");
	stca(erroooi, ash->args[0]);
	stca(erroooi, ": not found\n");
	stca(erroooi, "\0");
	free(vr_stooi);
	return (erroooi);
}

/**
 * _err_ex_shol - ***
 * @ash: ***
 * Return: ***
 */
char *_err_ex_shol(d_sh *ash)
{
	char *erroooi;
	char *vr_stooi;
	int lenooiii;

	vr_stooi = _ax_itoo(ash->counter);
	lenooiii = sren(ash->av[0]) + sren(vr_stooi);
	lenooiii += sren(ash->args[0]) + sren(ash->args[1]) + 23;
	erroooi = malloc(sizeof(char) * (lenooiii + 1));
	if (erroooi == 0)
	{
		free(vr_stooi);
		return (NULL);
	}
	stcp(erroooi, ash->av[0]);
	stca(erroooi, ": ");
	stca(erroooi, vr_stooi);
	stca(erroooi, ": ");
	stca(erroooi, ash->args[0]);
	stca(erroooi, ": Illegal number: ");
	stca(erroooi, ash->args[1]);
	stca(erroooi, "\n\0");
	free(vr_stooi);

	return (erroooi);
}
/**
 * ge_li - ***
 * @liptrooooi: ***
 * @n: ***
 * @stream: ***
 * Return: ***
 */
ssize_t ge_li(char **liptrooooi, size_t *n, FILE *stream)
{
	static ssize_t input;
	ssize_t retval;
	int x;
	char *buffooi;
	char t = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffooi = malloc(sizeof(char) * BUFSIZE);
	if (buffooi == 0)
		return (-1);
	while (t != '\n')
	{
		x = read(STDIN_FILENO, &t, 1);
		if (x == -1 || (x == 0 && input == 0))
		{
			free(buffooi);
			return (-1);
		}
		if (x == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFSIZE)
			buffooi = reloc(buffooi, input, input + 1);
		buffooi[input] = t;
		input++;
	}
	buffooi[input] = '\0';
	bri_li(liptrooooi, n, buffooi, input);
	retval = input;
	if (x != 0)
		input = 0;
	return (retval);
}
