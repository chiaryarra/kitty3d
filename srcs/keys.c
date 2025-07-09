/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yathayde <yathayde@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:00:58 by yathayde          #+#    #+#             */
/*   Updated: 2025/07/09 17:32:43 by yathayde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kitty3d.h"
#include "test_map.h"
#include <stdio.h>
#include <math.h>

#define MOVE_STEP   0.1
#define ROT_ANGLE   0.05

/* códigos de tecla no Linux+MLX */
#define KEY_W       119
#define KEY_S       115
#define KEY_A        97
#define KEY_D       100
#define KEY_ESC   65307
#define KEY_LEFT  65361
#define KEY_RIGHT 65363

int key_press(int key, t_map *m)
{
    double nx, ny;
    double move_dir;
    double rotate_ang;
    double old_dir_x;
    double old_plane_x;

    /* —— MOVE para frente/atrás —— */
    if (key == KEY_W || key == KEY_S)
    {
        /* sem ternário: */
        if (key == KEY_W)
            move_dir = 1.0;
        else
            move_dir = -1.0;

        /* tenta mover no eixo X */
        nx = m->pos_x + move_dir * m->dir_x * MOVE_STEP;
        ny = m->pos_y;
        if (can_move(m, nx, ny))
            m->pos_x = nx;

        /* tenta mover no eixo Y */
        nx = m->pos_x;
        ny = m->pos_y + move_dir * m->dir_y * MOVE_STEP;
        if (can_move(m, nx, ny))
            m->pos_y = ny;
    }
    /* —— STRAFE lateral —— */
    else if (key == KEY_A || key == KEY_D)
    {
        if (key == KEY_D)
            move_dir = 1.0;
        else
            move_dir = -1.0;

        nx = m->pos_x + move_dir * m->plane_x * MOVE_STEP;
        ny = m->pos_y;
        if (can_move(m, nx, ny))
            m->pos_x = nx;

        nx = m->pos_x;
        ny = m->pos_y + move_dir * m->plane_y * MOVE_STEP;
        if (can_move(m, nx, ny))
            m->pos_y = ny;
    }
    /* —— ROTAÇÃO —— */
    else if (key == KEY_LEFT || key == KEY_RIGHT)
    {
        if (key == KEY_LEFT)
            rotate_ang = ROT_ANGLE;
        else
            rotate_ang = -ROT_ANGLE;

        old_dir_x   = m->dir_x;
        old_plane_x = m->plane_x;

        /* rotaciona o vetor direção */
        m->dir_x   = m->dir_x * cos(rotate_ang)
                     - m->dir_y * sin(rotate_ang);
        m->dir_y   = old_dir_x   * sin(rotate_ang)
                     + m->dir_y * cos(rotate_ang);

        /* rotaciona o “plano” da câmera */
        m->plane_x = m->plane_x * cos(rotate_ang)
                     - m->plane_y * sin(rotate_ang);
        m->plane_y = old_plane_x * sin(rotate_ang)
                     + m->plane_y * cos(rotate_ang);
    }
    /* —— SAIR —— */
    else if (key == KEY_ESC)
    {
        close_window_stub(m);
    }

    printf("Player pos: (%.2f, %.2f)\n", m->pos_x, m->pos_y);
    return (0);
}

}
