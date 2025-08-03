/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 19:29:17 by lbarreto          #+#    #+#             */
/*   Updated: 2025/08/02 17:02:30 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d_bonus.h"

void	free_map_b(t_map *map)
{
	int	i;

	i = -1;
	free(map->map);
	if (map->north_texture)
		free(map->north_texture);
	if (map->south_texture)
		free(map->south_texture);
	if (map->east_texture)
		free(map->east_texture);
	if (map->west_texture)
		free(map->west_texture);
	if (map->door_texture)
		free(map->door_texture);
	if (map->map_string)
		free(map->map_string);
	if (map->grid_x_size != 0 && map->grid_y_size != 0)
	{
		while (map->grid[++i])
			free(map->grid[i]);
		free(map->grid);
	}
	free(map);
}

static void	free_textures_b(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (mlx->textures[i].img)
			mlx_destroy_image(mlx->mlx, (&mlx->textures[i])->img);
		i++;
	}
	free(mlx->textures);
}

static void	free_nyancat_b(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if (mlx->nyan_cat[i].img)
			mlx_destroy_image(mlx->mlx, (&mlx->nyan_cat[i])->img);
		i++;
	}
	free(mlx->nyan_cat);
}

void	free_mlx_b(t_mlx *mlx, t_data *d)
{
	free_nyancat_b(mlx);
	if (d->map->easter_egg_on == FALSE)
		free_textures_b(mlx);
	else
	{
		mlx_destroy_image(mlx->mlx, (&mlx->textures[4])->img);
		free(mlx->textures);
	}
	if (mlx->main_img.img && mlx->mlx)
		mlx_destroy_image(mlx->mlx, mlx->main_img.img);
	if (mlx->minimap.img && mlx->mlx)
		mlx_destroy_image(mlx->mlx, mlx->minimap.img);
	if (mlx->window && mlx->mlx)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->mlx)
	{
		mlx_loop_end(mlx->mlx);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		mlx->mlx = NULL;
	}
	free(mlx);
}

void	free_all_b(t_data *data)
{
	if (data->raycast != NULL)
		free(data->raycast);
	if (data->mlx != NULL)
		free_mlx_b(data->mlx, data);
	if (data->map != NULL)
		free_map_b(data->map);
	free(data);
}
