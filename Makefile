# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 18:21:52 by eabdelha          #+#    #+#              #
#    Updated: 2021/11/23 11:21:51 by eabdelha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =   ft_printf.c     			\
		ft_putchar_cs.c				\
		ft_printf_utils.c			\
		ft_putstr_str.c				\
		ft_putnbr_base_hex.c		\
		ft_putnbr_base_id_suit.c	\
		ft_putnbr_base_id.c			\
		ft_putnbr_base_us.c			\
		ft_put_add.c	


OBJECTS = $(SRC:.c=.o)


INCLUDE = ft_printf.h

.PHONY : all bonus clean fclean re

all: $(NAME)


$(NAME): $(OBJECTS) 
	ar rcs $(NAME) $(OBJECTS)


%.o : %.c $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

