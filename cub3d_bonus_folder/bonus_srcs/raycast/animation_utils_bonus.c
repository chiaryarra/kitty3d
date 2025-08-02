/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 23:52:05 by lbarreto          #+#    #+#             */
/*   Updated: 2025/08/02 00:04:47 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d_bonus.h"

void	init_nyancat_textures(t_data *d)
{
	d->mlx->nyan_cat = (t_img *)malloc(sizeof(t_img) * 9);
	if (!d->mlx->nyan_cat)
		general_errors_b(MALLOC_ERROR, d);
	import_texture_b("./assets/animations/.nyan_cat/frame_0_delay-0.1s.xpm", \
	d, &d->mlx->nyan_cat[0]);
	import_texture_b("./assets/animations/.nyan_cat/frame_0_delay-0.1s-1.xpm", \
	d, &d->mlx->nyan_cat[1]);
	import_texture_b("./assets/animations/.nyan_cat/frame_0_delay-0.1s-2.xpm", \
	d, &d->mlx->nyan_cat[2]);
	import_texture_b("./assets/animations/.nyan_cat/frame_0_delay-0.1s-3.xpm", \
	d, &d->mlx->nyan_cat[3]);
	import_texture_b("./assets/animations/.nyan_cat/frame_0_delay-0.1s-4.xpm", \
	d, &d->mlx->nyan_cat[4]);
	import_texture_b("./assets/animations/.nyan_cat/frame_0_delay-0.1s-5.xpm", \
	d, &d->mlx->nyan_cat[5]);
	import_texture_b("./assets/animations/.nyan_cat/frame_0_delay-0.1s-6.xpm", \
	d, &d->mlx->nyan_cat[6]);
	import_texture_b("./assets/animations/.nyan_cat/frame_0_delay-0.1s-7.xpm", \
	d, &d->mlx->nyan_cat[7]);
	import_texture_b("./assets/animations/.nyan_cat/frame_0_delay-0.1s-8.xpm", \
	d, &d->mlx->nyan_cat[8]);
}
