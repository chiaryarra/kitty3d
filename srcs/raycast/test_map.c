/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:56:11 by yathayde          #+#    #+#             */
/*   Updated: 2025/07/15 15:58:11 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

t_raycast  *create_starting_position(t_data *data)
{
    t_raycast *raycast; 
    
    raycast = (t_raycast *)malloc(sizeof(t_raycast) * 1);
    if (!raycast)
    {
        perror("Error\nmalloc falhou");
        exit(EXIT_FAILURE);
    }
    raycast->pos_x = (double)(data->map->player_x + 0.5);
    raycast->pos_y = 6.5;
    raycast->pov_x = 0.0;
    raycast->pov_y = -1.0;
    raycast->plane_x = 0.66;
    raycast->plane_y = 0.0;

    return (raycast);
}
