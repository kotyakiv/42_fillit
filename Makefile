SRC = error_handling.c output_map.c main.c reading.c print_map.c
OBJ = $(SRC:.c=.o)
NAME = fillit

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -lft -L.

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all