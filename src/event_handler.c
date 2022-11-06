#include "../so_long.h"

int	quit_game(t_game *game)
{
    if (game->win)
	    mlx_destroy_window(game->mlx, game->win);
    if (game->mlx)
	    free(game->mlx);
    if (game->tilemap)
        free_tilemap(game);
	exit(0);
}

int	event_handler(int key, t_game *game)
{
	if (key == ESC)
		quit_game(game);
    if (game->player.tile == NULL)
        return (0);
    if (key == KEY_UP)
        player_movement(game, game->player.tile->up);
    else if (key == KEY_DOWN)
        player_movement(game, game->player.tile->down);
    else if (key == KEY_RIGHT)
        player_movement(game, game->player.tile->right);
    else if (key == KEY_LEFT)
        player_movement(game, game->player.tile->left);
    else
        return (0);
	return (1);
}