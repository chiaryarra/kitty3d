/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window_stub.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yathayde <yathayde@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:00:51 by yathayde          #+#    #+#             */
/*   Updated: 2025/07/09 16:21:15 by yathayde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kitty3d.h"
#include "test_map.h"

int  close_window_stub(t_map *m)
{
    mlx_destroy_image(m->mlx, m->img.img);
    mlx_destroy_window(m->mlx, m->win);
    free(m);
    exit(EXIT_SUCCESS);
    return (0);
}
