/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easter_egg_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 15:49:15 by lbarreto          #+#    #+#             */
/*   Updated: 2025/08/02 20:48:46 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d_bonus.h"

void	easter_egg_key_press(int key, t_data *d)
{
	if (key == C)
	{
		if (d->map->easter_egg_count == 0 || d->map->easter_egg_count == 3)
			d->map->easter_egg_count++;
		else
			d->map->easter_egg_count = 0;
	}
	if (key == H)
	{
		if (d->map->easter_egg_count == 1 || d->map->easter_egg_count == 4)
			d->map->easter_egg_count++;
		else
			d->map->easter_egg_count = 0;
	}
	if (key == I)
	{
		if (d->map->easter_egg_count == 2)
			d->map->easter_egg_count++;
		else if (d->map->easter_egg_count == 5)
			d->map->easter_egg_on = TRUE;
		else
			d->map->easter_egg_count = 0;
	}
}
