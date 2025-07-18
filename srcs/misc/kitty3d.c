/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kitty3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:51:32 by lbarreto          #+#    #+#             */
/*   Updated: 2025/07/18 17:31:46 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

int	main(int argc, char **argv)
{
	char    *map_name;
    char    *map_file;
    t_data	*data;
    int     i;
	// //char	*grid[] = {
    // "111111100000",
    // "100000100000",
    // "101010100000",
    // "100N10100000",
    // "101010111111",
    // "100000000001",
    // "100000000001",  // ‘N’ = ponto de início
    // "111111111111",
    // NULL
	// };

    i = 0;
	//t_map *map;
	data = (t_data *)malloc(sizeof(t_data) * 1);
    if (argc != 2)
        my_printf_fd(2, "\033[35mKitty3d 😺: Error: \033[1;31m \
Wrong number of arguments ❌\033[0\n");
    else
    {
        map_name = argv[1];
        map_file = open_map(map_name);
    	data->map = parse_map(map_file);
		//data->raycast = create_starting_position(data);
		//data->map->grid = grid;
		//init_engine(data);
        // my_printf("floor config: %d\n", map->floor_color);
        // my_printf("ceiling config: %d\n", map->ceiling_color);
        // my_printf("north texture: %s\n", map->north_texture);
        // my_printf("south texture: %s\n", map->south_texture);
        // my_printf("east texture: %s\n", map->east_texture);
        // my_printf("west texture: %s\n", map->west_texture);
        // my_printf("grid x size: %d\n", map->grid_x_size);
		// my_printf("grid y size: %d\n", map->grid_y_size);
        my_printf("map:\n");
        while (data->map->grid[i])
        {
            my_printf("%s\n", data->map->grid[i]);
            i++;
        }
        free_map(data->map);
    }
}