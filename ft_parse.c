/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:23:37 by ccoto             #+#    #+#             */
/*   Updated: 2020/12/22 14:52:46 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf	init_struct(void)
{
	t_pf pf;

	pf.flagzero = 0;
	pf.flagmoins = 0;
	pf.flagwidth = 0;
	pf.flagprecision = -1;
	pf.flagetoile = 0;
	return (pf);
}

void	ft_putchar(char c, int *count)
{
	*count = *count + 1;
	write(1, &c, 1);
}

int		ft_parse(va_list ap, char *format)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while ((format[i]))
	{
		if (format[i] != '%')
			ft_putchar(format[i], &count);
		else if (format[i] == '%')
		{
			i++;
			i = i + ft_conversion(ap, &format[i], &count);
		}
		i++;
	}
	return (count);
}
