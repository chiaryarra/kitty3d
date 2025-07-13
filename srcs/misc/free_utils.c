/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 19:29:17 by lbarreto          #+#    #+#             */
/*   Updated: 2025/07/12 20:43:40 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

void	free_map(t_map *map)
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

static void	free_textures(t_mlx *mlx)
{
	int	i;
	
	i = 0;
	while (&mlx->img[i])
	{
		if ((&mlx->img[i])->addr)
			free((&mlx->img[i])->addr);
		mlx_destroy_image(mlx->mlx, (&mlx->img[i])->img);
		i++;
	}
	free(mlx->img);
}

void	free_mlx(t_mlx *mlx)
{
	free_textures(mlx);
	mlx_loop_end(mlx);
	mlx_destroy_window(mlx, mlx->window);
	mlx_destroy_display(mlx);
	free(mlx);
}

void	free_all(t_data *data)
{
	if (data->raycast != NULL)
		free(data->raycast);
	if (data->mlx != NULL)
		free_mlx(data->mlx);
	if (data->map != NULL)
		free_map(data->map);
	free(data);
}