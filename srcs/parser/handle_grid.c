/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:24:13 by lbarreto          #+#    #+#             */
/*   Updated: 2025/06/30 19:11:18 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

int	direction_setter(char c)
{
	if (c == 'N')
		return (NORTH);
	if (c == 'S')
		return (SOUTH);
	if (c == 'E')
		return (EAST);
	if (c == 'W')
		return (WEST);
	return (0);
}


static int	verify_grid_characters(t_map *map, char *map_file, int *i)
{
	int	recent_newline;

	recent_newline = FALSE;
	while (map_file[(*i)])
	{
		if (map_file[*i] == ' ')
			map_file[*i] = 'x';
		else if (is_map_direction(map_file[*i]) == TRUE)
			{
				if (map->start_direction != 0)
					map_error(REPEATED_STARTING_DIRECTION, map);
				else
					map->start_direction = direction_setter(map_file[*i]);
				recent_newline = FALSE;
			}
		else if (map_file[*i] == '1' || map_file[*i] == '0')
			recent_newline = FALSE;
		else if (map_file[*i] == '\n' && recent_newline == TRUE)
			map_error(MAP_EMPTY_LINE, map);
		else if (map_file[*i] == '\n' && recent_newline == FALSE)
			recent_newline = TRUE;
		else
			map_error(INVALID_MAP_CONTENT, map);
		(*i)++;
	}
}

void	set_map_grid(t_map *map, char *map_file, int *i)
{
	int		temp_i;

	temp_i = *i;
	verify_grid_characters(map, map_file, i);
	if (map->start_direction == FALSE)
		map_error(MISSING_START_DIRECTION, map);
	map->map_string = ft_strdup(map_file + temp_i);
	map->grid = ft_split(map->map_string, '\n');
	map->grid_x_size = get_grid_x_size(map->grid);
	map->grid_y_size = get_grid_y_size(map->map_string); 
}
