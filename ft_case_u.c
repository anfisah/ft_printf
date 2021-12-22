/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:11:33 by ccoto             #+#    #+#             */
/*   Updated: 2020/12/22 13:17:24 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cas2u(long arg, int *count, t_pf pf, char *str)
{
	int size_print;

	size_print = ft_strlen(str);
	ft_putnbr_u(arg, count);
	while (pf.flagwidth - size_print > 0)
	{
		ft_putchar(' ', count);
		pf.flagwidth--;
	}
}

void	ft_cas3u(long arg, int *count, t_pf pf, char *str)
{
	int size_print;
	int c;

	c = 0;
	size_print = ft_strlen(str);
	while (pf.flagprecision - size_print > 0)
	{
		ft_putchar('0', count);
		pf.flagprecision--;
		c++;
	}
	ft_putnbr_u(arg, count);
	while (pf.flagwidth - size_print - c > 0)
	{
		ft_putchar(' ', count);
		pf.flagwidth--;
	}
}

void	ft_cas4u(long arg, int *count, t_pf pf, char *str)
{
	int size_print;

	size_print = ft_strlen(str);
	if (arg == 0 && pf.flagprecision == 0)
		size_print = 0;
	if (!(arg == 0 && pf.flagprecision == 0))
		ft_putnbr_u(arg, count);
	while (pf.flagwidth - size_print > 0)
	{
		ft_putchar(' ', count);
		pf.flagwidth--;
	}
}

void	ft_cas5u(long arg, int *count, t_pf pf)
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
}
