/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kitty3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:51:32 by lbarreto          #+#    #+#             */
/*   Updated: 2025/06/29 18:30:26 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

int	main(int argc, char **argv)
{
	char    *map_name;
    char    *map_file;
    t_map   *map;

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
        free_map(map);
    }
}