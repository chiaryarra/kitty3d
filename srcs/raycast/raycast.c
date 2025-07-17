/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:26:04 by yathayde          #+#    #+#             */
/*   Updated: 2025/07/17 14:41:40 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

void cast_rays(t_data *d)
{
    int x = 0;
    while (x < SCREEN_WIDTH)
    {
        /* 1) calcular direção do raio para esta coluna */
        double camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
        //printf("camera x: %f\npov x: %f\npov y: %f\n", camera_x, d->raycast->pov_x, d->raycast->pov_y);
        double ray_dir_x = d->raycast->pov_x + d->raycast->plane_x * camera_x;
        double ray_dir_y = d->raycast->pov_y + d->raycast->plane_y * camera_x;

        int map_x = (int)d->raycast->pos_x;
        int map_y = (int)d->raycast->pos_y;
        /* 3) distâncias de um passo para o próximo eixo */
        double delta_x = fabs(1 / ray_dir_x);
        double delta_y = fabs(1 / ray_dir_y);

        /* 4) calcular step e distancia inicial até o primeiro lado */
        int step_x, step_y;
        double side_dist_x, side_dist_y;
        if (ray_dir_x < 0)
        {
            step_x = -1;
            side_dist_x = (d->raycast->pos_x - map_x) * delta_x;
        }
        else
        {
            step_x = 1;
            side_dist_x = (map_x + 1.0 - d->raycast->pos_x) * delta_x;
        }
        if (ray_dir_y < 0)
        {
            step_y = -1;
            side_dist_y = (d->raycast->pos_y - map_y) * delta_y;
        }
        else
        {
            step_y = 1;
            side_dist_y = (map_y + 1.0 - d->raycast->pos_y) * delta_y;
        }
        /* 5) DDA: avançar até encontrar uma parede '1' */
        int hit = 0, side = 0;
        //my_printf("player y: %d\nplayer x: %d\n", map_y, map_x);
        while (!hit)
        {
            if (side_dist_x < side_dist_y)
            {
                side_dist_x += delta_x;
                map_x += step_x;
                side = 0;
            }
            else
            {
                side_dist_y += delta_y;
                map_y += step_y;
                side = 1;
            }
            if (d->map->grid[map_y][map_x] == '1')
            hit = 1;
            //my_printf("player y: %d\nplayer x: %d\n", map_y, map_x);
        }
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
        int color;
        if (side)
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
