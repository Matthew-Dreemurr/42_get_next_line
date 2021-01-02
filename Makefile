# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/02 14:25:35 by mhadad            #+#    #+#              #
#    Updated: 2021/01/02 19:43:31 by mhadad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.OwO
CC = gcc
DEF = -D BUFFER_SIZE=32 -D TXT=\"test/txt.UwU\"
CFLAG = $(DEF) -Wall -Wextra -Werror
SRC = SRC/get_next_line_utils.c SRC/get_next_line.c \
	SRC/get_next_line_main.c

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(SRC) -o $(NAME)
	@cat ./test/cat.UwU
	@echo "\n"

re: fclean all

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

leak: re
	$(CC) $(CFLAG) -fsanitize=address $(SRC) -o $(NAME)

exe: leak
	@echo "\n[======[EXE: start]======]\n"
	@./gnl.OwO
	@echo "\n[=======[EXE: end]=======]\n"

.phony: yolo, all, exe, fclean, clean, res