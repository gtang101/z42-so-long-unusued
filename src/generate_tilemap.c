#include "../so_long.h"

t_tile	**alloc_tilemap(char **map, t_game *game)
{
	t_tile	**tilemap;
	int		i;

	tilemap = malloc(sizeof(t_tile *) * game->win_height);
	if (tilemap == NULL)
		return (NULL);
	i = 0;
	while (map[i] != NULL)
	{
		tilemap[i] = malloc(sizeof(t_tile) * ft_strlen(*map) + 1);
		if (tilemap == NULL)
		{
			while (i > 0)
				free(tilemap[--i]);
			return (NULL);
		}
		i++;
	}
	return (tilemap);
}

t_tiletype	define_tiletype(char definer)
{
	if (definer == '1')
		return (WALL);
	if (definer == 'C')
		return (COLLECTABLE);
	if (definer == 'P')
		return (PLAYER);
	if (definer == 'E')
		return (EXIT);
	else if (definer == 'M')
		return (ENEMY);
	return (EMPTY);
}

void	setup_tile(t_tile **tilemap, int x, int y)
{
	tilemap[y][x].pos_x = x * TILE_SIZE;
	tilemap[y][x].pos_y = y * TILE_SIZE;
	if (y != 0)
		tilemap[y][x].up = &tilemap[y - 1][x];
	if (tilemap[y + 1] != NULL)
		tilemap[y][x].down = &tilemap[y + 1][x];
	if (x != 0)
		tilemap[y][x].left = &tilemap[y][x - 1];
	tilemap[y][x].right = &tilemap[y][x + 1];
}

t_tile	**generate_tilemap(char **map, t_game *game)
{
	t_tile		**tilemap;
	int			x;
	int			y;

	tilemap = alloc_tilemap(map, game);
	if (!tilemap){
		error_map_invalid("fail to generate tilemap.");
		return (NULL);
	}
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			tilemap[y][x].current_type = define_tiletype(map[y][x]);
			setup_tile(tilemap, x, y);
			x++;
		}
		tilemap[y][x].current_type = 0;
		y++;
	}
	tilemap[y] = NULL;
	return (tilemap);
}