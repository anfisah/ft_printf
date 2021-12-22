/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pourcentage.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:27:24 by ccoto             #+#    #+#             */
/*   Updated: 2020/12/22 12:22:05 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(va_list ap, int *count, t_pf pf)
{
	char	charvalue;
	int		x;

	x = 0;
	charvalue = va_arg(ap, int);
	while ((pf.flagwidth - 1) > 0)
	{
		if (pf.flagmoins == 1)
		{
			ft_putchar(charvalue, count);
			pf.flagmoins = 0;
			x++;
		}
		ft_putchar(' ', count);
		pf.flagwidth--;
	}
	if (x == 0)
		ft_putchar(charvalue, count);
}

void	ft_moins_pct(int *count, t_pf pf)
{
	ft_putchar('%', count);
	while ((pf.flagwidth - 1) > 0)
	{
		ft_putchar(' ', count);
		pf.flagwidth--;
	}
}

void	ft_print_pourcentage(int *count, t_pf pf)
{
	if (pf.flagzero == 1)
	{
		while ((pf.flagwidth - 1) > 0)
		{
			ft_putchar('0', count);
			pf.flagwidth--;
		}
		ft_putchar('%', count);
	}
	else if (pf.flagmoins == 1)
		ft_moins_pct(count, pf);
	else
	{
		while ((pf.flagwidth - 1) > 0)
		{
			ft_putchar(' ', count);
			pf.flagwidth--;
		}
		ft_putchar('%', count);
	}
}
