CC=cc
CFLAGS=-Wall -Wextra -Werror
CFILES=main.c alg.c search_file.c size_dict.c
OBJ=main.o alg.o search_file.o size_dict.o 

NAME=rush-02

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
