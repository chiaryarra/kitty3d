/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:45:12 by lbarreto          #+#    #+#             */
/*   Updated: 2025/07/29 13:52:43 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d_bonus.h"

static void	verify_if_all_configs_set_b(t_map *map)
{
	if (map->ceiling_color_is_set == TRUE && map->floor_color_is_set == TRUE \
	&& map->north_texture != NULL && map->south_texture != NULL \
	&& map->west_texture != NULL && map->east_texture != NULL)
		map->map_configs_set = TRUE;
}

void	set_floor_b(t_map *map, char *map_file, int *i)
{
	char	*floor_rgbcode;
	int		j;

	j = 0;
	if (map->floor_color_is_set == TRUE)
		parse_error_b(REPEATED_FLOOR_CONFIG, map);
	while (map_file[*i] == ' ')
		(*i)++;
	while (map_file[*i + j] != '\n')
		j++;
	floor_rgbcode = ft_substr(map_file + *i, 0, j);
	*i += j;
	if (validate_colorcoords_b(floor_rgbcode) == -1)
	{
		free(floor_rgbcode);
		parse_error_b(INVALID_FLOOR_COORDS, map);
	}
	map->floor_color = rgb_to_int_b(floor_rgbcode);
	map->floor_color_is_set = TRUE;
	free(floor_rgbcode);
	verify_if_all_configs_set_b(map);
}

void	set_ceiling_b(t_map *map, char *map_file, int *i)
{
	char	*ceiling_rgbcode;
	int		j;

	j = 0;
	if (map->ceiling_color_is_set == TRUE)
		parse_error_b(REPEATED_CEIL_CONFIG, map);
	while (map_file[*i] == ' ')
		(*i)++;
	while (map_file[*i + j] != '\n')
		j++;
	ceiling_rgbcode = ft_substr(map_file + *i, 0, j);
	*i += j;
	if (validate_colorcoords_b(ceiling_rgbcode) == -1)
	{
		free(ceiling_rgbcode);
		parse_error_b(INVALID_CEIL_COORDS, map);
	}
	map->ceiling_color = rgb_to_int_b(ceiling_rgbcode);
	map->ceiling_color_is_set = TRUE;
	free(ceiling_rgbcode);
	verify_if_all_configs_set_b(map);
}

static void	set_texture_address_b(t_map *map, char *texture_name, \
	int texture_type)
{
	if (texture_type == NORTH)
		map->north_texture = texture_name;
	if (texture_type == SOUTH)
		map->south_texture = texture_name;
	if (texture_type == EAST)
		map->east_texture = texture_name;
	if (texture_type == WEST)
		map->west_texture = texture_name;
}

void	set_texture_b(t_map *map, char *map_file, int *i, int texture_type)
{
	char	*texture_name;
	int		j;

	j = 0;
	if (verify_texture_b(map, texture_type) == TRUE)
		texture_error_b(REPEATED_TEXTURE_CONFIG, map, texture_type);
	while (map_file[*i] == ' ')
		(*i)++;
	while (map_file[*i + j] != '\n')
		j++;
	texture_name = ft_substr(map_file + *i, 0, j);
	*i += j;
	texture_name = ft_strendtrim(texture_name, " ");
	if (validate_texture_b(texture_name) == -1)
	{
		free(texture_name);
		texture_error_b(INVALID_TEXTURE_CONFIG, map, texture_type);
	}
	set_texture_address_b(map, texture_name, texture_type);
	verify_if_all_configs_set_b(map);
}
