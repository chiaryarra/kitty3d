/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 23:13:30 by lbarreto          #+#    #+#             */
/*   Updated: 2025/07/22 00:16:04 by lbarreto         ###   ########.fr       */
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
	raycast->ray->wall_hit_point -= (int)raycast->ray->wall_hit_point;
}

void	calculate_texture_position(t_data *d, t_img texture)
{
	d->raycast->ray->tex_x = (int)(texture.width * \
	d->raycast->ray->wall_hit_point);
	d->raycast->ray->tex_step = (double)(texture.height) \
	/ d->raycast->ray->line_h;
	d->raycast->ray->tex_y_start = (d->raycast->ray->draw_start - SCREEN_HEIGHT / 2 + d->raycast->ray->line_h / 2) * d->raycast->ray->tex_step;
}

void	check_to_calculate_texture_positions(t_data *d)
{
	if (d->raycast->ray->wall_side_hit == NORTH)
		calculate_texture_position(d, d->mlx->textures[0]);
	if (d->raycast->ray->wall_side_hit == EAST)
		calculate_texture_position(d, d->mlx->textures[1]);
	if (d->raycast->ray->wall_side_hit == SOUTH)
		calculate_texture_position(d, d->mlx->textures[2]);
	if (d->raycast->ray->wall_side_hit == WEST)
		calculate_texture_position(d, d->mlx->textures[3]);
}