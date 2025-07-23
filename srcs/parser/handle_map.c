/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:12:46 by lbarreto          #+#    #+#             */
/*   Updated: 2025/07/22 21:05:27 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

char	*read_map(int fd)
{
	char	*temp_map;
	char	*return_map;
	char	*line;

	temp_map = get_next_line(fd);
	line = get_next_line(fd);
	while (line)
	{
		temp_map = ft_strjoinfree(temp_map, line);
		line = get_next_line(fd);
	}
	if (!temp_map)
		read_error(EMPTY_FILE);
	return_map = ft_strtrim(temp_map, "\n ");
	return_map = ft_strendtrim(return_map, " ");
	free(temp_map);
	return (return_map);
}

char	*open_map(char *map_name)
{
	int		fd;
	char	*map;

	if (map_name_validation(map_name) == 0)
		read_error(WRONG_FILENAME);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		read_error(OPEN_ERROR);
	map = read_map(fd);
	close(fd);
	return (map);
}

void	set_map_configs(t_map *map, char *map_file, int *i)
{
	int	config_value;

	config_value = is_kitty3dconfig(map_file, i);
	if ((*i - config_len(config_value) != 0) \
	&& config_value > 0 && map_file[*i - config_len(config_value) - 1] != '\n')
		parse_error(INDENTED_CONFIG, map);
	if (config_value == FLOOR)
		set_floor(map, map_file, i);
	else if (config_value == CEILING)
		set_ceiling(map, map_file, i);
	else if (config_value == NORTH)
		set_texture(map, map_file, i, config_value);
	else if (config_value == SOUTH)
		set_texture(map, map_file, i, config_value);
	else if (config_value == EAST)
		set_texture(map, map_file, i, config_value);
	else if (config_value == WEST)
		set_texture(map, map_file, i, config_value);
	else
		parse_error(INVALID_CONFIG, map);
}

t_map	*parse_map(char	*map_file)
{
	t_map	*map;
	int		i;

	i = 0;
	map = (t_map *)ft_calloc(sizeof(t_map), 1);
	map->map = map_file;
	while (map->map[i])
	{
		if (ft_isspace(map->map[i]) == TRUE)
			i++;
		else if (map->map_configs_set == FALSE)
			set_map_configs(map, map->map, &i);
		else
			set_map_grid(map, map->map, &i);
	}
	if (map->map_configs_set == FALSE || map->grid == NULL)
		parse_error(MISSING_CONFIGS, map);
	return (map);
}
