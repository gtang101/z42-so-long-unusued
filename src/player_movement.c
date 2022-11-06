#include "../so_long.h"

int move_to_empty(t_game *game, t_tile *tile)
{
    tile->current_type = PLAYER;
    if (game->player.tile->current_type != EXIT)
        game->player.tile->current_type = EMPTY;
    game->player.tile = tile;
    return (1);
};

int move_to_collect(t_game *game, t_tile *tile)
{
    tile->current_type = PLAYER;
    ft_printf("Collected a power up, %d remaining", --game->collects_count);
    game->player.tile->current_type = EMPTY;
    return (1);
};

int move_to_exit(t_game *game)
{
    if(game->collects_count)
        return (0);
    game->player.tile->current_type = EMPTY;
    game->player.tile = NULL;
    ft_printf("Nice work! Total move count: %d", game->collects_count);
    quit_game(game);
    return (0);
};

int move_to_die(t_game *game)
{
    game->player.tile->current_type = EMPTY;
    game->player.tile = NULL;
    ft_printf("YOU DIED");
    quit_game(game);
    return (1);
};

int player_movement(t_game *game, t_tile *tile)
{
    int valid_move;

    valid_move = 0;
    if (tile->current_type == EMPTY)
        valid_move = move_to_empty(game, tile);
    else if (tile->current_type == COLLECTABLE)
        valid_move = move_to_collect(game, tile);
    else if (tile->current_type == EXIT)
        valid_move = move_to_exit(game);
    else if (tile->current_type == ENEMY)
    {    
        valid_move = move_to_die(game);
    }
    else 
        return (0);
    if (valid_move)
        ft_printf("Number of moves: %d\n", ++game->moves_count);
    ft_printf("INVALID MOVE\nEither stop slamming into the wall, or collect all your power ups!\n");
    return (0);
}