/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:00:36 by yathayde          #+#    #+#             */
/*   Updated: 2025/07/26 15:37:54 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d_bonus.h"

void	render_frame(t_data *data)
{
	cast_rays(data);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->window, \
	data->mlx->main_img.img, 0, 0);
}
