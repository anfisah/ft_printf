# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/03 12:15:59 by ccoto             #+#    #+#              #
#    Updated: 2020/12/22 13:29:38 by ccoto            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME =          libftprintf.a

SRCS =          ft_printf.c ft_utils.c ft_conversions.c ft_parse.c \
				ft_flags.c ft_print_str.c ft_print_hexa.c \
				ft_print_int.c ft_print_ptr.c ft_cas_i.c ft_cas_x.c \
				ft_print_hexamaj.c ft_cas_xmaj.c ft_print_pct_chr.c \
				ft_print_unsign_int.c ft_case_u.c ft_utils2.c

OBJS =          ${SRCS:.c=.o}

CC =            gcc

FLAGS =         -Wall -Wextra -Werror

RM =            rm -f

.c.o:
				${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I .

${NAME}:		${OBJS}
				ar -rcs ${NAME} ${OBJS}

all:			${NAME}

clean: 
				${RM} ${OBJS}

fclean:     	clean
				${RM} ${NAME}

re:         	fclean all

.PHONY:     	all clean fclean re