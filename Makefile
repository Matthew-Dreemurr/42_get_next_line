NAME = gnl.OwO
CC = gcc
DEF = -D BUFFER_SIZE=10000000
DEF += -D LOOP=999
DEF += -D TEST0
DEF += -D TXT=\"test/txt.UwU\"
# DEF += -D DEBUG
# DEF += -D WLK
# DEF += -fsanitize=address -fsanitize=leak -g3
#-D TXT=\"test/lorem_ipsum_of_the_doom.UwU\"

CFLAG = $(DEF) #-Wall -Wextra -Werror
SRC = get_next_line_utils.c get_next_line.c get_next_line_main.c

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(SRC) -o $(NAME)
	@cat ./test/cat.UwU
	@echo "\n"

re: clean all

clean:
	rm -f gnl.OwO

leak: clean
	$(CC) $(CFLAG) -g3 $(SRC) -o $(NAME)
	@cat ./test/cat.UwU
	@echo "\n"

exe: leak
	@echo "\n[======[EXE: start]======]\n"
	@./gnl.OwO
	@echo "\n[=======[EXE: end]=======]\n"

c:
	@clear

.phony: yolo, all, exe, fclean, clean, res