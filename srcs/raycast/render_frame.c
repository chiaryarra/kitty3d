/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:00:36 by yathayde          #+#    #+#             */
/*   Updated: 2025/07/12 20:46:34 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

void render_frame(t_data *data)
{
    /* 1) em cada frame, faça o ray-casting para desenhar paredes, teto e chão */
    cast_rays(data->map);
    /* 2) então envie o buffer para a janela */
    mlx_put_image_to_window(m->mlx,
                            m->win,
                            m->img.img,
                            0, 0);
}
