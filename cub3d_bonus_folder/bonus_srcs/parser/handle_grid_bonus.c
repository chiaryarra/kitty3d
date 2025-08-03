/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_grid_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:24:13 by lbarreto          #+#    #+#             */
/*   Updated: 2025/08/02 21:59:19 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d_bonus.h"

int	direction_setter_b(char c)
{
	if (c == 'N')
		return (NORTH);
	if (c == 'S')
		return (SOUTH);
	if (c == 'E')
		return (EAST);
	if (c == 'W')
		return (WEST);
	return (0);
}

static void	verify_grid_characters_b(t_map *map, char *map_file, int *i)
{
	int	recent_newline;

	recent_newline = FALSE;
	while (map_file[(*i)])
	{
		if (map_file[*i] == ' ')
			map_file[*i] = 'x';
		else if (is_map_direction_b(map_file[*i]) == TRUE)
		{
			if (map->start_direction != 0)
				map_error_b(REPEATED_STARTING_DIRECTION, map);
			else
				map->start_direction = direction_setter_b(map_file[*i]);
			recent_newline = FALSE;
		}
		else if (ft_strchr("10Dd", map_file[*i]))
			recent_newline = FALSE;
		else if (map_file[*i] == '\n' && recent_newline == TRUE)
			map_error_b(MAP_EMPTY_LINE, map);
		else if (map_file[*i] == '\n' && recent_newline == FALSE)
			recent_newline = TRUE;
		else
			map_error_b(INVALID_MAP_CONTENT, map);
		(*i)++;
	}
}

static char	*re_gen_grid_line_b(char *grid_line, int grid_lenght)
{
	char	*new_line;
	int		i;

	i = -1;
	new_line = (char *)malloc((grid_lenght + 3) * sizeof(char));
	if (!new_line)
		return (NULL);
	new_line[0] = 'x';
	while (grid_line[++i])
	{
		new_line[i + 1] = grid_line[i];
		if (grid_line[i] == 'x')
			grid_line[i] = ' ';
	}
	while (++i < grid_lenght + 2)
		new_line[i] = 'x';
	new_line[i] = '\0';
	return (new_line);
}

static void	verify_and_clear_grid_b(t_map *map)
{
	char	**new_grid;
	int		i;

	i = 0;
	new_grid = (char **)malloc((map->grid_y_size + 3) * sizeof(char *));
	new_grid[0] = fill_line_b(map->grid_x_size + 2);
	while (map->grid[i])
	{
		new_grid[i + 1] = re_gen_grid_line_b(map->grid[i], map->grid_x_size);
		if ((int)ft_strlen(map->grid[i]) < map->grid_x_size)
			map->grid[i] = recreate_grid_line_b(map->grid[i], map->grid_x_size);
		i++;
	}
	new_grid[i + 1] = fill_line_b(map->grid_x_size + 2);
	new_grid[i + 2] = NULL;
	verify_grid_b(map, new_grid);
	i = 0;
	while (new_grid[i])
	{
		free(new_grid[i]);
		i++;
	}
	free(new_grid);
}

void	set_map_grid_b(t_map *map, char *map_file, int *i)
{
	int		temp_i;
	int		j;

	j = -1;
	temp_i = 0;
	map->map_string = clear_lines_b(map_file, i);
	*i += ft_strlen(map_file + *i);
	verify_grid_characters_b(map, map->map_string, &temp_i);
	if (map->start_direction == FALSE)
		map_error_b(MISSING_START_DIRECTION, map);
	map->grid = ft_split(map->map_string, '\n');
	map->grid_x_size = get_grid_x_size_b(map->grid);
	map->grid_y_size = get_grid_y_size_b(map->map_string);
	verify_and_clear_grid_b(map);
	while (map->grid[++j])
		map->grid[j] = ft_strendtrim(map->grid[j], " \t\v\b");
	map->grid_x_size = get_grid_x_size_b(map->grid);
	map->player_x = get_player_x_b(map);
	map->player_y = get_player_y_b(map);
}
