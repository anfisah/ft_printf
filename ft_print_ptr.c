/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:38:03 by ccoto             #+#    #+#             */
/*   Updated: 2020/12/22 13:33:50 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ptr(int *count, t_pf pf, char *str)
{
	if (pf.flagmoins == 0)
	{
		while (pf.flagwidth - ft_strlen(str) - 2 > 0)
		{
			ft_putchar(' ', count);
			pf.flagwidth--;
		}
		ft_putstr("0x", count);
		ft_putstr(str, count);
	}
	else
	{
		ft_putstr("0x", count);
		ft_putstr(str, count);
		while (pf.flagwidth - ft_strlen(str) - 2 > 0)
		{
			ft_putchar(' ', count);
			pf.flagwidth--;
		}
	}
}

void	ft_print_ptr(va_list ap, int *count, t_pf pf)
{
	void				*ptr;
	unsigned long long	nb;
	char				*str;

	ptr = va_arg(ap, void *);
	nb = (unsigned long long)ptr;
	str = ft_itoa_base(nb);
	ft_ptr(count, pf, str);
	free(str);
}
