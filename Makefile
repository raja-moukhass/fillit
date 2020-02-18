# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramoukha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/12 12:17:42 by ramoukha          #+#    #+#              #
#    Updated: 2019/07/24 15:09:19 by ramoukha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMP = gcc -Werror -Wextra -Wall
SRC = srcs/validation.c srcs/extraction.c srcs/map.c srcs/solver.c
OB = validation.o extraction.o map.o solver.o main.o
NAME = fillit  

all : $(NAME)

$(NAME):
	make -C libft/
	$(COMP) -c $(SRC) srcs/main.c
	$(COMP) -o $(NAME) $(OB) libft/libft.a

clean:
	make -C libft/ clean
	rm -f $(OB)
fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all 
