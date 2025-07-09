/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yathayde <yathayde@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:31:59 by yathayde          #+#    #+#             */
/*   Updated: 2025/07/09 17:32:04 by yathayde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_map.h"

int can_move(t_map *m, double x, double y)
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
    if (m->grid[my][mx] == '1')
        return (0);
    return (1);
}