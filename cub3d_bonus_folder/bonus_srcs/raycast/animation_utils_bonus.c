/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 23:52:05 by lbarreto          #+#    #+#             */
/*   Updated: 2025/08/02 21:58:30 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d_bonus.h"

void	init_nyancat_textures(t_data *d)
{
	d->mlx->nyan_cat = (t_img *)ft_calloc(sizeof(t_img), 10);
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

static int	get_frames_count(t_img *animation)
{
	int	frames_count;

	frames_count = 0;
	while (animation[frames_count].img)
		frames_count++;
	return (frames_count);
}

t_img	get_animation_frame_b(t_data *d, t_img *animation)
{
	int		frames_count;
	int		frames_duration;	

	frames_count = get_frames_count(animation);
	frames_duration = 1000 / frames_count;
	return (animation[(d->map->run_time / frames_duration) % frames_count]);
}

void	set_easter_egg_animation(t_data *d, t_img *animation)
{
	static int	first_call;

	if (first_call == 0)
	{
		while (first_call < 4)
		{
			mlx_destroy_image(d->mlx->mlx, d->mlx->textures[first_call].img);
			first_call++;
		}
	}
	d->mlx->textures[0] = get_animation_frame_b(d, animation);
	d->mlx->textures[1] = get_animation_frame_b(d, animation);
	d->mlx->textures[2] = get_animation_frame_b(d, animation);
	d->mlx->textures[3] = get_animation_frame_b(d, animation);
}
