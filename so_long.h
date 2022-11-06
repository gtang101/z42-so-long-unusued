#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"

# define TILE_SIZE 32

// All possible tile types and tile structs
typedef enum e_tiletype
{
	EMPTY = '0', 
	WALL = '1', 
	COLLECTABLE = 'C', 
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY = 'M'
}	t_tiletype;

typedef struct s_tile
{
	t_tiletype		current_type;
	int				pos_x;
	int				pos_y;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

typedef struct s_player
{
	t_tile	*tile;
	void	*current_img;
}	t_player;

// All possible key action
enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	ESC = 53,
	CLOSE_WINDOW = 17
};

// GAME
typedef struct	s_game
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;

	t_tile		**tilemap;

	int			moves_count;
	int			collects_count;
	int			player_count;
	int			exit_count;
	t_player	player;

	int			img_size;
	void		*wall_img;
	void		*empty_img;
	void		*exit_img;
	void		*enemy_img;
	void		*collect_img;
}				t_game;

// Create and Display the game
char	**read_map(t_game *game, char *map_file);
t_tile	**generate_tilemap(char **map, t_game *game);
int		check_map(char **map, t_game *game);
void	render(t_game game);

// Game Function
int		event_handler(int key, t_game *game);
int		quit_game(t_game *game);
int 	player_movement(t_game *game, t_tile *tile);

// Utils
void	free_map(char **map);
void	free_tilemap(t_game *game);
int		error_map_invalid(char *message);

#endif
