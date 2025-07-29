/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kitty3d_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:51:32 by lbarreto          #+#    #+#             */
/*   Updated: 2025/07/29 13:32:55 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d_bonus.h"

int	main(int argc, char **argv)
{
	char	*map_file;
	t_data	*data;
	t_map	*map;

	if (argc != 2)
		my_printf_fd(2, "\033[35mKitty3d 😺: Error: \033[1;31m \
Wrong number of arguments ❌\033[0\n");
	else
	{
		map_file = open_map_b(argv[1]);
		map = parse_map_b(map_file);
		data = (t_data *)ft_calloc(sizeof(t_data) , 1);
		data->map = map;
		data->raycast = create_starting_position_b(data);
		init_engine_b(data);
		free_map_b(data->map);
	}
}
