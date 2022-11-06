#include "../so_long.h"

static int	file_linecount(char *map_file)
{
	int		linecount;
	int		fd;
	int		readcount;
	char	c;	

	fd = open(map_file, O_RDONLY);
	if (!fd)
		return (-1);
	linecount = 1;
	while (1)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			linecount++;
	}
	close(fd);
	return (linecount);
}

static char	**alloc_columns(char *map_file)
{
	char	**map;
	int		linecount;

	linecount = file_linecount(map_file);
	if (linecount <= 0)
	{
		ft_printf("open or reading error, the file may not exist");
		return (NULL);
	}
	map = malloc(sizeof(char *) * linecount + 1);
	if (map == NULL)
	{
		ft_printf("malloc error on alloc_map()");
		return (NULL);
	}
	ft_printf("\n\nalloc_columns: SUCCESS\n\n");
	return (map);
}

void	assign_temp(char *map, char *temp)
{
	int	len;

	if (!temp)
		return ;
	len = ft_strlen(temp);
	map = malloc(sizeof(char *) * len + 1);
	ft_strlcpy(map, temp, len);
	free(temp);
	ft_printf("\n\nassign_temp: SUCCESS\n\n");
}

char    **read_map(t_game *game, char *map_file)
{
    char    **map;
	char	*temp;
    int     fd;
    int     i;

    i = 0;
    map = alloc_columns(map_file);
	if (!map)
		return (NULL);
    fd = open(map_file, O_RDONLY);
    if (fd < 0)
        return (0);
    while (1)
    {
		temp = get_next_line(fd);
		if (temp == NULL)
            break ;
		ft_printf("\n\nCHECK HERE\n\n");
		assign_temp(map[i], temp);
		i++;
	}	
    game->win_height = i++;
	game->win_width = ft_strlen(map[0]);
    close(fd);
	ft_printf("\n\nread_map: SUCCESS\n\n");
    return (map);
}