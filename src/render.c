#include "../so_long.h"

static void place_img(t_tile tile, t_game game, int x, int y)
{
    if (tile.current_type == EXIT)
        mlx_put_image_to_window(game.mlx, game.win, game.exit_img, x, y);
    else if (tile.current_type == WALL)
        mlx_put_image_to_window(game.mlx, game.win, game.wall_img, x, y);
    else if (tile.current_type == COLLECTABLE)
        mlx_put_image_to_window(game.mlx, game.win, game.collect_img, x, y);
    else if (tile.current_type == EMPTY)
        mlx_put_image_to_window(game.mlx, game.win, game.empty_img, x, y);
    else if (tile.current_type == PLAYER)
    {
        mlx_put_image_to_window(game.mlx, game.win, game.player.current_img, x, y);
        game.player.tile = &tile;
    }
    else if (tile.current_type == ENEMY)
        mlx_put_image_to_window(game.mlx, game.win, game.enemy_img, x, y);
}

static void	draw_text(t_game game)
{
	char	*str;

	str = ft_itoa(game.moves_count);
	mlx_string_put(game.mlx, game.win, game.win_width - TILE_SIZE / 2.3, TILE_SIZE - TILE_SIZE / 1.5, -1, str);
	free(str);
}

void    render(t_game game)
{
    t_tile  tile;
    int     x;
    int     y;

    mlx_clear_window(game.mlx, game.win);
    y = 0;
    while (game.tilemap[y] != NULL)
    {
        x = 0;
        while(game.tilemap[y][x].current_type)
        {
            tile = game.tilemap[y][x];
            place_img(tile, game, tile.pos_x, tile.pos_y);
            x++;
        }
        y++;
    }
    draw_text(game);
}