/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 10:52:25 by ccoto             #+#    #+#             */
/*   Updated: 2020/12/22 13:34:32 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cas1i(long arg, int *count, t_pf pf, char *str)
{
	int size_print;

	size_print = ft_compteur(arg);
	if (str[0] == '-')
		pf.flagwidth--;
	while (pf.flagwidth > pf.flagprecision)
	{
		ft_putchar(' ', count);
		pf.flagwidth--;
	}
	if (str[0] == '-')
		ft_putchar('-', count);
	while (pf.flagprecision - size_print > 0)
	{
		ft_putchar('0', count);
		pf.flagprecision--;
	}
	if (!(arg == 0 && pf.flagprecision == 0))
		ft_putnbr(arg, count);
}

void	ft_cas6i(long arg, int *count, t_pf pf, char *str)
{
	int size_print;

	size_print = ft_compteur(arg);
	if (str[0] == '-')
		pf.flagwidth--;
	if (pf.flagzero == 1 && pf.flagprecision == -1)
	{
		if (str[0] == '-')
			ft_putchar('-', count);
		while (pf.flagwidth > size_print)
		{
			ft_putchar('0', count);
			pf.flagwidth--;
		}
	}
	else
		ft_cas5i(arg, count, pf, str);
	if (arg != 0 || pf.flagprecision != 0)
		ft_putnbr(arg, count);
}

void	ft_moins_i(long arg, int *count, t_pf pf, char *str)
{
	int size_print;
	int c;

	c = 0;
	size_print = ft_compteur(arg);
	if (arg == 0 && pf.flagprecision == 0)
		size_print = 0;
	if (str[0] == '-')
		pf.flagwidth--;
	if (pf.flagprecision > size_print)
		ft_cas3i(arg, count, pf, str);
	else if (pf.flagprecision < size_print)
		ft_cas2i(arg, count, pf, str);
	else
		ft_cas4i(arg, count, pf, str);
}

void	ft_nomoins_i(long arg, int *count, t_pf pf, char *str)
{
	int size_print;

	size_print = ft_compteur(arg);
	if (arg == 0)
		size_print = 0;
	if (pf.flagprecision > size_print)
		ft_cas1i(arg, count, pf, str);
	else
		ft_cas6i(arg, count, pf, str);
}

void	ft_print_int(va_list ap, int *count, t_pf pf)
{
	int		intvalue;
	int		size_print;
	char	*str;
	long	intlong;

	intvalue = va_arg(ap, int);
	intlong = intvalue;
	size_print = ft_compteur(intvalue);
	str = ft_itoa(intvalue);
	if (str[0] == '-')
		intlong *= -1;
	if (pf.flagmoins == 1)
		ft_moins_i(intlong, count, pf, str);
	if (pf.flagmoins == 0)
		ft_nomoins_i(intlong, count, pf, str);
	free(str);
}
