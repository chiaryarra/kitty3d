/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:12:46 by lbarreto          #+#    #+#             */
/*   Updated: 2025/06/24 22:12:50 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

char	*read_map(int fd)
{
	char	*map;
	char	*line;
	int		i;

	i = 0;
	map = get_next_line(fd);
	line = get_next_line(fd);
	while (line)
	{
		map = ft_strjoinfree(map, line);
		line = get_next_line(fd);
	}
	if (!map)
		read_error(EMPTY_FILE);
	return (map);
}

// void	validate_map_file(char *map_file)
// {
// 	int	i;

// 	i = 0;
// 	if (is_kitty3dconfig(map_file, &i) == FALSE)
// 	{
// 		free(map_file);
// 		handle_error(INVALID_CONFIG);
// 	}
// 	while (map_file[i])
// 	{
// 		if (ft_isspace(map_file[i]) == TRUE)
// 			i++;
// 		else if (is_kitty3dconfig(map_file, &i) == FALSE)
// 		{
// 			free(map_file);
// 			handle_error(INVALID_CONFIG);
// 		}
// 		else if (map_file[i - 1] != '\n')
// 		{
// 			free(map_file);
// 			handle_error(INVALID_CONFIG);
// 		}
// 		else
// 			i++;
// 	}
// }

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

void	set_map(t_map *map, char *map_file, int *i)
{
	int	config_value;

	config_value = is_kitty3dconfig(map_file, i);
	if ((*i - config_len(config_value) != 0)
	&& config_value > 0 && map_file[*i - config_len(config_value) - 1] != '\n')
		parse_error(INDENTED_CONFIG, map);
	if (config_value == FLOOR)
	 	set_floor(map, map_file, i);
	// else if (config_value == CEILING)
	// 	set_ceiling(map, map_file, i);
	// else if (config_value == NORTH)
	// 	set_north(map, map_file, i);
	// else if (config_value == SOUTH)
	// 	set_south(map, map_file, i);
	// else if (config_value == EAST)
	// 	set_east(map, map_file, i);
	// else if (config_value == WEST)
	// 	set_west(map, map_file, i);
	else if (config_value == 0)
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
		else
			set_map(map, map->map, &i);
	}
	return (map);
}