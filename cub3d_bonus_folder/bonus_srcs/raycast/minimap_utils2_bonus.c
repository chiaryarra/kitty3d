/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:36:58 by lbarreto          #+#    #+#             */
/*   Updated: 2025/07/29 13:46:50 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d_bonus.h"

void	draw_circle_b(t_data *d, t_vec coords, int radius, int color)
{
	int	y;
	int	x;

	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
				put_minimap_pixel_b(d, coords.x + x, coords.y + y, color);
			x++;
		}
		y++;
	}
}

static void	rotate_point_b(t_data *d, float *x, float *y, float angle)
{
	float	dx;
	float	dy;

	dx = *x - d->mlx->minimap_cs_px;
	dy = *y - d->mlx->minimap_cs_py;
	*x = dx * cosf(angle) - dy * sinf(angle) + d->mlx->minimap_cs_px;
	*y = dx * sinf(angle) + dy * cosf(angle) + d->mlx->minimap_cs_py;
}

void	draw_cat_paw_b(t_data *d)
{
	float		angle;
	int			paw_size;
	t_vec		toe;
	t_vec		paw;
	int			i;

	paw.x = d->mlx->minimap_cs_px;
	paw.y = d->mlx->minimap_cs_py;
	angle = atan2f((float)d->raycast->plane_y, (float)d->raycast->plane_x);
	paw_size = d->mlx->minimap_cs / 2;
	i = -1;
	while(i <= 1)
	{
		toe.x = d->mlx->minimap_cs_px + i * paw_size * 0.8f;
		toe.y = d->mlx->minimap_cs_py - paw_size * 0.8f;
		rotate_point_b(d, &toe.x, &toe.y, angle);
		draw_circle_b(d, toe, paw_size / 3, 0xDDAAFF);
		i += 2;
	}
	toe.x = d->mlx->minimap_cs_px;
	toe.y = d->mlx->minimap_cs_py - paw_size * 0.8f * 1.4f;
	rotate_point_b(d, &toe.x, &toe.y, angle);
	draw_circle_b(d, toe, paw_size / 3, 0xDDAAFF);
	draw_circle_b(d, paw, paw_size, 0xAA66CC);
}
