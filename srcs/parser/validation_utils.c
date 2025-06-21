/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:20:06 by lbarreto          #+#    #+#             */
/*   Updated: 2025/06/21 20:15:56 by lbarreto         ###   ########.fr       */
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