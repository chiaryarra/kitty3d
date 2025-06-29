/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 20:00:19 by lbarreto          #+#    #+#             */
/*   Updated: 2025/06/29 18:53:54 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

void	read_error(int error_type)
{
	if (error_type == WRONG_FILENAME)
		my_printf_fd(2, "\033[35mKitty3d 😺: Error: \033[1;31m\
Wrong type of file ❌\033[0\n");
	if (error_type == OPEN_ERROR)
		my_printf_fd(2, "\033[35mKitty3d 😺: Error: \033[1;31m\
Cannot open the map file ❌\033[0\n");
	if (error_type == EMPTY_FILE)
		my_printf_fd(2, "\033[35mKitty3d 😺: Error: \033[1;31m\
The map file is empty ❌\033[0\n");
	exit(1);
}

void	parse_error(int error_type, t_map *map)
{
	free_map(map);
	if (error_type == INVALID_CONFIG)
		my_printf_fd(2, "\033[35mKitty3d 😺: Error: \033[1;31m\
The map file has a invalid element for configurations ❌\033[0\n");
	if (error_type == INDENTED_CONFIG)
		my_printf_fd(2, "\033[35mKitty3d 😺: Error: \033[1;31m\
The configs on map file must be on the start of the line ❌\033[0\n");
	if (error_type == INVALID_FLOOR_COORDS)
		my_printf_fd(2, "\033[35mKitty3d 😺: Error: \033[1;31m\
The color coordinates of the floor color(F) is invalid ❌\033[0\n");
	if (error_type == INVALID_CEIL_COORDS)
		my_printf_fd(2, "\033[35mKitty3d 😺: Error: \033[1;31m\
The color coordinates of the ceiling color(C) is invalid ❌\033[0\n");
	if (error_type == REPEATED_FLOOR_CONFIG)
		my_printf_fd(2, "\033[35mKitty3d 😺: Error: \033[1;31m\
You must not repeat the floor color(F) configuration ❌\033[0\n");
	if (error_type == REPEATED_CEIL_CONFIG)
		my_printf_fd(2, "\033[35mKitty3d 😺: Error: \033[1;31m\
You must not repeat the ceiling color(C) configuration ❌\033[0\n");	
	exit(1);
}

void	texture_error(int error_type, t_map *map, int texture_type)
{
	char *texture_text;

	texture_text = generate_texture_text(texture_type);
	free_map(map);
	if (error_type == INVALID_TEXTURE_CONFIG)
		my_printf_fd(2, "\033[35mKitty3d 😺: Error: \033[1;31m\
The path to %s configuration is invalid ❌\033[0\n", texture_text);	
	if (error_type == REPEATED_TEXTURE_CONFIG)
		my_printf_fd(2, "\033[35mKitty3d 😺: Error: \033[1;31m\
You must not repeat the %s configuration ❌\033[0\n", texture_text);	

	exit(1);
}

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
	if (map->x_size != 0 && map->y_size != 0)
	{
		while (++i < map->y_size)
			free(map->grid[i]);
		free(map->grid);
	}
	free(map);
}
