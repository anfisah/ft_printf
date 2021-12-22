/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 11:18:20 by ccoto             #+#    #+#             */
/*   Updated: 2020/12/21 17:37:31 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(va_list ap, char *format, int *count)
{
	t_pf	pf;
	int		i;

	i = 0;
	pf = ft_flags(ap, format, &i);
	if (format[i] == 'c')
		ft_print_char(ap, count, pf);
	else if (format[i] == 's')
		ft_print_str(ap, count, pf);
	else if (format[i] == 'p')
		ft_print_ptr(ap, count, pf);
	else if (format[i] == 'd' || format[i] == 'i')
		ft_print_int(ap, count, pf);
	else if (format[i] == 'u')
		ft_print_unsign_int(ap, count, pf);
	else if (format[i] == 'x')
		ft_print_hexa(ap, count, pf);
	else if (format[i] == 'X')
		ft_print_hexa_maj(ap, count, pf);
	else if (format[i] == '%')
		ft_print_pourcentage(count, pf);
	return (i);
}
