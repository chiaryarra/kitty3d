/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_keys_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:28:07 by lbarreto          #+#    #+#             */
/*   Updated: 2025/08/02 21:57:43 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d_bonus.h"

static void	set_door_directions_b(t_data *d, int *x, int *y)
{
	*x = (int)d->raycast->pos_x;
	*y = (int)d->raycast->pos_y;
	if (fabs(d->raycast->pov_x) > fabs(d->raycast->pov_y))
	{
		if (d->raycast->pov_x > 0)
			*x += 1;
		else if (d->raycast->pov_x < 0)
			*x -= 1;
	}
	else
	{
		if (d->raycast->pov_y > 0)
			*y += 1;
		else if (d->raycast->pov_y < 0)
			*y -= 1;
	}
}

void	open_close_door_b(t_data *d)
{
	int		direction_x;
	int		direction_y;
	double	distance;

	set_door_directions_b(d, &direction_x, &direction_y);
	distance = hypot(d->raycast->pos_x - direction_x, \
	d->raycast->pos_y - direction_y);
	distance -= (int)distance;
	if (d->map->grid[direction_y][direction_x] == 'D')
		d->map->grid[direction_y][direction_x] = 'd';
	else if (distance < 0.3)
		return ;
	else if (d->map->grid[direction_y][direction_x] == 'd')
		d->map->grid[direction_y][direction_x] = 'D';
}
