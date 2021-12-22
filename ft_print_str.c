/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:06:30 by ccoto             #+#    #+#             */
/*   Updated: 2020/12/22 12:24:31 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ftmoins_s(char *arg, int *count, t_pf pf)
{
	int i;
	int size_print;

	i = 0;
	size_print = ft_strlen(arg);
	if (pf.flagprecision != -1 && pf.flagprecision < size_print)
		size_print = pf.flagprecision;
	if (pf.flagprecision != -1)
		while (size_print > 0)
		{
			ft_putchar(arg[i], count);
			i++;
			size_print--;
		}
	else
		ft_putstr(arg, count);
	while (pf.flagwidth - size_print - i > 0)
	{
		ft_putchar(' ', count);
		pf.flagwidth--;
	}
}

void	ftnomoins_s(char *arg, int *count, t_pf pf)
{
	int i;
	int size_print;

	i = 0;
	size_print = ft_strlen(arg);
	if (pf.flagprecision != -1 && pf.flagprecision < size_print)
		size_print = pf.flagprecision;
	while ((pf.flagwidth - size_print) > 0)
	{
		ft_putchar(' ', count);
		pf.flagwidth--;
	}
	if (pf.flagprecision != -1)
		while (size_print > 0)
		{
			ft_putchar(arg[i], count);
			i++;
			size_print--;
		}
	else
		ft_putstr(arg, count);
}

void	ft_print_str(va_list ap, int *count, t_pf pf)
{
	char	*chrvalue;
	int		i;
	int		size_print;

	i = 0;
	chrvalue = va_arg(ap, char *);
	if (pf.flagprecision != 0)
	{
		if (chrvalue == NULL)
			chrvalue = "(null)";
		size_print = ft_strlen(chrvalue);
		if (pf.flagprecision != -1 && pf.flagprecision < size_print)
			size_print = pf.flagprecision;
		if (pf.flagmoins == 0)
			ftnomoins_s(chrvalue, count, pf);
		if (pf.flagmoins == 1)
			ftmoins_s(chrvalue, count, pf);
	}
	else
	{
		if (pf.flagmoins == 0)
			ftnomoins_s("", count, pf);
		if (pf.flagmoins == 1)
			ftmoins_s("", count, pf);
	}
}
