NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = src/check_map.c \
		src/event_handler.c \
		src/generate_tilemap.c \
		src/player_movement.c \
		src/read_map.c \
		src/render.c \
		src/utils.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		main.c

LIB = libft/libft.a mlx/libmlx.a -framework OpenGL -framework AppKit

MINILIBX = mlx/

LIBFT = libft/

OBJ = *.o

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(MINILIBX)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	$(MAKE) clean -C $(MINILIBX)
	$(MAKE) clean -C $(LIBFT)
	rm -rf $(OBJ)
	rm -rf $(NAME)

fclean: clean

re: fclean all