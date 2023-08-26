#include "shell.h"

/**
 * rep_char - ***
 *
 * @input: ***
 * @i: ***
 * Return: ***
 */
int rep_char(char *input, int i)
{
	if (*(input - 1) == *input)
	{
		return (rep_char(input - 1, i + 1));
	}

	return (i);
}

/**
 * err_s_op - ***
 *
 * @input: ***
 * @i: ***
 * @last: ***
 * Return: ***
 */
int err_s_op(char *input, int i, char last)
{
	int cntooi;

	cntooi = 0;
	if (*input == '\0')
		return (0);
	if (*input == ' ' || *input == '\t')
		return (err_s_op(input + 1, i + 1, last));
	if (*input == ';')
		if (last == '|' || last == '&' || last == ';')
			return (i);
	if (*input == '|')
	{
		if (last == ';' || last == '&')
			return (i);

		if (last == '|')
		{
			cntooi = rep_char(input, 0);
			if (cntooi == 0 || cntooi > 1)
				return (i);
		}
	}
	if (*input == '&')
	{
		if (last == ';' || last == '|')
			return (i);

		if (last == '&')
		{
			cntooi = rep_char(input, 0);
			if (cntooi == 0 || cntooi > 1)
				return (i);
		}
	}

	return (err_s_op(input + 1, i + 1, *input));
}

/**
 * fir_ch - ***
 *
 * @input: ***
 * @i: ***
 * Return: ***
 */
int fir_ch(char *input, int *i)
{

	for (*i = 0; input[*i]; *i += 1)
	{
		if (input[*i] == ' ' || input[*i] == '\t')
			continue;

		if (input[*i] == ';' || input[*i] == '|' || input[*i] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * pri_sta_err - ***
 *
 * @ash: ***
 * @input: ***
 * @i: ***
 * @iobolooi: ***
 * Return: ***
 */
void pri_sta_err(d_sh *ash, char *input, int i, int iobolooi)
{
	int lengthoooi;
	char *mgoooi, *mgoooi2, *mgoooi3, *erroooi, *counter;

	if (input[i] == ';')
	{
		if (iobolooi == 0)
			mgoooi = (input[i + 1] == ';' ? ";;" : ";");
		else
			mgoooi = (input[i - 1] == ';' ? ";;" : ";");
	}

	if (input[i] == '|')
		mgoooi = (input[i + 1] == '|' ? "||" : "|");

	if (input[i] == '&')
		mgoooi = (input[i + 1] == '&' ? "&&" : "&");

	mgoooi2 = ": Syntax erroooi: \"";
	mgoooi3 = "\" unexpected\n";
	counter = _ax_itoo(ash->counter);
	lengthoooi = sren(ash->av[0]) + sren(counter);
	lengthoooi += sren(mgoooi) + sren(mgoooi2) + sren(mgoooi3) + 2;

	erroooi = malloc(sizeof(char) * (lengthoooi + 1));
	if (erroooi == 0)
	{
		free(counter);
		return;
	}
	stcp(erroooi, ash->av[0]);
	stca(erroooi, ": ");
	stca(erroooi, counter);
	stca(erroooi, mgoooi2);
	stca(erroooi, mgoooi);
	stca(erroooi, mgoooi3);
	stca(erroooi, "\0");

	write(STDERR_FILENO, erroooi, lengthoooi);
	free(erroooi);
	free(counter);
}

/**
 * cck_synta_err - ***
 *
 * @ash: ***
 * @input: ***
 * Return: ***
 */
int cck_synta_err(d_sh *ash, char *input)
{
	int begiaoooi = 0;
	int f_chaoooi = 0;
	int i = 0;

	f_chaoooi = fir_ch(input, &begiaoooi);
	if (f_chaoooi == -1)
	{
		pri_sta_err(ash, input, begiaoooi, 0);
		return (1);
	}

	i = err_s_op(input + begiaoooi, 0, *(input + begiaoooi));
	if (i != 0)
	{
		pri_sta_err(ash, input, begiaoooi + i, 1);
		return (1);
	}

	return (0);
}
