/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_grid_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:20:58 by lbarreto          #+#    #+#             */
/*   Updated: 2025/07/23 15:43:35 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

int	get_grid_x_size(char **grid)
{
	int	i;
	int	bigger_line;

	if (grid == NULL)
		return (0);
	i = 0;
	bigger_line = 0;
	while (grid[i])
	{
		if ((int)ft_strlen(grid[i]) > bigger_line)
			bigger_line = ft_strlen(grid[i]);
		i++;
	}
	return (bigger_line);
}

int	get_grid_y_size(char *map_string)
{
	int	i;
	int	lines_count;

	if (map_string == NULL)
		return (0);
	i = 0;
	lines_count = 1;
	while (map_string[i])
	{
		if (map_string[i] == '\n')
			lines_count++;
		i++;
	}
	return (lines_count);
}

static void	kitty_flood_fill(t_map *map, char **grid, int x, int y)
{
	int	i;

	i = -1;
	if (x < 0 || y < 0 || x >= map->grid_x_size + 2 \
	|| y >= map->grid_y_size + 2)
		return ;
	if (grid[y][x] == 'X' || grid[y][x] == '1')
		return ;
	if (grid[y][x] != 'x')
	{
		while (grid[++i])
			free(grid[i]);
		free(grid);
		map_error(GRID_ERROR, map);
	}
	grid[y][x] = 'X';
	kitty_flood_fill(map, grid, x + 1, y);
	kitty_flood_fill(map, grid, x - 1, y);
	kitty_flood_fill(map, grid, x, y + 1);
	kitty_flood_fill(map, grid, x, y - 1);
}

void	verify_grid(t_map *map, char **grid)
{
	int	x;
	int	y;

	y = -1;
	my_printf("map: \n");
	while (++y < map->grid_y_size + 2)
		my_printf("%s\n", grid[y]);
	y = -1;
	while (++y < map->grid_y_size + 2)
	{
		x = -1;
		while (++x < map->grid_x_size + 2)
		{
			if (grid[y][x] == 'x')
				kitty_flood_fill(map, grid, x, y);
		}
	}
}

char	*fill_line(int lenght_of_line)
{
	char	*line;
	int		i;

	i = 0;
	line = (char *)malloc((lenght_of_line + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (i < lenght_of_line)
	{
		line[i] = 'x';
		i++;
	}
	line[i] = '\0';
	return (line);
}
