/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 10:57:38 by ccoto             #+#    #+#             */
/*   Updated: 2020/12/22 13:32:39 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cas1x(long arg, int *count, t_pf pf, char *str)
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
		ft_putnbr_base(arg, "0123456789abcdef", count);
}

void	ft_cas6x(long arg, int *count, t_pf pf, char *str)
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
		ft_putnbr_base(arg, "0123456789abcdef", count);
}

void	ft_moins_x(long arg, int *count, t_pf pf, char *str)
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
		ft_cas3x(arg, count, pf, str);
	else if (pf.flagprecision < size_print)
		ft_cas2x(arg, count, pf, str);
	else
		ft_cas4x(arg, count, pf, str);
}

void	ft_nomoins_x(long arg, int *count, t_pf pf, char *str)
{
	int size_print;

	size_print = ft_strlen(str);
	if (arg == 0)
		size_print = 0;
	if (pf.flagprecision > size_print)
		ft_cas1x(arg, count, pf, str);
	else
		ft_cas6x(arg, count, pf, str);
}

void	ft_print_hexa(va_list ap, int *count, t_pf pf)
{
	int				size_print;
	char			*str;
	long			intlong;
	unsigned int	hexavalue;

	hexavalue = va_arg(ap, int);
	intlong = hexavalue;
	str = ft_itoa_base(intlong);
	size_print = ft_strlen(str);
	if (pf.flagmoins == 1)
		ft_moins_x(hexavalue, count, pf, str);
	if (pf.flagmoins == 0)
		ft_nomoins_x(hexavalue, count, pf, str);
	free(str);
}
