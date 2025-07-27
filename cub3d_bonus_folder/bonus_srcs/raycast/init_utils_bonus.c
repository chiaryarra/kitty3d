/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:19:04 by lbarreto          #+#    #+#             */
/*   Updated: 2025/07/26 21:24:12 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d_bonus.h"

void	init_bonuses(t_data *d)
{
	d->mlx->minimap.img = mlx_new_image(d->mlx->mlx, \
	d->mlx->s_width * 0.2, d->mlx->s_width * 0.2);
	d->mlx->minimap.addr = mlx_get_data_addr(d->mlx->minimap.img, \
	&d->mlx->minimap.bpp, &d->mlx->minimap.line, &d->mlx->minimap.endian);
}