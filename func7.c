#include "shell.h"

/**
 * _err_envo - ***
 * @ash: ***
 * Return: **
 */
char *_err_envo(d_sh *ash)
{
	char *erroooi;
	char *vr_stooi;
	char *sgooi;
	int lengooi;

	vr_stooi = _ax_itoo(ash->counter);
	sgooi = ": Unable to add/remove from environment\n";
	lengooi = sren(ash->av[0]) + sren(vr_stooi);
	lengooi += sren(ash->args[0]) + sren(sgooi) + 4;
	erroooi = malloc(sizeof(char) * (lengooi + 1));
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
	stca(erroooi, sgooi);
	stca(erroooi, "\0");
	free(vr_stooi);

	return (erroooi);
}
/**
 * _err_pathrr - ***
 * @ash: ***
 *
 * Return: ***
 */
char *_err_pathrr(d_sh *ash)
{
	char *vr_stooi;
	char *erroooi;
	int lengooi;

	vr_stooi = _ax_itoo(ash->counter);
	lengooi = sren(ash->av[0]) + sren(vr_stooi);
	lengooi += sren(ash->args[0]) + 24;
	erroooi = malloc(sizeof(char) * (lengooi + 1));
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
	stca(erroooi, ": Permission denied\n");
	stca(erroooi, "\0");
	free(vr_stooi);
	return (erroooi);
}
/**
 * _help_aliooo - **
 * Return: ***
 */
void _help_aliooo(void)
{
	char *hpoooii = "alias: alias [-p] [namiooi[=value]...]\n";

	write(STDOUT_FILENO, hpoooii, sren(hpoooii));
	hpoooii = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, hpoooii, sren(hpoooii));
}
/**
 * rea_line - ***
 *
 * @i_eof: ***
 * Return: ***
 */
char *rea_line(int *i_eof)
{
	char *inpoii = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&inpoii, &bufsize, stdin);

	return (inpoii);
}
/**
 * _gt_sigi - ***
 * @sig: ***
 */
void _gt_sigi(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
