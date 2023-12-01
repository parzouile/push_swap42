# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 15:57:13 by aschmitt          #+#    #+#              #
#    Updated: 2023/11/16 11:42:18 by aschmitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRCS =	ft_convert_hexa.c  ft_printf.c  ft_put.c  ft_strlen.c
			

HEADER = ft_printf.h
OBJS = ${SRCS:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS} 

%.o : %.c ${HEADER} Makefile
	${CC} ${FLAGS}  -o $@ -c $<

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re