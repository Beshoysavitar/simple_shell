#include "shell.h"

/**
 * gt_leno - ***
 * @n: ***
 * Return: ***
 */
int gt_leno(int n)
{
	int lghtoooi = 1;
	unsigned int nooiii;

	if (n < 0)
	{
		lghtoooi++;
		nooiii = n * -1;
	}
	else
	{
		nooiii = n;
	}
	while (nooiii > 9)
	{
		lghtoooi++;
		nooiii = nooiii / 10;
	}

	return (lghtoooi);
}
/**
 * _ax_itoo - ***
 * @n: ***
 * Return: ***
 */
char *_ax_itoo(int n)
{
	char *buffer;
	unsigned int nooiii;
	int lghtoooi = gt_leno(n);

	buffer = malloc(sizeof(char) * (lghtoooi + 1));
	if (buffer == 0)
	{
		return (NULL);
	}
	*(buffer + lghtoooi) = '\0';

	if (n < 0)
	{
		nooiii = n * -1;
		buffer[0] = '-';
	}
	else
	{
		nooiii = n;
	}

	lghtoooi--;
	do {
		*(buffer + lghtoooi) = (nooiii % 10) + '0';
		nooiii = nooiii / 10;
		lghtoooi--;
	}
	while (nooiii > 0)
		;
	return (buffer);
}

/**
 * atoo - ***
 * @s: ***
 * Return: ***
 */
int atoo(char *s)
{
	unsigned int conoooi = 0, siziooiii = 0, oooi = 0, pnoooii = 1, m = 1, x;

	while (*(s + conoooi) != '\0')
	{
		if (siziooiii > 0 && (*(s + conoooi) < '0' || *(s + conoooi) > '9'))
			break;

		if (*(s + conoooi) == '-')
			pnoooii *= -1;

		if ((*(s + conoooi) >= '0') && (*(s + conoooi) <= '9'))
		{
			if (siziooiii > 0)
				m *= 10;
			siziooiii++;
		}
		conoooi++;
	}
	for (x = conoooi - siziooiii; x < conoooi; x++)
	{
		oooi = oooi + ((*(s + x) - 48) * m);
		m /= 10;
	}
	return (oooi * pnoooii);
}
/**
 * ev_stg - ***
 * @s: ***
 * Return: ***
 */
void ev_stg(char *s)
{
	int conoooi = 0, x, j;
	char *str, temp;

	while (conoooi >= 0)
	{
		if (s[conoooi] == '\0')
			break;
		conoooi++;
	}
	str = s;

	for (x = 0; x < (conoooi - 1); x++)
	{
		for (j = x + 1; j > 0; j--)
		{
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	}
}
/**
 * _help_cdooi - ***
 * Return: ***
 */
void _help_cdooi(void)
{
	char *hlpooi = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, hlpooi, sren(hlpooi));
	hlpooi = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, hlpooi, sren(hlpooi));
}
