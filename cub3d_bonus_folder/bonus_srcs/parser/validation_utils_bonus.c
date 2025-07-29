/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:20:06 by lbarreto          #+#    #+#             */
/*   Updated: 2025/07/29 13:42:23 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d_bonus.h"

int	map_name_validation_b(char *map_name)
{
	int	i;

	i = 0;
	while (map_name[i])
		i++;
	if (i >= 4)
		i -= 4;
	else
		i = 0;
	if (ft_strncmp(map_name + i, ".cub", ft_strlen(map_name + i)) == 0)
		return (TRUE);
	return (FALSE);
}

int	verify_coord_b(char *cords, int *i)
{
	while (cords[*i] && cords[*i] == ' ')
		(*i)++;
	if (hexmap_atoi_b(cords, i) == -1)
		return (-1);
	while (cords[*i] && cords[*i] == ' ')
		(*i)++;
	if (cords[*i] != ',')
		return (-1);
	(*i)++;
	return (0);
}

int	verify_texture_b(t_map *map, int texture_type)
{
	if (texture_type == NORTH && map->north_texture != NULL)
		return (TRUE);
	if (texture_type == SOUTH && map->south_texture != NULL)
		return (TRUE);
	if (texture_type == EAST && map->east_texture != NULL)
		return (TRUE);
	if (texture_type == WEST && map->west_texture != NULL)
		return (TRUE);
	return (FALSE);
}

int	validate_colorcoords_b(char *cords)
{
	int	i;

	i = 0;
	if (verify_coord_b(cords, &i) == -1)
		return (-1);
	if (verify_coord_b(cords, &i) == -1)
		return (-1);
	while (cords[i] && cords[i] == ' ')
		i++;
	if (hexmap_atoi_b(cords, &i) == -1)
		return (-1);
	while (cords[i] && cords[i] == ' ')
		i++;
	if (cords[i])
		return (-1);
	return (0);
}

int	validate_texture_b(char *texture_name)
{
	int	i;

	i = 0;
	while (texture_name[i])
	{
		if (texture_name[i] == ' ')
			return (-1);
		i++;
	}
	if (open(texture_name, O_RDONLY) == -1)
		return (-1);
	return (0);
}
