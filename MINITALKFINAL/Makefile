# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 17:01:19 by mafourni          #+#    #+#              #
#    Updated: 2024/06/02 21:30:28 by mafourni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra  -fsanitize=address
RM = rm -f

NAME_C = client
NAME_S = server

SRC_S = ./src/server.c
SRC_C = ./src/client.c
SRC_I = ./src/include.c

OBJ_C = $(SRC_C:.c=.o)
OBJ_S = $(SRC_S:.c=.o)
OBJ_I = $(SRC_I:.c=.o)

LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft/

all: server client

client: $(SRC_C) $(OBJ_C)
		make -C $(LIBFT_PATH)
		$(CC) $(CFLAGS) -o $(NAME_C) $(SRC_C) $(LIBFT)
	
server: $(SRC_S) $(OBJ_S) $(SRC_I) $(OBJ_I)
		make -C $(LIBFT_PATH)
		$(CC) $(CFLAGS) -o $(NAME_S) $(SRC_S) $(SRC_I) $(LIBFT)

clean:
		$(RM) $(OBJ_C) $(OBJ_S) $(OBJ_I)
		make -C $(LIBFT_PATH) clean

fclean: clean
		$(RM) $(NAME_C) $(NAME_S) $(LIBFT)

re: fclean all