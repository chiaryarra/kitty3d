/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:25:50 by lbarreto          #+#    #+#             */
/*   Updated: 2025/07/24 12:53:29 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	calculate_strings_len(char **strings)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (strings[i])
	{
		count += ft_strlen(strings[i]);
		count++;
		i++;
	}
	return (count);
}

char	*ft_unsplit(char **strings, char separator)
{
	char	*unsplitted;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = calculate_strings_len(strings);
	unsplitted = (char *)malloc(len * sizeof(char));
	if (!unsplitted)
		return (NULL);
	while (strings[j])
	{
		ft_strlcpy(unsplitted + i, strings[j], ft_strlen(strings[j]) + 1);
		i += ft_strlen(strings[j]);
		unsplitted[i] = separator;
		i++;
		j++;
	}
	unsplitted[i - 1] = '\0';
	return (unsplitted);
}

/* int	main(void)
{
	char	*str = "Hello World Chiara!";
	int		i = 0;
	char	**strs;
	char	*str2;

	strs = ft_split(str, ' ');
	while (strs[i])
	{
		my_printf("%s\n", strs[i]);
		i++;
	}
	str2 = ft_unsplit(strs, '-');
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	my_printf("%s\n", str2);
	free(str2);
	return (0);
} */
