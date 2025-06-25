/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:45:12 by lbarreto          #+#    #+#             */
/*   Updated: 2025/06/24 22:31:53 by lbarreto         ###   ########.fr       */
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
	while (map_file[(*i) + j] == ',' || map_file[(*i) + j] 
	|| ft_isdigit(map_file[(*i) + j]) == 1)
		j++;
	floor_hexcode = ft_substr(map_file + *i, 0, j);
	*i += j;
	map->floor_color = floor_hexcode;	
}