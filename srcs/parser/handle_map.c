/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:12:46 by lbarreto          #+#    #+#             */
/*   Updated: 2025/06/21 20:11:22 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

char	*open_map(char *map_name)
{
	int	fd;
	
	if (map_name_validation(map_name) == 0)
		handle_error(WRONG_NAME);

	return (NULL);
}