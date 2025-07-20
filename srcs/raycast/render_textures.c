/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 23:13:30 by lbarreto          #+#    #+#             */
/*   Updated: 2025/07/19 23:32:41 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

void	set_wall_hit_direction(t_rays *ray)
{
	if (ray->wall_is_side == TRUE) 
	{
		if (ray->ray_dir_y < 0)
			ray->wall_side_hit = WEST;
		else
			ray->wall_side_hit = EAST;	
	}
	else
	{
		if (ray->ray_dir_x < 0)
			ray->wall_side_hit = SOUTH;
		else 
			ray->wall_side_hit = NORTH;
	}
}