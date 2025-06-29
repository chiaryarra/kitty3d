/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:45:12 by lbarreto          #+#    #+#             */
/*   Updated: 2025/06/29 18:30:44 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

void	set_floor(t_map *map, char *map_file, int *i)
{
	char	*floor_rgbcode;
	int		j;

	j = 0;
	if (map->floor_color_is_set == TRUE)
		parse_error(REPEATED_FLOOR_CONFIG, map);
	while (map_file[*i] == ' ')
		(*i)++;
	while (map_file[*i + j] != '\n')
		j++;
	floor_rgbcode = ft_substr(map_file + *i, 0, j);
	*i += j;
	if (validate_colorcoords(floor_rgbcode) == -1)
	{
		free(floor_rgbcode);
		parse_error(INVALID_FLOOR_COORDS, map);
	}
	map->floor_color = rgb_to_int(floor_rgbcode);
	map->floor_color_is_set = TRUE;
	free(floor_rgbcode);
}

void	set_ceiling(t_map *map,char *map_file, int *i)
{
	char	*ceiling_rgbcode;
	int		j;

	j = 0;
	if (map->ceiling_color_is_set == TRUE)
		parse_error(REPEATED_CEIL_CONFIG, map);
	while (map_file[*i] == ' ')
		(*i)++;
	while (map_file[*i + j] != '\n')
		j++;
	ceiling_rgbcode = ft_substr(map_file + *i, 0, j);
	*i += j;
	if (validate_colorcoords(ceiling_rgbcode) == -1)
	{
		free(ceiling_rgbcode);
		parse_error(INVALID_CEIL_COORDS, map);
	}
	map->ceiling_color = rgb_to_int(ceiling_rgbcode);
	map->ceiling_color_is_set = TRUE;
	free(ceiling_rgbcode);
}
