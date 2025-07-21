/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 23:13:30 by lbarreto          #+#    #+#             */
/*   Updated: 2025/07/21 15:58:11 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

void	set_wall_hit_direction(t_raycast *raycast)
{
	if (raycast->ray->wall_is_horizontal == TRUE) 
	{
		raycast->ray->wall_hit_point = raycast->ray->perp_dist * \
		raycast->ray->ray_dir_x + raycast->pos_x;
		if (raycast->ray->ray_dir_y < 0)
			raycast->ray->wall_side_hit = WEST;
		else
			raycast->ray->wall_side_hit = EAST;
	}
	else
	{
		raycast->ray->wall_hit_point = raycast->ray->perp_dist * \
		raycast->ray->ray_dir_y + raycast->pos_y;
		if (raycast->ray->ray_dir_x < 0)
			raycast->ray->wall_side_hit = SOUTH;
		else 
			raycast->ray->wall_side_hit = NORTH;
	}
}