#include "so_long.h"

t_tile	**load_map(char **av, t_game *game)
{
	char	**map;
	t_tile	**tilemap;

	map = read_map(game, av[0]);
	if (!map)
		return (NULL);
	if (!check_map(map, game))
	{
		free_map(map);
		return (NULL);
	}
	tilemap = generate_tilemap(map, game);
	free_map(map);
	if (!tilemap)
		return (NULL);
	return (tilemap);
};

void	load_img(t_game *game)
{
	game->player.current_img = mlx_xpm_file_to_image(game->mlx, "img/pacman_open_right.xpm", &game->img_size, &game->img_size);
	game->collect_img = mlx_xpm_file_to_image(&game->mlx, "img/collects.xpm", &game->img_size, &game->img_size);
	game->enemy_img = mlx_xpm_file_to_image(&game->mlx, "img/ghost.xpm", &game->img_size, &game->img_size);
	game->exit_img = mlx_xpm_file_to_image(&game->mlx, "img/exit.xpm", &game->img_size, &game->img_size);
	game->wall_img = mlx_xpm_file_to_image(&game->mlx, "img/wall.xpm", &game->img_size, &game->img_size);
	game->empty_img = mlx_xpm_file_to_image(&game->mlx, "img/empty.xpm", &game->img_size, &game->img_size);
};

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (game->win_width * TILE_SIZE + TILE_SIZE), (game->win_height * TILE_SIZE), "So_Long");
	load_img(game);
	render(*game);
	mlx_key_hook(game->win, event_handler, &game);
	mlx_hook(game->win, CLOSE_WINDOW, 0, quit_game, 0);
};

void	set_count(t_game *game)
{
	game->moves_count = 0;
    game->collects_count = 0;
    game->player_count = 0;
    game->exit_count = 0;
	game->img_size = TILE_SIZE;
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_printf("Incorrect Number of Arguments.\nPlease enter ./so_long map/<choose a map>\n");
		return (1);
	}
	set_count(&game);
	game.tilemap = load_map(&av[1], &game);
	if (game.tilemap == NULL)
	{
		ft_printf("\n\nCannot load map\n\n");
		return (0);
	}
	game_init(&game);
	mlx_loop(game.mlx);
}