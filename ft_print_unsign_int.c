/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsign_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:45:44 by ccoto             #+#    #+#             */
/*   Updated: 2020/12/22 13:35:10 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cas1u(long arg, int *count, t_pf pf, char *str)
{
	int size_print;

	size_print = ft_strlen(str);
	while (pf.flagwidth > pf.flagprecision)
	{
		ft_putchar(' ', count);
		pf.flagwidth--;
	}
	while (pf.flagprecision - size_print > 0)
	{
		ft_putchar('0', count);
		pf.flagprecision--;
	}
	if (!(arg == 0 && pf.flagprecision == 0))
		ft_putnbr_u(arg, count);
}

void	ft_cas6u(long arg, int *count, t_pf pf, char *str)
{
	int size_print;

	size_print = ft_strlen(str);
	if (pf.flagzero == 1 && pf.flagprecision == -1)
	{
		while (pf.flagwidth > size_print)
		{
			ft_putchar('0', count);
			pf.flagwidth--;
		}
	}
	else
		ft_cas5u(arg, count, pf);
	if (arg != 0 || pf.flagprecision != 0)
		ft_putnbr_u(arg, count);
}

void	ft_moins_u(long arg, int *count, t_pf pf, char *str)
{
	int size_print;
	int c;

	c = 0;
	size_print = ft_strlen(str);
	if (arg == 0 && pf.flagprecision == 0)
		size_print = 0;
	if (pf.flagprecision > size_print)
		ft_cas3u(arg, count, pf, str);
	else if (pf.flagprecision < size_print)
		ft_cas2u(arg, count, pf, str);
	else
		ft_cas4u(arg, count, pf, str);
}

void	ft_nomoins_u(long arg, int *count, t_pf pf, char *str)
{
	int size_print;

	size_print = ft_strlen(str);
	if (arg == 0)
		size_print = 0;
	if (pf.flagprecision > size_print)
		ft_cas1u(arg, count, pf, str);
	else
		ft_cas6u(arg, count, pf, str);
}

void	ft_print_unsign_int(va_list ap, int *count, t_pf pf)
{
	unsigned int	nb_u;
	int				size_print;
	char			*str;
	long			intlong;

	nb_u = va_arg(ap, int);
	intlong = nb_u;
	str = ft_itoa_u(nb_u);
	size_print = ft_strlen(str);
	if (pf.flagmoins == 1)
		ft_moins_u(intlong, count, pf, str);
	if (pf.flagmoins == 0)
		ft_nomoins_u(intlong, count, pf, str);
	free(str);
}
