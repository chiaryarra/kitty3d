/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 20:00:19 by lbarreto          #+#    #+#             */
/*   Updated: 2025/07/25 16:46:25 by lbarreto         ###   ########.fr       */
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
The map file has an invalid element for configurations ❌\033[0\n");
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
	if (error_type == MISSING_CONFIGS)
		my_printf_fd(2, "\033[35mKitty3d 😺: Error: \033[1;31m\
The map file is missing some informations ❌\033[0\n");
	exit(1);
}

void	texture_error(int error_type, t_map *map, int texture_type)
{
	char	*texture_text;

	texture_text = generate_texture_text(texture_type);
	if (error_type == INVALID_TEXTURE_CONFIG)
		my_printf_fd(2, "\033[35mKitty3d 😺: Error: \033[1;31m\
The path to %s configuration is invalid ❌\033[0\n", texture_text);
	if (error_type == REPEATED_TEXTURE_CONFIG)
		my_printf_fd(2, "\033[35mKitty3d 😺: Error: \033[1;31m\
You must not repeat the %s configuration ❌\033[0\n", texture_text);
	free_map(map);
	free(texture_text);
	exit(1);
}

void	map_error(int error_type, t_map *map)
{
	if (error_type == INVALID_MAP_CONTENT)
		my_printf_fd(2, "\033[35mKitty3d 😺: Error: \033[1;31m\
The map cant contain anything different from 1, 0, N, S, E or W ❌\033[0\n");
	if (error_type == MAP_EMPTY_LINE)
		my_printf_fd(2, "\033[35mKitty3d 😺: Error: \033[1;31m\
The map can't have empty lines ❌\033[0\n");
	if (error_type == REPEATED_STARTING_DIRECTION)
		my_printf_fd(2, "\033[35mKitty3d 😺: Error: \033[1;31m\
The map cant have more than one starting direction (N, S, E, W) ❌\033[0\n");
	if (error_type == MISSING_START_DIRECTION)
		my_printf_fd(2, "\033[35mKitty3d 😺: Error: \033[1;31m\
The map need to have one starting direction (N, S, E, W) ❌\033[0\n");
	if (error_type == GRID_ERROR)
		my_printf_fd(2, "\033[35mKitty3d 😺: Error: \033[1;31m\
The map grid is not closed by walls or has a space inside of it ❌\033[0\n");
	free_map(map);
	exit(1);
}

void	general_errors(int error_type, t_data *data)
{
	if (error_type == MALLOC_ERROR)
		my_printf_fd(2, "\033[35mKitty3d 😺: Error: \033[1;31m\
malloc failed to execute ❌\033[0\n");
	if (error_type == MLX_INIT_ERROR)
		my_printf_fd(2, "\033[35mKitty3d 😺: Error: \033[1;31m\
mlx_init failed to execute ❌\033[0\n");
	if (error_type == MLX_WINDOW_ERROR)
		my_printf_fd(2, "\033[35mKitty3d 😺: Error: \033[1;31m\
mlx_new_window failed to execute ❌\033[0\n");
	if (error_type == MLX_IMAGE_ERROR)
		my_printf_fd(2, "\033[35mKitty3d 😺: Error: \033[1;31m\
mlx_new_image failed to execute ❌\033[0\n");
	free_all(data);
	exit(1);
}
