#include "../so_long.h"

int	horizontal_check(char **map, t_game *game)
{
	while(*map[0])
        if (*map[0]++ != WALL)
            return(0);
    while(*map[((game->win_height) - 1)])
        if (*map[((game->win_height) - 1)] != WALL)
            return(0);
	return (1);
}

int	vertical_check(char **map, t_game *game)
{
    int h;
    int w;

    h = (game->win_height) - 1;
    w = (game->win_width);
	while(h >= 0)
        {
            if ((map[h][w - 1] != WALL) || (map[h][0]))
                return(0);
            h--;
        }
	return (1);
}

static void	check_wall(char **map, t_game *game)
{
	int	vertical_check_err;
	int	horizontal_check_err;

	vertical_check_err = vertical_check(map, game);
	horizontal_check_err = horizontal_check(map, game);
	if (!vertical_check_err && !horizontal_check_err)
		return ;
    free_map(map);
    quit_game(game);
    ft_printf("\n\nINVALID MAP: WALL ERROR\n\n");
    return ;
}

void    check_map_character(char **map, t_game *game)
{
    int h;
    int w;

    h = (game->win_height) - 1;
    w = 0;
    while (map[h])
    {
        while(map[h][w]){
            if (map[h][w] == COLLECTABLE)
                game->collects_count++;
            else if (map[h][w] == EXIT)
                game->exit_count++;
            else if (map[h][w] == PLAYER)
                game->player_count++;
            else if (map[h][w] != EMPTY &&
                    map[h][w] != WALL &&
                    map[h][w] != '\0')
                {
                    error_map_invalid("Map has invalid character");
                    free_map(map);
                    quit_game(game);
                    return ;
                }
            w++;
        }
        h++;
    }
    
};

int check_map(char **map, t_game *game)
{   
    if (game->win_height == game->win_width)
        return (error_map_invalid("Not rectangular"));
    check_wall(map, game);
    check_map_character(map, game);
    if (game->collects_count == 0)
        return (error_map_invalid("Need at least 1 collectable"));
    if ((game->player_count != 1) || (game->exit_count != 1))
        return (error_map_invalid("More than 1 player/exit"));
    return (1);
};