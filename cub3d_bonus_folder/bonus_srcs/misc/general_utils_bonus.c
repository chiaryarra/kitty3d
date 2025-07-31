/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:10:27 by lbarreto          #+#    #+#             */
/*   Updated: 2025/07/31 15:50:18 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d_bonus.h"

int	is_kitty3dconfig_b(char *c, int *i)
{
	int	j;

	j = 0;
	while (c[*i] && ft_isspace(c[*i]) == 0)
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
	if (ft_strncmp(c + *i - j, "DO", j) == 0)
		return (DOOR);
	return (FALSE);
}

int	is_map_direction_b(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (TRUE);
	return (FALSE);
}

int	config_len_b(int config_value)
{
	if (config_value == FLOOR || config_value == CEILING)
		return (1);
	else if (config_value == NORTH || config_value == SOUTH \
	|| config_value == EAST || config_value == WEST || config_value == DOOR)
		return (2);
	else
		return (0);
}

int	hexmap_atoi_b(char *str, int *i)
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

char	*generate_texture_text_b(int texture_type)
{
	char	*texture_text;

	if (texture_type == NORTH)
		texture_text = ft_strdup("north texture(NO)");
	else if (texture_type == SOUTH)
		texture_text = ft_strdup("south texture(SO)");
	else if (texture_type == EAST)
		texture_text = ft_strdup("east texture(EA)");
	else if (texture_type == WEST)
		texture_text = ft_strdup("west texture(WE)");
	else if (texture_type == DOOR)
		texture_text = ft_strdup("door texture(DO)");
	else
		texture_text = ft_strdup("invalid texture");
	return (texture_text);
}
