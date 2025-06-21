/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kitty3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:51:32 by lbarreto          #+#    #+#             */
/*   Updated: 2025/06/21 20:28:47 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

int	main(int argc, char **argv)
{
	char    *map_name;

    if (argc != 2)
        my_printf_fd(2, "\033[35mKitty3d 😺:\033[1;31m \
Wrong number of arguments ❌\033[0\n");
    else
    {
        map_name = argv[1];
        open_map(map_name);
    }
}