/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:22:51 by lbarreto          #+#    #+#             */
/*   Updated: 2025/07/22 17:39:30 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

static void	extract_rgb(char *floor_rgbcode, int *i, int *rgb)
{
	int	j;

	j = 0;
	while (floor_rgbcode[*i])
	{
		if (floor_rgbcode[*i] == ',' || floor_rgbcode[*i] == ' ')
			(*i)++;
		else
		{
			rgb[j] = hexmap_atoi(floor_rgbcode, i);
			j++;
		}
	}
}

static char	decimal_to_hex(int decimal)
{
	if (decimal == 15)
		return ('F');
	if (decimal == 14)
		return ('E');
	if (decimal == 13)
		return ('D');
	if (decimal == 12)
		return ('C');
	if (decimal == 11)
		return ('B');
	if (decimal == 10)
		return ('A');
	return (decimal + '0');
}

static int	hex_to_decimal(char hex)
{
	if (hex == 'F')
		return (15);
	if (hex == 'E')
		return (14);
	if (hex == 'D')
		return (13);
	if (hex == 'C')
		return (12);
	if (hex == 'B')
		return (11);
	if (hex == 'A')
		return (10);
	return (hex - '0');
}

int	rgb_to_int(char *floor_rgbcode)
{
	int		rgb[3];
	char	hex[6];
	int		i;
	int		result;

	i = 0;
	result = 0;
	extract_rgb(floor_rgbcode, &i, rgb);
	hex[5] = decimal_to_hex(rgb[2] % 16);
	hex[4] = decimal_to_hex(rgb[2] / 16);
	hex[3] = decimal_to_hex(rgb[1] % 16);
	hex[2] = decimal_to_hex(rgb[1] / 16);
	hex[1] = decimal_to_hex(rgb[0] % 16);
	hex[0] = decimal_to_hex(rgb[0] / 16);
	i = 0;
	while (i < 6)
	{
		result += (hex_to_decimal(hex[i]) * pow(16, 5 - i));
		i++;
	}
	return (result);
}
