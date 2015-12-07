# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/04 10:50:26 by aleblanc          #+#    #+#              #
#    Updated: 2015/12/07 11:40:01 by aleblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c				\
	  ft_lst.c				\
	  ft_read_tetriminos.c	\
	  io_search.c			\
	  j_place.c				\
	  jzs_search.c			\
	  place_tetri_1.c		\
	  place_tetri_2.c		\
	  place_tetri_l.c		\
	  resolv.c				\
	  tetris_check.c

OBJ = $(SRC:.c=.o)

HEAD = fillit.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) -I $(HEAD) -L. -lft

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
