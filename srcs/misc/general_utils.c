/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:10:27 by lbarreto          #+#    #+#             */
/*   Updated: 2025/06/29 18:47:26 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

int	is_kitty3dconfig(char *c, int *i)
{
	int	j;

	j = 0;
	while(c[*i] && ft_isspace(c[*i]) == 0)
	{
		(*i)++;
		j++;
	}
	if (ft_strncmp(c + *i - j, "NO", j) == 0)
		return (NORTH);
	if (ft_strncmp(c + *i - j, "SO", j) == 0)
		return (SOUTH);
	if (ft_strncmp(c + *i - j, "WE", j) == 0)
		return (WEST);
	if (ft_strncmp(c + *i - j, "EA", j) == 0)
		return (EAST);
	if (ft_strncmp(c + *i - j, "C", j) == 0)
		return (CEILING);
	if (ft_strncmp(c + *i - j, "F", j) == 0)
		return (FLOOR);
	return (0);
}

int	config_len(int config_value)
{
	if (config_value == FLOOR || config_value == CEILING)
		return (1);
	else if (config_value == NORTH || config_value == SOUTH \
	|| config_value == EAST || config_value == WEST)
		return (2);
	else
		return (0);
}

int	hexmap_atoi(char *str, int *i)
{
	int	not_a_number;
	int	n;

	n = 0;
	not_a_number = TRUE;
	while (ft_isdigit(str[*i]) == 1)
	{
		n = n * 10 + (str[*i] - '0');
		(*i)++;
		not_a_number = FALSE;
	}
	if (not_a_number == TRUE || (n > 255))
		return (-1);
	return (n);
}
char	*generate_texture_text(int texture_type)
{
	if (texture_type == NORTH)
		return (ft_strdup("north texture(NO)"));
	if (texture_type == SOUTH)
		return (ft_strdup("south texture(SO)"));
	if (texture_type == EAST)
		return (ft_strdup("east texture(EA)"));
	if (texture_type == WEST)
		return (ft_strdup("west texture(WE)"));
	return (ft_strdup("invalid texture"));
}
