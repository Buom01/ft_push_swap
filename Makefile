# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: badam <badam@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/10 18:46:41 by badam             #+#    #+#              #
#    Updated: 2021/12/07 08:52:44 by badam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
CC=clang
INCLUDES=-Isrcs -Ilibft
DEPS=libft/libft.a
COMMON_CFLAGS=-Wall -Wextra -Werror
CFLAGS=$(COMMON_CFLAGS) -g3 $(INCLUDES)

HEADERS= \
	srcs/push_swap.h
SRC= \
	srcs/utils.c \
	srcs/list_utils.c \
	srcs/sort_utils.c \
	srcs/errors.c \
	srcs/push_swap.c \
	srcs/operation_swap.c \
	srcs/operation_push.c \
	srcs/operation_rotate.c \
	srcs/operation_reverse_rotate.c \
	srcs/simple_sort.c
OBJ=$(SRC:.c=.o)

SRC_BONUS=
OBJ_BONUS=$(SRC_BONUS:.c=.o)

NORM=libft srcs

all: $(NAME) 

bonus: $(NAME) 

$(NAME): $(DEPS) $(OBJ) $(HEADERS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(DEPS)

libft/libft.a:
	make -C libft bonus

clean:
	rm -rf $(OBJ)
	make -C libft clean

fclean:	clean	
	rm -rf $(NAME)
	make -C libft fclean

re: fclean all

norm: fclean
	norminette $(NORM)

norminette: norm

test: $(NAME)
