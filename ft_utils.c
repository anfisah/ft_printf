/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 10:18:26 by ccoto             #+#    #+#             */
/*   Updated: 2020/12/22 13:14:18 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *count)
{
	long	nbr;
	int		sign;

	nbr = nb;
	sign = 1;
	if (nbr < 0)
	{
		sign = 0;
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		ft_putnbr((nbr / 10), count);
	}
	ft_putchar((nbr % 10) + '0', count);
}

void	ft_putnbr_u(unsigned int nb, int *count)
{
	if (nb < 0)
		nb *= -1;
	if (nb >= 10)
		ft_putnbr_u((nb / 10), count);
	ft_putchar(((nb % 10) + '0'), count);
}

void	ft_putstr(char *s, int *count)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], count);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_base(unsigned long long nbr, char *base, int *count)
{
	int		i;
	int		sizebase;
	long	nb;

	i = 0;
	nb = nbr;
	sizebase = ft_strlen(base);
	if (nb < 0)
	{
		ft_putchar('-', count);
		nb *= (-1);
	}
	if (nb >= sizebase)
	{
		ft_putnbr_base(nb / sizebase, base, count);
		ft_putnbr_base(nb % sizebase, base, count);
	}
	else
		ft_putchar(base[nb], count);
}
