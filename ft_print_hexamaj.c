/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexamaj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:07:52 by ccoto             #+#    #+#             */
/*   Updated: 2020/12/22 13:33:23 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cas1x_maj(long arg, int *count, t_pf pf, char *str)
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
		ft_putnbr_base(arg, "0123456789ABCDEF", count);
}

void	ft_cas6x_maj(long arg, int *count, t_pf pf, char *str)
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
		ft_cas5x(arg, count, pf, str);
	if (!(arg == 0 && pf.flagprecision == 0))
		ft_putnbr_base(arg, "0123456789ABCDEF", count);
}

void	ft_moins_xmaj(long arg, int *count, t_pf pf, char *str)
{
	int size_print;
	int c;

	c = 0;
	size_print = ft_strlen(str);
	if (arg == 0 && pf.flagprecision == 0)
		size_print = 0;
	if (str[0] == '-')
		pf.flagwidth--;
	if (pf.flagprecision > size_print)
		ft_cas3x_maj(arg, count, pf, str);
	else if (pf.flagprecision < size_print)
		ft_cas2x_maj(arg, count, pf, str);
	else
		ft_cas4x_maj(arg, count, pf, str);
}

void	ft_nomoins_xmaj(long arg, int *count, t_pf pf, char *str)
{
	int size_print;

	size_print = ft_strlen(str);
	if (arg == 0)
		size_print = 0;
	if (pf.flagprecision > size_print)
		ft_cas1x_maj(arg, count, pf, str);
	else
		ft_cas6x_maj(arg, count, pf, str);
}

void	ft_print_hexa_maj(va_list ap, int *count, t_pf pf)
{
	int				size_print;
	char			*str;
	long			intlong;
	unsigned int	hexamaj;

	hexamaj = va_arg(ap, int);
	intlong = hexamaj;
	str = ft_itoa_base(intlong);
	size_print = ft_strlen(str);
	if (pf.flagmoins == 1)
		ft_moins_xmaj(hexamaj, count, pf, str);
	if (pf.flagmoins == 0)
		ft_nomoins_xmaj(hexamaj, count, pf, str);
	free(str);
}
