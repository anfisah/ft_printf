/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cas_xmaj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:13:41 by ccoto             #+#    #+#             */
/*   Updated: 2020/12/21 17:36:30 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cas2x_maj(long arg, int *count, t_pf pf, char *str)
{
	int size_print;

	size_print = ft_strlen(str);
	if (str[0] == '-')
		ft_putchar('-', count);
	ft_putnbr_base(arg, "0123456789ABCDEF", count);
	while (pf.flagwidth - size_print > 0)
	{
		ft_putchar(' ', count);
		pf.flagwidth--;
	}
}

void	ft_cas3x_maj(long arg, int *count, t_pf pf, char *str)
{
	int size_print;
	int c;

	c = 0;
	size_print = ft_strlen(str);
	if (str[0] == '-')
		ft_putchar('-', count);
	while (pf.flagprecision - size_print > 0)
	{
		ft_putchar('0', count);
		pf.flagprecision--;
		c++;
	}
	ft_putnbr_base(arg, "0123456789ABCDEF", count);
	while (pf.flagwidth - size_print - c > 0)
	{
		ft_putchar(' ', count);
		pf.flagwidth--;
	}
}

void	ft_cas4x_maj(long arg, int *count, t_pf pf, char *str)
{
	int size_print;

	size_print = ft_strlen(str);
	if (arg == 0 && pf.flagprecision == 0)
		size_print = 0;
	if (str[0] == '-')
		ft_putchar('-', count);
	if (!(arg == 0 && pf.flagprecision == 0))
		ft_putnbr_base(arg, "0123456789ABCDEF", count);
	while (pf.flagwidth - size_print > 0)
	{
		ft_putchar(' ', count);
		pf.flagwidth--;
	}
}
