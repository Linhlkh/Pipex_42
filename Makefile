# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khle <khle@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 00:10:21 by khle              #+#    #+#              #
#    Updated: 2023/03/05 20:36:34 by khle             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -MMD

NAME = pipex

INC = ./lib/pipex.h

SRC = ./src/get_path.c\
		./src/pipex.c\
		./src/utils.c\
		./src/ft_split.c\
		./src/ft_strjoin.c\
		./src/ft_strlen.c\
		./src/ft_strnstr.c\

OBJ = $(SRC:.c=.o)

DEPS = $(SRC:.c=.d)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf $(DEPS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(OBJ:.o=.d)

.PHONY: all clean fclean re