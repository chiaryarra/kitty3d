/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yathayde <yathayde@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:00:36 by yathayde          #+#    #+#             */
/*   Updated: 2025/07/09 16:55:42 by yathayde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h> 
#include "kitty3d.h"
#include "pixel_utils.h"
#include "test_map.h"



void render_frame(t_map *m)
{
    /* 1) em cada frame, faça o ray-casting para desenhar paredes, teto e chão */
    cast_rays(m);

    /* 2) então envie o buffer para a janela */
    mlx_put_image_to_window(m->mlx,
                            m->win,
                            m->img.img,
                            0, 0);
}
