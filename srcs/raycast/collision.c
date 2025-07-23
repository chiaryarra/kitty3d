/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:31:59 by yathayde          #+#    #+#             */
/*   Updated: 2025/07/22 21:20:44 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

int	can_move_front_back(t_data *d, double x, double y, double move_vector)
{
	int		mx;
	int		my;
	double	check_x;
	double	check_y;

	mx = (int)x;
	my = (int)y;
	check_x = x + COLLISION_RAY * move_vector * d->raycast->pov_x;
	check_y = y + COLLISION_RAY * move_vector * d->raycast->pov_y;
	if (mx < 0)
		return (0);
	if (mx >= d->map->grid_x_size)
		return (0);
	if (my < 0)
		return (0);
	if (my >= d->map->grid_y_size)
		return (0);
	if (d->map->grid[(int)check_y][(int)check_x] == '1')
		return (0);
	return (1);
}

int	can_move_side(t_data *d, double x, double y, double move_vector)
{	
	int		mx;
	int		my;
	double	check_x;
	double	check_y;

	mx = (int)x;
	my = (int)y;
	check_x = x + COLLISION_RAY * move_vector * d->raycast->plane_x;
	check_y = y + COLLISION_RAY * move_vector * d->raycast->plane_y;
	if (mx < 0)
		return (0);
	if (mx >= d->map->grid_x_size)
		return (0);
	if (my < 0)
		return (0);
	if (my >= d->map->grid_y_size)
		return (0);
	if (d->map->grid[(int)check_y][(int)check_x] == '1')
		return (0);
	return (1);
}
