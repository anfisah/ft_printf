/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 13:55:28 by ccoto             #+#    #+#             */
/*   Updated: 2020/12/22 14:49:43 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_pf {
	int			flagzero;
	int			flagmoins;
	int			flagwidth;
	int			flagprecision;
	int			flagetoile;
}				t_pf;

int				ft_printf(const char *format,
				...) __attribute__((format(printf,1,2)));
t_pf			init_struct(void);
void			ft_print_char(va_list ap, int *count, t_pf pf);
void			ft_print_str(va_list ap, int *count, t_pf pf);
void			ft_print_ptr(va_list ap, int *count, t_pf pf);
void			ft_print_int(va_list ap, int *count, t_pf pf);
void			ft_print_unsign_int(va_list ap, int *count, t_pf pf);
void			ft_print_hexa(va_list ap, int *count, t_pf pf);
void			ft_print_hexa_maj(va_list ap, int *count, t_pf pf);
void			ft_print_pourcentage(int *count, t_pf pf);
void			ft_putchar(char c, int *count);
void			ft_putnbr_u(unsigned int n, int *count);
void			ft_putstr(char *s, int *count);
void			ft_putnbr_base(unsigned long long nb, char *base, int *count);
void			ft_putnbr(int nb, int *count);
int				ft_strlen(char *str);
int				ft_conversion(va_list ap, char *format, int *count);
int				ft_parse(va_list ap, char *format);
t_pf			ft_flags(va_list ap, char *format, int *i);
void			pointflag(va_list ap, char *format, int *i, t_pf *pf);
char			*ft_itoa_base(unsigned long long nbr);
int				ft_compteur(long nb);
char			*ft_itoa(int n);
char			*ft_itoa_u(unsigned int n);
int				ft_compteur2(unsigned long long *nb, int *len);
void			ft_moins_pct(int *count, t_pf pf);
void			ft_ptr(int *count, t_pf pf, char *str);
void			ft_cas2i(long arg, int *count, t_pf pf, char *str);
void			ft_cas3i(long arg, int *count, t_pf pf, char *str);
void			ft_cas4i(long arg, int *count, t_pf pf, char *str);
void			ft_cas5i(long arg, int *count, t_pf pf, char *str);
void			ft_cas2x(long arg, int *count, t_pf pf, char *str);
void			ft_cas3x(long arg, int *count, t_pf pf, char *str);
void			ft_cas4x(long arg, int *count, t_pf pf, char *str);
void			ft_cas5x(long arg, int *count, t_pf pf, char *str);
void			ft_cas2x_maj(long arg, int *count, t_pf pf, char *str);
void			ft_cas3x_maj(long arg, int *count, t_pf pf, char *str);
void			ft_cas4x_maj(long arg, int *count, t_pf pf, char *str);
void			ft_cas1u(long arg, int *count, t_pf pf, char *str);
void			ft_cas2u(long arg, int *count, t_pf pf, char *str);
void			ft_cas3u(long arg, int *count, t_pf pf, char *str);
void			ft_cas4u(long arg, int *count, t_pf pf, char *str);
void			ft_cas5u(long arg, int *count, t_pf pf);
void			ft_cas6u(long arg, int *count, t_pf pf, char *str);

#endif
