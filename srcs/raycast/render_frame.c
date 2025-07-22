/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:00:36 by yathayde          #+#    #+#             */
/*   Updated: 2025/07/19 23:16:06 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

void render_frame(t_data *data)
{
    /* 1) em cada frame, faça o ray-casting para desenhar paredes, teto e chão */
    cast_rays(data);
    /* 2) então envie o buffer para a janela */
    mlx_put_image_to_window(data->mlx->mlx, data->mlx->window, \
    data->mlx->main_img.img, 0, 0);
//     mlx_put_image_to_window(data->mlx->mlx, data->mlx->window, \
//     data->mlx->textures[0].img, 0, 0);
}
