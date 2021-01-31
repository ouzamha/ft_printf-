# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/12 13:41:53 by ouzamhar          #+#    #+#              #
#    Updated: 2019/07/07 18:41:15 by ouzamhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	libftprintf.a

SRC = char.c di.c double.c flag.c float.c fract.c ft_atl.c ft_zero.c inte.c \
long.c node.c ouprintf.c p_string.c prec.c printf.c ptg.c racprintf.c reald.c \
string.c x.c xup.c ft_malloc.c

OBJ = $(SRC:.c=.o)

LIBFT_INCLUDES_DIR = libft

LIB = libft/libft.a

all:	$(NAME)

$(NAME): $(OBJ) $(LIB)
	cp $(LIB) $(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ) : %.o : %.c $(LIBFT_INCLUDES_DIR)/libft.h
	gcc -c $< -o $@ -I $(LIBFT_INCLUDES_DIR)

$(LIB):
	make -C $(LIBFT_INCLUDES_DIR)

clean:
	make clean -C $(LIBFT_INCLUDES_DIR)
	/bin/rm -f *.o

fclean:	clean
	make fclean -C $(LIBFT_INCLUDES_DIR)
	/bin/rm -f $(NAME)

re: fclean all
