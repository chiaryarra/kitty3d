/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_grid_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:20:58 by lbarreto          #+#    #+#             */
/*   Updated: 2025/06/30 17:00:26 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

int	get_grid_x_size(char **grid)
{
	int	i;
	int	bigger_line;

	if (grid == NULL)
		return (0);
	i = 0;
	bigger_line = 0;
	while (grid[i])
	{
		if (ft_strlen(grid[i]) > bigger_line)
			bigger_line = ft_strlen(grid[i]);
		i++;
	}
	return (bigger_line);
}

int	get_grid_y_size(char *map_string)
{
	int	i;
	int	lines_count;

	if (map_string == NULL)
		return (0);
	i = 0;
	lines_count = 1;
	while (map_string[i])
	{
		if (map_string[i] == '\n')
			lines_count++;
		i++;
	}
	return (lines_count);
}