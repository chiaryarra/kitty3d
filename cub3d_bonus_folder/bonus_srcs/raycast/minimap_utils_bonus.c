/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:54:08 by lbarreto          #+#    #+#             */
/*   Updated: 2025/08/02 21:56:27 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d_bonus.h"

void	put_minimap_pixel_b(t_data *d, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > d->mlx->minimap.width \
	|| y > d->mlx->minimap.height)
		return ;
	dst = d->mlx->minimap.addr + (y * d->mlx->minimap.line) \
	+ (x * (d->mlx->minimap.bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

static int	define_color(t_data *d, int x, int y)
{
	int	color;

	color = 0;
	if (ft_strchr("1", d->map->grid[y][x]))
		color = 0xBB8D67;
	else if (ft_strchr("D", d->map->grid[y][x]))
		color = 0x23429E;
	else if (ft_strchr("d", d->map->grid[y][x]))
		color = 0xB3EDE3;
	return (color);
}

static void	draw_map_blocks_b(t_data *d, int x, int y)
{
	int	py;
	int	px;
	int	color;

	py = 0;
	while (py < d->mlx->minimap_step_y)
	{
		px = 0;
		while (px < d->mlx->minimap_step_x)
		{
			color = *(int *)(d->mlx->main_img.addr + \
			((y * d->mlx->minimap_step_y + py) * d->mlx->main_img.line \
			+ (x * d->mlx->minimap_step_x + px) * \
			(d->mlx->main_img.bpp / 8)));
			if (ft_strchr("1Dd", d->map->grid[y][x]))
				color = define_color(d, x, y);
			put_minimap_pixel_b(d, x * d->mlx->minimap_step_x + px, \
			y * d->mlx->minimap_step_y + py, color);
			px++;
		}
		py++;
	}
	draw_cat_paw_b(d);
}

void	draw_minimap_b(t_data *d)
{
	int	x;
	int	y;

	y = 0;
	d->mlx->minimap_cs_py = (int)(d->raycast->pos_y * d->mlx->minimap_cs);
	d->mlx->minimap_cs_px = (int)(d->raycast->pos_x * d->mlx->minimap_cs);
	while (y < d->map->grid_y_size)
	{
		x = 0;
		while (x < d->map->grid_x_size)
		{
			draw_map_blocks_b(d, x, y);
			x++;
		}
		y++;
	}
}
