/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kitty3d_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:51:32 by lbarreto          #+#    #+#             */
/*   Updated: 2025/07/25 16:46:09 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

int	main(int argc, char **argv)
{
	char	*map_file;
	t_data	*data;
	int		i;
	t_map	*map;

	i = 0;
	if (argc != 2)
		my_printf_fd(2, "\033[35mKitty3d 😺: Error: \033[1;31m \
Wrong number of arguments ❌\033[0\n");
	else
	{
		map_file = open_map(argv[1]);
		map = parse_map(map_file);
		data = (t_data *)malloc(sizeof(t_data) * 1);
		data->map = map;
		data->raycast = create_starting_position(data);
		init_engine(data);
		free_map(data->map);
	}
}
