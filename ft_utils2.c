/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:46:22 by ccoto             #+#    #+#             */
/*   Updated: 2020/12/22 13:07:17 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_compteur2(unsigned long long *nb, int *len)
{
	if (*nb < 0)
	{
		(*len)++;
		*nb *= -1;
	}
	while (*nb >= 16)
	{
		*nb = *nb / 16;
		(*len)++;
	}
	return (*len);
}

char	*ft_itoa_base(unsigned long long nbr)
{
	char				*str;
	char				*base;
	int					len;
	unsigned long long	nb;

	nb = nbr;
	len = 1;
	base = "0123456789abcdef";
	ft_compteur2(&nb, &len);
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len--] = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	while (nbr >= 16)
	{
		str[len] = base[nbr % 16];
		len--;
		nbr = nbr / 16;
	}
	str[len] = base[nbr % 16];
	return (str);
}

int		ft_compteur(long nb)
{
	int len;

	len = 0;
	len++;
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		i;

	nb = n;
	i = ft_compteur(nb);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = 0;
	if (nb == 0)
		str[0] = 48;
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb >= 10)
	{
		str[i] = 48 + (nb % 10);
		nb = nb / 10;
		i--;
	}
	str[i] = 48 + (nb % 10);
	return (str);
}

char	*ft_itoa_u(unsigned int n)
{
	char	*str;
	long	nb;
	int		i;

	nb = n;
	i = ft_compteur(nb);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = 0;
	if (nb == 0)
		str[0] = 48;
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb >= 10)
	{
		str[i] = 48 + (nb % 10);
		nb = nb / 10;
		i--;
	}
	str[i] = 48 + (nb % 10);
	return (str);
}
