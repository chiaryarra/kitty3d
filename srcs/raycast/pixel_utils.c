/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yathayde <yathayde@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:00:41 by yathayde          #+#    #+#             */
/*   Updated: 2025/07/09 16:00:42 by yathayde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pixel_utils.h"

void  put_pixel(t_map *m, int x, int y, int color)
{
    char  *dst;

    dst = m->img.addr
        + (y * m->img.line)
        + (x * (m->img.bpp / 8));
    *(unsigned int *)dst = (unsigned int)color;
}
