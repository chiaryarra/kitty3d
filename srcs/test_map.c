/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yathayde <yathayde@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:56:11 by yathayde          #+#    #+#             */
/*   Updated: 2025/07/09 17:20:57 by yathayde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_map.h"
#include <stdlib.h>
#include <stdio.h>

static char *stub_grid[] = {
    "111111111111",
    "1000000000001",
    "101110000001",
    "1000100W0001",
    "101010000001",
    "100000000001",
    "100000000001",  // ‘N’ = ponto de início
    "111111111111",
    NULL
};

t_map  *create_stub_map(void)
{
    t_map *m = malloc(sizeof(*m));
    if (!m)
    {
        perror("Error\nmalloc falhou");
        exit(EXIT_FAILURE);
    }

    /* ————— Parâmetros de tela ————— */
    m->screen_w      = 640;
    m->screen_h      = 480;

    /* ————— Stub do grid e cores ————— */
    m->grid          = stub_grid;
    m->floor_color   = 0x444444;          /* corresponde ao seu campo floor_color */
    m->ceiling_color = 0xCCCCCC;          /* corresponde ao seu campo ceiling_color */

    /* ————— Ponteiros MLX serão criados em init_engine ————— */
    m->mlx = NULL;
    m->win = NULL;
    /* m->img será inicializado por mlx_new_image() em init_engine */

    /* ————— Estado inicial do “player” ————— */
    m->pos_x   = 4.5;
    m->pos_y   = 6.5;
    m->dir_x   = 0.0;
    m->dir_y   = -1.0;
    m->plane_x = 0.66;
    m->plane_y = 0.0;

    return (m);
}
