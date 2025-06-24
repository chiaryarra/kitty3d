/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kitty3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:36:07 by lbarreto          #+#    #+#             */
/*   Updated: 2025/06/24 20:01:32 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KITTY3D_H
# define KITTY3D_H

# include "libft/libft.h"
# include <fcntl.h>

# define TRUE 1
# define FALSE 0

enum	e_errors {
	WRONG_FILENAME,
	OPEN_ERROR,
	EMPTY_FILE,
	INVALID_CONFIG,
	INDENTED_CONFIG
};

enum	e_configs {
	FLOOR = 1,
	CEILING,
	NORTH,
	SOUTH,
	EAST,
	WEST
};

typedef struct	s_map {
	char	*map;
	char	**grid;
	int		x_size;
	int		y_size;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color;
	int		ceiling_color;
}	t_map;

// Map reading 

char	*open_map(char *map_name);
char	*read_map(int fd);
t_map	*parse_map(char	*map_file);
void	set_map(t_map *map, char *map_file, int *i);

// Validations

int		map_name_validation(char *map_name);

// Error Utils

void	read_error(int error_type);
void	parse_error(int error_type, t_map *map);
void	free_map(t_map *map);

// Utils

int		is_kitty3dconfig(char *c, int *i);
int		config_len(int config_value);

#endif