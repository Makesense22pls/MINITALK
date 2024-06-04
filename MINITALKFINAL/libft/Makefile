# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 14:24:40 by mafourni          #+#    #+#              #
#    Updated: 2024/05/24 19:32:58 by mafourni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

RM = rm -f

SRC = ft_atoi.c ft_strlen.c \
	ft_printf.c ft_print_char.c ft_print_char.c ft_print_format.c \
	ft_print_hexmaj.c ft_print_hexmin.c ft_print_nbr.c \
	ft_print_str.c ft_print_ptr.c ft_print_nbru.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o: %.c
	cc -Wall -Werror -Wextra -c $< -o $@ -I.

$(NAME):	$(OBJ)
	ar rcs $@ $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all