/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cas_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 10:46:19 by ccoto             #+#    #+#             */
/*   Updated: 2020/12/22 12:53:16 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cas2i(long arg, int *count, t_pf pf, char *str)
{
	int size_print;

	size_print = ft_compteur(arg);
	if (str[0] == '-')
		ft_putchar('-', count);
	ft_putnbr(arg, count);
	while (pf.flagwidth - size_print > 0)
	{
		ft_putchar(' ', count);
		pf.flagwidth--;
	}
}

void	ft_cas3i(long arg, int *count, t_pf pf, char *str)
{
	int size_print;
	int c;

	c = 0;
	size_print = ft_compteur(arg);
	if (str[0] == '-')
		ft_putchar('-', count);
	while (pf.flagprecision - size_print > 0)
	{
		ft_putchar('0', count);
		pf.flagprecision--;
		c++;
	}
	ft_putnbr(arg, count);
	while (pf.flagwidth - size_print - c > 0)
	{
		ft_putchar(' ', count);
		pf.flagwidth--;
	}
}

void	ft_cas4i(long arg, int *count, t_pf pf, char *str)
{
	int size_print;

	size_print = ft_compteur(arg);
	if (arg == 0 && pf.flagprecision == 0)
		size_print = 0;
	if (str[0] == '-')
		ft_putchar('-', count);
	if (!(arg == 0 && pf.flagprecision == 0))
		ft_putnbr(arg, count);
	while (pf.flagwidth - size_print > 0)
	{
		ft_putchar(' ', count);
		pf.flagwidth--;
	}
}

void	ft_cas5i(long arg, int *count, t_pf pf, char *str)
{
	int size_print;

	size_print = ft_compteur(arg);
	if (arg == 0 && pf.flagprecision == 0)
		size_print = 0;
	while (pf.flagwidth > size_print)
	{
		ft_putchar(' ', count);
		pf.flagwidth--;
	}
	if (str[0] == '-')
		ft_putchar('-', count);
}
