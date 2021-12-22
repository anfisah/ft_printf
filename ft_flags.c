/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:57:42 by ccoto             #+#    #+#             */
/*   Updated: 2020/12/22 14:55:52 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pointflag(va_list ap, char *format, int *i, t_pf *pf)
{
	int f;

	if (format[*i] == '.')
	{
		pf->flagprecision = 0;
		(*i)++;
		if (format[*i] == '*')
		{
			f = va_arg(ap, int);
			if (f >= 0)
				pf->flagprecision = f;
			else
				pf->flagprecision = -1;
			(*i)++;
		}
		while (format[*i] >= '0' && format[*i] <= '9')
		{
			pf->flagprecision *= 10;
			pf->flagprecision += format[*i] - 48;
			(*i)++;
		}
	}
}

void	widthflag(va_list ap, char *format, int *i, t_pf *pf)
{
	int		f;

	if (format[*i] == '*')
	{
		f = va_arg(ap, int);
		pf->flagwidth = f;
		if (pf->flagwidth < 0)
		{
			pf->flagmoins = 1;
			pf->flagwidth *= -1;
		}
		(*i)++;
	}
	while (format[*i] >= '0' && format[*i] <= '9')
	{
		pf->flagwidth *= 10;
		pf->flagwidth += format[*i] - 48;
		(*i)++;
	}
}

t_pf	ft_flags(va_list ap, char *format, int *i)
{
	t_pf	pf;

	pf = init_struct();
	while (format[*i] == '0' || format[*i] == '-')
	{
		if (format[*i] == '0' && pf.flagmoins != 1)
			pf.flagzero = 1;
		else
			pf.flagmoins = 1;
		(*i)++;
	}
	widthflag(ap, format, i, &pf);
	pointflag(ap, format, i, &pf);
	return (pf);
}
