/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:31:59 by yathayde          #+#    #+#             */
/*   Updated: 2025/07/16 16:43:45 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

int can_move(t_data *d, double x, double y)
{
    int mx;
    int my;

    mx = (int)x;
    my = (int)y;
    /* fora dos limites: */
    if (mx < 0)
        return (0);
    if (mx >= 8)    /* largura fixa do stub */
        return (0);
    if (my < 0)
        return (0);
    if (my >= 8)    /* altura fixa do stub */
        return (0);
    /* parede: */
    if (d->map->grid[my][mx] == '1')
        return (0);
    return (1);
}