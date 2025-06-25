/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kitty3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:51:32 by lbarreto          #+#    #+#             */
/*   Updated: 2025/06/24 22:26:24 by lbarreto         ###   ########.fr       */
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
        my_printf("floor config: %s\n", map->floor_color);
        free_map(map);
    }
}