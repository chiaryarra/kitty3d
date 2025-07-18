/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:26:04 by yathayde          #+#    #+#             */
/*   Updated: 2025/07/18 17:13:47 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

static void	set_rays_data(t_data *d, int x)
{
	d->raycast->ray.camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	d->raycast->ray.ray_dir_x = d->raycast->pov_x + \
	d->raycast->plane_x * d->raycast->ray.camera_x;
	d->raycast->ray.ray_dir_y = d->raycast->pov_y + \
	d->raycast->plane_y * d->raycast->ray.camera_x;
	d->raycast->ray.map_x = (int)d->raycast->pos_x;
	d->raycast->ray.map_y = (int)d->raycast->pos_y;
	d->raycast->ray.delta_x = fabs(1 / d->raycast->ray.ray_dir_x);
	d->raycast->ray.delta_y = fabs(1 / d->raycast->ray.ray_dir_y);
}

static void	calculate_step_and_distance(t_data *d)
{
	if (d->raycast->ray.ray_dir_x < 0)
	{
        d->raycast->ray.step_x = -1;
        d->raycast->ray.side_dist_x = (d->raycast->pos_x - \
		d->raycast->ray.map_x) * d->raycast->ray.delta_x;
    }
    else
    {
        d->raycast->ray.step_x = 1;
        d->raycast->ray.side_dist_x = (d->raycast->ray.map_x + \
		1.0 - d->raycast->pos_x) * d->raycast->ray.delta_x;
    }
	if (d->raycast->ray.ray_dir_y < 0)
    {
        d->raycast->ray.step_y = -1;
        d->raycast->ray.side_dist_y = (d->raycast->pos_y - \
		d->raycast->ray.map_y) * d->raycast->ray.delta_y;
    }
    else
    {
        d->raycast->ray.step_y = 1;
        d->raycast->ray.side_dist_y = (d->raycast->ray.map_y + \
		1.0 - d->raycast->pos_y) * d->raycast->ray.delta_y;
    }
}

static void	wall_check(t_data *d)
{
	d->raycast->ray.wall_hit = FALSE;
	d->raycast->ray.wall_is_side = FALSE;
	while (d->raycast->ray.wall_hit == FALSE)
        {
            if (d->raycast->ray.side_dist_x < d->raycast->ray.side_dist_y)
            {
                d->raycast->ray.side_dist_x += d->raycast->ray.delta_x;
                d->raycast->ray.map_x += d->raycast->ray.step_x;
                d->raycast->ray.wall_is_side = FALSE;
            }
            else
            {
                d->raycast->ray.side_dist_y += d->raycast->ray.delta_y;
                d->raycast->ray.map_y += d->raycast->ray.step_y;
                d->raycast->ray.wall_is_side = TRUE;
            }
            if (d->map->grid[d->raycast->ray.map_y][d->raycast->ray.map_x] \
			== '1')
            d->raycast->ray.wall_hit = TRUE;
        }
}

void	cast_rays(t_data *d)
{
	int color;
    int x = 0;
    while (x < SCREEN_WIDTH)
    {
		set_rays_data(d, x);
        /* 4) calcular step e distancia inicial até o primeiro lado */
        calculate_step_and_distance(d);
        /* 5) DDA: avançar até encontrar uma parede '1' */
        //my_printf("player y: %d\nplayer x: %d\n", map_y, map_x);
        /* 6) calcular distância perpendicular do jogador até a parede */
        double perp_dist;
        if (side == 0)
        {
            perp_dist = (map_x - d->raycast->pos_x + (1 - step_x) / 2.0) / ray_dir_x;
        }
        else
        {
            perp_dist = (map_y - d->raycast->pos_y + (1 - step_y) / 2.0) / ray_dir_y;
        }
        /* 7) altura da linha de parede a desenhar */
        int line_h = (int)(SCREEN_HEIGHT / perp_dist);
        
        /* 8) limites de desenho vertical */
        int draw_start = -line_h / 2 + SCREEN_HEIGHT / 2;
        if (draw_start < 0)
        draw_start = 0;
        int draw_end = line_h / 2 + SCREEN_HEIGHT / 2;
        if (draw_end >= SCREEN_HEIGHT)
        draw_end = SCREEN_HEIGHT - 1;
        /* 9) cor simples: um tom diferente se foi hit no eixo Y */
        if (d->raycast->ray.wall_is_side)
            color = 0x42F5E0;
        else
        	color = 0xE82E15;
        /* 10) desenha a “faixa” da parede */
        int y = draw_start;
        while (y < draw_end)
        {
            put_pixel(d, x, y, color);
            y++;
        }
        /* 11) desenha teto e chão ao redor */
        y = 0;
        while (y < draw_start)
        {
            put_pixel(d, x, y, d->map->ceiling_color);
            y++;
        }
        y = draw_end;
        while (y < SCREEN_HEIGHT)
        {
            put_pixel(d, x, y, d->map->floor_color);
            y++;
        }
        x++;
    }
}
