/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:00:41 by yathayde          #+#    #+#             */
/*   Updated: 2025/07/19 16:26:13 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

void	put_pixel(t_data *d, int x, int y, int color)
{
    char  *dst;

    dst = d->mlx->main_img.addr + (y * d->mlx->main_img.line)
    + (x * (d->mlx->main_img.bpp / 8));
    *(unsigned int *)dst = (unsigned int)color;
}

void	draw_rays(t_data *d, int x, int color)
{
	int	y;
	y = d->raycast->ray->draw_start;
	while (y < d->raycast->ray->draw_end)
	{
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

