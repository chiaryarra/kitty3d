/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:26:04 by yathayde          #+#    #+#             */
/*   Updated: 2025/08/02 21:52:26 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d_bonus.h"

static void	set_rays_data_b(t_data *d, int x)
{
	d->raycast->ray->camera_x = 2 * x / (double)d->mlx->s_width - 1;
	d->raycast->ray->ray_dir_x = d->raycast->pov_x + \
	d->raycast->plane_x * d->raycast->ray->camera_x;
	d->raycast->ray->ray_dir_y = d->raycast->pov_y + \
	d->raycast->plane_y * d->raycast->ray->camera_x;
	d->raycast->ray->map_x = (int)d->raycast->pos_x;
	d->raycast->ray->map_y = (int)d->raycast->pos_y;
	d->raycast->ray->delta_x = fabs(1 / d->raycast->ray->ray_dir_x);
	d->raycast->ray->delta_y = fabs(1 / d->raycast->ray->ray_dir_y);
}

static void	calculate_step_and_distance_b(t_data *d)
{
	if (d->raycast->ray->ray_dir_x < 0)
	{
		d->raycast->ray->step_x = -1;
		d->raycast->ray->side_dist_x = (d->raycast->pos_x - \
		d->raycast->ray->map_x) * d->raycast->ray->delta_x;
	}
	else
	{
		d->raycast->ray->step_x = 1;
		d->raycast->ray->side_dist_x = (d->raycast->ray->map_x + \
		1.0 - d->raycast->pos_x) * d->raycast->ray->delta_x;
	}
	if (d->raycast->ray->ray_dir_y < 0)
	{
		d->raycast->ray->step_y = -1;
		d->raycast->ray->side_dist_y = (d->raycast->pos_y - \
		d->raycast->ray->map_y) * d->raycast->ray->delta_y;
	}
	else
	{
		d->raycast->ray->step_y = 1;
		d->raycast->ray->side_dist_y = (d->raycast->ray->map_y + \
		1.0 - d->raycast->pos_y) * d->raycast->ray->delta_y;
	}
}

static void	wall_check_b(t_data *d)
{
	d->raycast->ray->wall_hit = FALSE;
	d->raycast->ray->wall_is_horizontal = FALSE;
	while (d->raycast->ray->wall_hit == FALSE)
	{
		if (d->raycast->ray->side_dist_x < d->raycast->ray->side_dist_y)
		{
			d->raycast->ray->side_dist_x += d->raycast->ray->delta_x;
			d->raycast->ray->map_x += d->raycast->ray->step_x;
			d->raycast->ray->wall_is_horizontal = FALSE;
		}
		else
		{
			d->raycast->ray->side_dist_y += d->raycast->ray->delta_y;
			d->raycast->ray->map_y += d->raycast->ray->step_y;
			d->raycast->ray->wall_is_horizontal = TRUE;
		}
		if (ft_strchr("1D", d->map->grid[d->raycast->ray->map_y] \
		[d->raycast->ray->map_x]))
		{
			d->raycast->ray->wall_hit = TRUE;
			if (d->map->grid[d->raycast->ray->map_y] \
			[d->raycast->ray->map_x] == 'D')
				d->raycast->ray->door_hit = TRUE;
		}
	}
}

void	set_draw_points_b(t_data *d)
{
	if (d->raycast->ray->wall_is_horizontal == FALSE)
		d->raycast->ray->perp_dist = \
		(d->raycast->ray->map_x - d->raycast->pos_x + \
		(1 - d->raycast->ray->step_x) / 2.0) / d->raycast->ray->ray_dir_x;
	else
		d->raycast->ray->perp_dist = \
		(d->raycast->ray->map_y - d->raycast->pos_y + \
		(1 - d->raycast->ray->step_y) / 2.0) / d->raycast->ray->ray_dir_y;
	d->raycast->ray->line_h = (int) \
	(d->mlx->s_height / d->raycast->ray->perp_dist);
	d->raycast->ray->draw_start = -d->raycast->ray->line_h / 2 + \
	d->mlx->s_height / 2;
	if (d->raycast->ray->draw_start < 0)
		d->raycast->ray->draw_start = 0;
	d->raycast->ray->draw_end = \
	d->raycast->ray->line_h / 2 + d->mlx->s_height / 2;
	if (d->raycast->ray->draw_end >= d->mlx->s_height)
		d->raycast->ray->draw_end = d->mlx->s_height - 1;
}

void	cast_rays_b(t_data *d)
{
	int	x;

	x = 0;
	while (x < d->mlx->s_width)
	{
		d->raycast->ray = (t_rays *)ft_calloc(sizeof(t_rays), 1);
		if (!d->raycast->ray)
			general_errors_b(MALLOC_ERROR, d);
		set_rays_data_b(d, x);
		calculate_step_and_distance_b(d);
		wall_check_b(d);
		set_draw_points_b(d);
		set_wall_hit_direction_b(d->raycast);
		check_to_calculate_texture_positions_b(d);
		check_to_draw_rays_b(d, x);
		x++;
		free(d->raycast->ray);
	}
}
