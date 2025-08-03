/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_movement_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:55:52 by lbarreto          #+#    #+#             */
/*   Updated: 2025/07/29 13:47:00 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d_bonus.h"

int	mouse_move_handler_b(int x, int y, t_data *d)
{
	static int	prev_x = -1;
	double		rot_speed;
	double		old_pov_x;
	double		old_plane_x;

	(void)y;
	if (prev_x == -1)
		prev_x = x;
	rot_speed = (x - prev_x) * MOUSE_SENSIBILITY;
	if (rot_speed != 0)
	{
		old_pov_x = d->raycast->pov_x;
		d->raycast->pov_x = d->raycast->pov_x * cos(rot_speed) \
		- d->raycast->pov_y * sin(rot_speed);
		d->raycast->pov_y = old_pov_x * sin(rot_speed) \
		+ d->raycast->pov_y * cos(rot_speed);
		old_plane_x = d->raycast->plane_x;
		d->raycast->plane_x = d->raycast->plane_x * cos(rot_speed) \
		- d->raycast->plane_y * sin(rot_speed);
		d->raycast->plane_y = old_plane_x * sin(rot_speed) \
		+ d->raycast->plane_y * cos(rot_speed);
	}
	prev_x = x;
	return (0);
}
