# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nowl <nowl@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/27 23:00:31 by nowl              #+#    #+#              #
#    Updated: 2015/02/27 23:13:36 by nowl             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/

SRC_NAME =	ft_kernel.c \

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ_PATH = ./obj/

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

INC_PATH = ./include/

INC = $(addprefix -I, $(INC_PATH))

NAME = game_2048

CC = gcc

CFLAGS = -Wall -Wextra -Werror -lncurses -lcurses

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJ) -g

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(INC) -o $@ -c $< -g

clean :
	rm -fv $(OBJ)
	rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean : clean
	rm -fv $(NAME)

re : fclean all

norme :
	norminette $(SRC)
	norminette $(INC_PATH)*.h
