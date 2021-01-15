# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/02 14:25:35 by mhadad            #+#    #+#              #
#    Updated: 2021/01/15 15:25:32 by mhadad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.OwO
CC = gcc
DEF = -D BUFFER_SIZE=1 -D TXT=\"test/txt.UwU\" -D DEBUG -D LOOP=1000
CFLAG = $(DEF) -Wall -Wextra -Werror
SRC = src/get_next_line_utils.c src/get_next_line.c \
	src/get_next_line_main.c

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(SRC) -o $(NAME)
	@cat ./test/cat.UwU
	@echo "\n"

re: clean all

clean:
	rm -f gnl.OwO

leak: clean
	$(CC) $(CFLAG) -fsanitize=address $(SRC) -o $(NAME)
	@cat ./test/cat.UwU
	@echo "\n"

exe: leak
	@echo "\n[======[EXE: start]======]\n"
	@./gnl.OwO
	@echo "\n[=======[EXE: end]=======]\n"

c:
	@clear

.phony: yolo, all, exe, fclean, clean, res