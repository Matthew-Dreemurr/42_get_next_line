NAME = gnl.OwO
CC = gcc

CFLAG = $(DEF) -Wall -Wextra -Werror
SRC = get_next_line_utils.c get_next_line.c main.c
DEF = -D BUFFER_SIZE=1
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(SRC) -o $(NAME)
	@cat ./test/cat.UwU
	@echo "\n"

.phony: all
