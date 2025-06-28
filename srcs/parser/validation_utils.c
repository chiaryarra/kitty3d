/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:20:06 by lbarreto          #+#    #+#             */
/*   Updated: 2025/06/28 15:50:11 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

int	map_name_validation(char *map_name)
{
	int	i;

	if (!map_name)
		return (FALSE);
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

int	verify_coord(char *cords, int *i)
{
	while(cords[*i] && cords[*i] == ' ')
		(*i)++;
	if (hexmap_atoi(cords, i) == -1)
		return (-1);
	while(cords[*i] && cords[*i] == ' ')
		(*i)++;
	if (cords[*i] != ',')
		return (-1);
	(*i)++;
	return (0);
}

int	validate_colorcoords(char *cords)
{
	int	i;

	if (verify_coord(cords, &i) == -1)
		return (-1);
	if (verify_coord(cords, &i) == -1)
		return (-1);
	while(cords[i] && cords[i] == ' ')
		i++;
	if (hexmap_atoi(cords, &i) == -1)
		return (-1);
	while(cords[i] && cords[i] == ' ')
		i++;
	if (cords[i])
		return (-1);
	return (0);
}
