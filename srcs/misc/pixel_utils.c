/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:00:41 by yathayde          #+#    #+#             */
/*   Updated: 2025/07/16 16:29:44 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

void  put_pixel(t_data *d, int x, int y, int color)
{
    char  *dst;

    dst = d->mlx->main_img.addr + (y * d->mlx->main_img.line)
    + (x * (d->mlx->main_img.bpp / 8));
    *(unsigned int *)dst = (unsigned int)color;
}
