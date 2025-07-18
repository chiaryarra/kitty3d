/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendtrim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:07:15 by lbarreto          #+#    #+#             */
/*   Updated: 2025/07/17 20:31:01 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	verif(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strendtrim(char *s1, char const *set)
{
	int		end;
	int		i;
	char	*str;

	end = ft_strlen(s1);
	i = 0;
	while (end > 0 && verif(s1[end - 1], set) == 0)
		end--;
	str = (char *)malloc((end + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < end)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}
