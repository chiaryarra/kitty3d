/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:00:58 by yathayde          #+#    #+#             */
/*   Updated: 2025/08/01 14:21:24 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d_bonus.h"

static void	move_front_back_b(t_data *data, int direction)
{
	if (direction == W)
		data->raycast->move_vect = 1.0;
	else
		data->raycast->move_vect = -1.0;
	data->raycast->temp_x = data->raycast->pos_x + \
	data->raycast->move_vect * data->raycast->pov_x * MOVE_STEP;
	data->raycast->temp_y = data->raycast->pos_y;
	if (can_move_front_back_b(data, data->raycast->temp_x, \
	data->raycast->temp_y, data->raycast->move_vect))
		data->raycast->pos_x = data->raycast->temp_x;
	data->raycast->temp_x = data->raycast->pos_x;
	data->raycast->temp_y = data->raycast->pos_y + \
	data->raycast->move_vect * data->raycast->pov_y * MOVE_STEP;
	if (can_move_front_back_b(data, data->raycast->temp_x, \
	data->raycast->temp_y, data->raycast->move_vect))
		data->raycast->pos_y = data->raycast->temp_y;
}

static void	move_sides_b(t_data *data, int direction)
{
	if (direction == D)
		data->raycast->move_vect = 1.0;
	else
		data->raycast->move_vect = -1.0;
	data->raycast->temp_x = data->raycast->pos_x + \
	data->raycast->move_vect * data->raycast->plane_x * MOVE_STEP;
	if (can_move_side_b(data, data->raycast->temp_x, \
	data->raycast->pos_y, data->raycast->move_vect))
		data->raycast->pos_x = data->raycast->temp_x;
	data->raycast->temp_y = data->raycast->pos_y + \
	data->raycast->move_vect * data->raycast->plane_y * MOVE_STEP;
	if (can_move_side_b(data, data->raycast->pos_x, \
	data->raycast->temp_y, data->raycast->move_vect))
		data->raycast->pos_y = data->raycast->temp_y;
}

static void	rotate_pov_b(t_data *data, int direction)
{
	double	rotate_ang;
	double	old_pov_x;
	double	old_plane_x;

	if (direction == LEFT)
		rotate_ang = -ROT_ANGLE;
	else
		rotate_ang = ROT_ANGLE;
	old_pov_x = data->raycast->pov_x;
	old_plane_x = data->raycast->plane_x;
	data->raycast->pov_x = data->raycast->pov_x * cos(rotate_ang) \
	- data->raycast->pov_y * sin(rotate_ang);
	data->raycast->pov_y = old_pov_x * sin(rotate_ang) \
	+ data->raycast->pov_y * cos(rotate_ang);
	data->raycast->plane_x = data->raycast->plane_x * cos(rotate_ang) \
	- data->raycast->plane_y * sin(rotate_ang);
	data->raycast->plane_y = old_plane_x * sin(rotate_ang) \
	+ data->raycast->plane_y * cos(rotate_ang);
}

int	close_window_b(void *pointer)
{
	t_data	*data;

	data = (t_data *)pointer;
	free_map_b(data->map);
	free_mlx_b(data->mlx);
	free(data->raycast);
	free(data);
	exit(0);
}

int	key_press_b(int key, t_data *data)
{
	if (key == W || key == S)
		move_front_back_b(data, key);
	else if (key == A || key == D)
		move_sides_b(data, key);
	else if (key == LEFT || key == RIGHT)
		rotate_pov_b(data, key);
	else if (key == SPACE)
		open_close_door_b(data);
	else if (key == ESC)
		close_window_b(data);
	return (0);
}
