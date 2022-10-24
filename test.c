#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mlx/mlx.h"

typedef struct	s_game
{
	void	*mlx;
	void	*win;
}				t_game;

int	close_game(int key, t_game *game)
{
	if (key == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		free(game->mlx);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1920, 1080, "Hellow World!");
	mlx_key_hook(game.win, close_game, &game);
	mlx_loop(game.mlx);
}
