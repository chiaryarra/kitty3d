/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:54:08 by lbarreto          #+#    #+#             */
/*   Updated: 2025/07/26 21:30:33 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d_bonus.h"

static void	put_minimap_pixel(t_data *d, int x, int y, int color)
{
	char	*dst;

	dst = d->mlx->minimap.addr + (y * d->mlx->minimap.line) \
	+ (x * (d->mlx->minimap.bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

static void	calc_minimap_pixelpos(t_data *d, int x, int y)
{
	int	minimap_step;

	if (d->map->grid_x_size > d->map->grid_y_size)
		minimap_step = d->mlx->s_width * 0.2 / d->map->grid_x_size;
	else 
		minimap_step = d->mlx->s_width * 0.2 / d->map->grid_y_size;
	// my_printf("y: %d virtual y: %d x: %d virtual x: %d\n", y, y / minimap_block_h, x, x / minimap_block_w);
	if (y / minimap_step >= d->map->grid_y_size || x / minimap_step >= d->map->grid_x_size)
		return ;
	if (d->map->grid[(y / minimap_step)][(x / minimap_step)] == '1')
		put_minimap_pixel(d, x, y, 3217);
}

void	draw_minimap(t_data *d)
{
	int y;
	int	x;
	
	y = 0;
	while (y < d->mlx->s_width * 0.2)
	{
		x = 0;
		while (x < d->mlx->s_width * 0.2)
		{
			calc_minimap_pixelpos(d, x, y);
			x++;
		}
		y++;
	}
}
