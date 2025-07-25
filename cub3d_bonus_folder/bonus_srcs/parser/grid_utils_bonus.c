/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:56:46 by lbarreto          #+#    #+#             */
/*   Updated: 2025/07/25 16:46:09 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

char	*clear_lines(char *map_file, int *i)
{
	char	*cleared_file;
	int		space_count;

	space_count = 0;
	while (map_file[*i])
	{
		if (map_file[*i] == '\n')
			space_count = 0;
		else if (ft_isspace(map_file[*i]) == TRUE)
			space_count++;
		else
		{
			*i -= space_count;
			break ;
		}
		*i = *i + 1;
	}
	cleared_file = ft_strdup(map_file + *i);
	return (cleared_file);
}

char	*recreate_grid_line(char *grid_line, int grid_x_size)
{
	char	*new_line;
	int		i;

	i = -1;
	new_line = (char *)malloc((grid_x_size + 1) * sizeof(char));
	while (grid_line[++i])
		new_line[i] = grid_line[i];
	while (i < grid_x_size)
	{
		new_line[i] = 'x';
		i++;
	}
	new_line[grid_x_size] = '\0';
	free(grid_line);
	return (new_line);
}
