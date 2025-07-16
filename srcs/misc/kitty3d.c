/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kitty3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:51:32 by lbarreto          #+#    #+#             */
/*   Updated: 2025/07/15 15:48:40 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

int	main(int argc, char **argv)
{
	char    *map_name;
    char    *map_file;
    t_map   *map;
    int     i;

    i = 0;
    if (argc != 2)
        my_printf_fd(2, "\033[35mKitty3d 😺: Error: \033[1;31m \
Wrong number of arguments ❌\033[0\n");
    else
    {
        map_name = argv[1];
        map_file = open_map(map_name);
        map = parse_map(map_file);
        my_printf("floor config: %d\n", map->floor_color);
        my_printf("ceiling config: %d\n", map->ceiling_color);
        my_printf("north texture: %s\n", map->north_texture);
        my_printf("south texture: %s\n", map->south_texture);
        my_printf("east texture: %s\n", map->east_texture);
        my_printf("west texture: %s\n", map->west_texture);
        my_printf("grid x size: %d\n", map->grid_x_size);
		my_printf("grid y size: %d\n", map->grid_y_size);
        my_printf("player x: %d\n", map->player_x);
        my_printf("player y: %d\n", map->player_y);
        my_printf("map:\n");
        while (map->grid[i])
        {
            my_printf("%s\n", map->grid[i]);
            i++;
        }
        free_map(map);
    }
}