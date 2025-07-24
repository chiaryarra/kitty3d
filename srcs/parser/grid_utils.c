/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:56:46 by lbarreto          #+#    #+#             */
/*   Updated: 2025/07/24 13:19:07 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

char	*clear_lines(char *map_file, int i)
{
	char	*temp_file;
	char	**temp_grid;
	int		j;
	char	*cleared_file;

	j = -1;
	temp_file = ft_strdup(map_file + i);
	temp_grid = ft_split(temp_file, '\n');
	while (temp_grid[++j])
		temp_grid[j] = ft_strendtrim(temp_grid[j], " ");
	free(temp_file);
	temp_file = ft_unsplit(temp_grid, '\n');
	cleared_file = ft_strtrim(temp_file, "\n");
	j = -1;
	while (temp_grid[++j])
		free(temp_grid[j]);
	free(temp_grid);
	free(temp_file);
	return (cleared_file);
}
