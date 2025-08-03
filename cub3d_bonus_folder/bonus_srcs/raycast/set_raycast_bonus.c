/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_raycast_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:56:43 by lbarreto          #+#    #+#             */
/*   Updated: 2025/07/29 13:48:46 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d_bonus.h"

static void	set_pov_b(t_data *data, t_raycast *raycast)
{
	if (data->map->start_direction == NORTH)
	{
		raycast->pov_x = 0;
		raycast->pov_y = -1.0;
	}
	else if (data->map->start_direction == SOUTH)
	{
		raycast->pov_x = 0;
		raycast->pov_y = 1.0;
	}
	else if (data->map->start_direction == WEST)
	{
		raycast->pov_x = -1.0;
		raycast->pov_y = 0;
	}
	else if (data->map->start_direction == EAST)
	{
		raycast->pov_x = 1.0;
		raycast->pov_y = 0;
	}
}

t_raycast	*create_starting_position_b(t_data *data)
{
	t_raycast	*raycast;

	raycast = (t_raycast *)ft_calloc(sizeof(t_raycast), 1);
	if (!raycast)
		general_errors_b(MALLOC_ERROR, data);
	raycast->pos_x = (double)(data->map->player_x + 0.5);
	raycast->pos_y = (double)(data->map->player_y + 0.5);
	set_pov_b(data, raycast);
	raycast->plane_x = -raycast->pov_y * FOV_RANGE;
	raycast->plane_y = raycast->pov_x * FOV_RANGE;
	return (raycast);
}
