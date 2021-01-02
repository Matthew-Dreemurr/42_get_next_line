# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/02 14:25:35 by mhadad            #+#    #+#              #
#    Updated: 2021/01/02 18:29:46 by mhadad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.OwO
CC = gcc
CFLAG = -Wall -Wextra -Werror -I ./include
SRC = SRC/get_next_line_utils.c SRC/get_next_line.c \
	SRC/get_next_line_main.c
OBJ = ${SRC:c=o}
DEF = -D BUFFER_SIZE=32

all: $(NAME)

.c:.o
	gcc -c -o

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(DEF) $(OBJ) -o $(NAME)
	@cat ./test/cat.UwU
	@echo "\n"

re: fclean all

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

leak: re
	$(CC) $(CFLAG) $(DEF) -fsanitize=address $(OBJ) -o $(NAME)

exe: leak
	@echo "\n[======[EXE: start]======]\n"
	@./gnl.OwO
	@echo "\n[=======[EXE: end]=======]\n"