/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_keys_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:28:07 by lbarreto          #+#    #+#             */
/*   Updated: 2025/08/01 12:02:21 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d_bonus.h"

void	open_close_door(t_data *d)
{
	int	direction_x;
	int	direction_y;
	
	direction_x = (int)d->raycast->pos_x;
	direction_y = (int)d->raycast->pos_y;
	if (fabs(d->raycast->pov_x) > fabs(d->raycast->pov_y))
	{
		if (d->raycast->pov_x > 0)
			direction_x += 1;
		else if (d->raycast->pov_x < 0)
			direction_x -= 1;
	}
	else
	{
		if (d->raycast->pov_y > 0)
			direction_y += 1;
		else if (d->raycast->pov_y < 0)
			direction_y -= 1;
	}
	if (d->map->grid[direction_y][direction_x] == 'D')
		d->map->grid[direction_y][direction_x] = 'd';
	else if (d->map->grid[direction_y][direction_x] == 'd')
		d->map->grid[direction_y][direction_x] = 'D';
}
