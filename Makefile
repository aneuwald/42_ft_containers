# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 17:18:31 by acanterg          #+#    #+#              #
#    Updated: 2022/03/18 17:03:52 by acanterg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

SRC 	= 	main.cpp

NAME 	=	containers
CC		=	clang++
FLAGS	=	-Wall -Wextra -Werror -std=c++98
FSANIT	=	-fsanitize=address
INCLUD	=	-I .
DIR_OBJ	=	obj
OBJ		= 	$(SRC:%.cpp=$(DIR_OBJ)/%.o)

$(DIR_OBJ)/%.o:%.cpp
			mkdir -p $(DIR_OBJ)
			$(CC) $(FLAGS) $(INCLUD) -o $@ -c $<

$(NAME):	$(OBJ)
			printf "Compiling $(NAME) ... "
			$(CC) $(FLAGS) $(FSANIT) $(SRC) -o $(NAME)
			printf "$(C_GREEN)DONE$(C_END)\n"


all:		$(NAME)

clean:
			printf "Deleting .o folder ... "
			rm -rf $(DIR_OBJ)
			printf "$(C_GREEN)DONE$(C_END)\n"

fclean: 	clean
			printf "Deleting $(NAME) ... "
			rm -rf $(NAME) *_shrubbery
			printf "$(C_GREEN)DONE$(C_END)\n"

test:		re
			./$(NAME) a
			$(MAKE) fclean

re: fclean all

C_BLACK		= \033[0;30m
C_RED		= \033[0;31m
C_GREEN		= \033[0;32m
C_YELLOW	= \033[0;33m
C_BLUE		= \033[0;34m
C_WHITE		= \033[0;37m
C_END		= \033[0m