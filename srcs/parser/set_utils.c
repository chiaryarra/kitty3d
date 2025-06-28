/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:45:12 by lbarreto          #+#    #+#             */
/*   Updated: 2025/06/28 15:49:54 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

void	set_floor(t_map *map, char *map_file, int *i)
{
	char	*floor_hexcode;
	int		j;

	j = 0;
	while (map_file[*i] == ' ')
		(*i)++;
	while (map_file[*i + j] != '\n')
		j++;
	floor_hexcode = ft_substr(map_file + *i, 0, j);
	*i += j;
	if (validate_colorcoords(floor_hexcode) == -1)
	{
		free(floor_hexcode);
		parse_error(INVALID_FLOOR_COORDS, map);
	}
	map->floor_color = floor_hexcode;	
}
