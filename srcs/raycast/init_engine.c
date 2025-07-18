/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:00:48 by yathayde          #+#    #+#             */
/*   Updated: 2025/07/17 20:51:47 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

/* ——— Wrapper que casa a assinatura esperada pela mlx_loop_hook ——— */
static int  render_loop(void *param)
{
	render_frame((t_data *)param);
    return (0);
}

void	*import_texture(char *file_path, t_data *data)
{
	void	*img;
	int		img_w;
	int		img_h;

	img = mlx_xpm_file_to_image(data->mlx->mlx, file_path, &img_w, &img_h);
	if (!img)
		general_errors(MLX_IMAGE_ERROR, data);
	return (img);
}

t_img	*init_textures(t_data *data)
{
	t_img	*textures;

	textures = (t_img *)ft_calloc(sizeof(t_img), 4);
	if (!textures)
		general_errors(MALLOC_ERROR, data);
	textures[0].img = import_texture(data->map->north_texture, data);
	textures[0].addr = mlx_get_data_addr(&textures[0].img, &textures[0].bpp, \
	&textures[0].line, &textures[0].endian);
	textures[1].img = import_texture(data->map->east_texture, data);
	textures[1].addr = mlx_get_data_addr(&textures[1].img, &textures[1].bpp, \
	&textures[1].line, &textures[1].endian);
	textures[2].img = import_texture(data->map->south_texture, data);
	textures[2].addr = mlx_get_data_addr(&textures[2].img, &textures[2].bpp, \
	&textures[2].line, &textures[2].endian);
	textures[3].img = import_texture(data->map->west_texture, data);
	textures[3].addr = mlx_get_data_addr(&textures[3].img, &textures[3].bpp, \
	&textures[3].line, &textures[0].endian);
	return (textures);
}

void   init_engine(t_data *data)
{
    t_mlx   *mlx;

    mlx = (t_mlx *)malloc(sizeof(t_mlx) * 1);
    if (!mlx)
        general_errors(MALLOC_ERROR, data);
    data->mlx = mlx;
    mlx->mlx = mlx_init();
    if (!mlx->mlx)
        general_errors(MLX_INIT_ERROR, data);
    mlx->window = mlx_new_window(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Kitty3D");
	mlx->main_img.img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx->main_img.addr = mlx_get_data_addr(mlx->main_img.img, &mlx->main_img.bpp, \
	&mlx->main_img.line, &mlx->main_img.endian);
	//my_printf("main_img.addr: %s\n", mlx->main_img.addr);
    if (!mlx->window)
		general_errors(MLX_WINDOW_ERROR, data);
    // mlx->textures = init_textures(data);
    /* agora usa o wrapper, que retorna int e aceita void* */
    mlx_loop_hook(mlx->mlx, render_loop, data);
    mlx_hook(mlx->window, 2, 1L<<0, key_press, data);
    mlx_hook(mlx->window, 17, 0, close_window, data);
    mlx_loop(mlx->mlx);
}
