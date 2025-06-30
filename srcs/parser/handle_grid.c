/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:24:13 by lbarreto          #+#    #+#             */
/*   Updated: 2025/06/29 23:47:02 by lbarreto         ###   ########.fr       */
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
	int	j;
	int	recent_newline;

	j = -1;
	recent_newline = FALSE;
	while (map_file[*i + ++j])
	{
		if (map_file[*i + j] == ' ')
			map_file[*i + j] = 'x';
		else if (is_map_direction(map_file[*i + j]) == TRUE)
			{
				if (map->start_direction != 0)
					map_error(REPEATED_STARTING_DIRECTION, map);
				recent_newline = FALSE;
			}
		else if (map_file[*i + j] == '1' || map_file[*i + j] == '0')
			recent_newline = FALSE;
		else if (map_file[*i + j] == '\n' && recent_newline == TRUE)
			map_error(MAP_EMPTY_LINE, map);
		else if (map_file[*i + j] == '\n' && recent_newline == FALSE)
			recent_newline = TRUE;
		else
			map_error(INVALID_MAP_CONTENT, map);	
	}
	return (j);	
}

void	set_map_grid(t_map *map, char *map_file, int *i)
{
	int	j;
	
	j = verify_grid_characters(map, map_file, i);
	map->map_string = ft_substr(map_file, *i, j);
	*i += j;
	map->grid = ft_split(map->map_string, '\n');
}
