/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:00:48 by yathayde          #+#    #+#             */
/*   Updated: 2025/07/27 21:15:45 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d_bonus.h"

static int	render_loop(void *param)
{
	render_frame((t_data *)param);
	return (0);
}

static void	import_texture(char *file_path, t_data *data, t_img *texture)
{
	texture->img = mlx_xpm_file_to_image(data->mlx->mlx, file_path, \
	&texture->width, &texture->height);
	if (texture->img)
		texture->addr = mlx_get_data_addr(texture->img, &texture->bpp, \
		&texture->line, &texture->endian);
}

t_img	*init_textures(t_data *data)
{
	t_img	*texts;

	texts = (t_img *)ft_calloc(sizeof(t_img), 5);
	if (!texts)
		general_errors(MALLOC_ERROR, data);
	import_texture(data->map->north_texture, data, &texts[0]);
	import_texture(data->map->east_texture, data, &texts[1]);
	import_texture(data->map->south_texture, data, &texts[2]);
	import_texture(data->map->west_texture, data, &texts[3]);
	return (texts);
}

void	validate_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!data->mlx->textures[i].img)
			general_errors(MLX_IMAGE_ERROR, data);
		i++;
	}
}

void	init_engine(t_data *data)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ft_calloc(sizeof(t_mlx), 1);
	if (!mlx)
		general_errors(MALLOC_ERROR, data);
	data->mlx = mlx;
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		general_errors(MLX_INIT_ERROR, data);
	mlx->textures = init_textures(data);
	validate_textures(data);
	mlx_get_screen_size(mlx->mlx, &mlx->s_width, &mlx->s_height);
	mlx->window = mlx_new_window(mlx->mlx, mlx->s_width, \
	mlx->s_height, "Kitty3D");
	mlx->main_img.img = mlx_new_image(mlx->mlx, mlx->s_width, mlx->s_height);
	if (!mlx->window)
		general_errors(MLX_WINDOW_ERROR, data);
	mlx->main_img.addr = mlx_get_data_addr(mlx->main_img.img, \
	&mlx->main_img.bpp, &mlx->main_img.line, &mlx->main_img.endian);
	init_bonuses(data);
	mlx_loop_hook(mlx->mlx, render_loop, data);
	mlx_hook(mlx->window, 2, 1L << 0, key_press, data);
	mlx_hook(mlx->window, 6, 1L << 6, mouse_move_handler, data);
	mlx_hook(mlx->window, 17, 0, close_window, data);
	mlx_loop(mlx->mlx);
}
