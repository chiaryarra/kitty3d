/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:00:02 by lbarreto          #+#    #+#             */
/*   Updated: 2025/07/29 13:40:30 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d_bonus.h"

int	get_player_x_b(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->grid_y_size)
	{
		x = 0;
		while (x < map->grid_x_size - 1)
		{
			if (map->grid[y][x] && is_map_direction_b(map->grid[y][x]) == TRUE)
				return (x);
			x++;
		}
		y++;
	}
	return (-1);
}

int	get_player_y_b(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->grid_y_size)
	{
		x = 0;
		while (x < map->grid_x_size - 1)
		{
			if (is_map_direction_b(map->grid[y][x]) == TRUE)
				return (y);
			x++;
		}
		y++;
	}
	return (-1);
}
