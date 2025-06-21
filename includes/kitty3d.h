/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kitty3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:36:07 by lbarreto          #+#    #+#             */
/*   Updated: 2025/06/21 20:09:17 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KITTY3D_H
# define KITTY3D_H

# include "libft/libft.h"

# define TRUE 1
# define FALSE 0

enum	e_errors {
	WRONG_NAME
};


// Map reading 

char	*open_map(char *map_name);

// Validations

int		map_name_validation(char *map_name);

// Utils

void	handle_error(int error_type);

#endif