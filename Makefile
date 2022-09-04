NAME = fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = test.c
LIB = -Lmlx -lmlx -framework OpenGL -framework AppKit
MINILIBX = mlx/

all: $(NAME)

$(NAME):
	$(MAKE) -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SRC) $(LIB) -o $(NAME)

clean:
	$(MAKE) clean -C $(MINILIBX)
	rm -rf $(NAME)

fclean: clean
	$(MAKE) fclean -C $(MINILIBX)
	rm -rf $(NAME)

re: fclean all
