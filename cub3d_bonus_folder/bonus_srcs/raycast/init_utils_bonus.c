/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:19:04 by lbarreto          #+#    #+#             */
/*   Updated: 2025/07/29 13:10:01 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d_bonus.h"

static void	init_minimap(t_data *d)
{
	if (d->mlx->s_height * 0.2 / d->map->grid_y_size < \
	d->mlx->s_width * 0.2 / d->map->grid_x_size)
		d->mlx->minimap_cs = d->mlx->s_height * 0.2 / d->map->grid_y_size;
	else
		d->mlx->minimap_cs = d->mlx->s_width * 0.2 / d->map->grid_x_size;
	d->mlx->minimap.height = d->map->grid_y_size * d->mlx->minimap_cs;
	d->mlx->minimap.width = d->map->grid_x_size * d->mlx->minimap_cs;
	d->mlx->minimap.img = mlx_new_image(d->mlx->mlx, \
	d->mlx->minimap.width, d->mlx->minimap.height);
	d->mlx->minimap.addr = mlx_get_data_addr(d->mlx->minimap.img, \
	&d->mlx->minimap.bpp, &d->mlx->minimap.line, &d->mlx->minimap.endian);
	d->mlx->minimap_step_x = d->mlx->minimap.width / d->map->grid_x_size;
	d->mlx->minimap_step_y = d->mlx->minimap.height / d->map->grid_y_size;
}

void	init_bonuses(t_data *d)
{
	init_minimap(d);
}