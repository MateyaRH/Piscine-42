CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs/
CFILES = $(addprefix $(SRC_DIR), ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c)
OBJ = $(CFILES:%.c=%.o)
HEADER = includes
AR = ar
ARFLAGS = -rc

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^ 

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^ -I $(HEADER)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
