/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:00:41 by yathayde          #+#    #+#             */
/*   Updated: 2025/07/25 16:46:09 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

void	put_pixel(t_data *d, int x, int y, int color)
{
	char	*dst;

	dst = d->mlx->main_img.addr + (y * d->mlx->main_img.line) \
	+ (x * (d->mlx->main_img.bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

void	draw_rays(t_data *d, int x, t_img texture)
{
	int	color;
	int	y;

	y = d->raycast->ray->draw_start;
	while (y < d->raycast->ray->draw_end)
	{
		d->raycast->ray->tex_y = (int)d->raycast->ray->tex_y_start;
		color = *(int *)(texture.addr + (d->raycast->ray->tex_y * \
		texture.line + d->raycast->ray->tex_x * (texture.bpp / 8)));
		d->raycast->ray->tex_y_start += d->raycast->ray->tex_step;
		put_pixel(d, x, y, color);
		y++;
	}
	y = 0;
	while (y < d->raycast->ray->draw_start)
	{
		put_pixel(d, x, y, d->map->ceiling_color);
		y++;
	}
	y = d->raycast->ray->draw_end;
	while (y < SCREEN_HEIGHT)
	{
		put_pixel(d, x, y, d->map->floor_color);
		y++;
	}
}

void	check_to_draw_rays(t_data *d, int x)
{
	if (d->raycast->ray->wall_side_hit == NORTH)
		draw_rays(d, x, d->mlx->textures[0]);
	if (d->raycast->ray->wall_side_hit == EAST)
		draw_rays(d, x, d->mlx->textures[1]);
	if (d->raycast->ray->wall_side_hit == SOUTH)
		draw_rays(d, x, d->mlx->textures[2]);
	if (d->raycast->ray->wall_side_hit == WEST)
		draw_rays(d, x, d->mlx->textures[3]);
}
