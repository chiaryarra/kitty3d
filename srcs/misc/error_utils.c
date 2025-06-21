/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 20:00:19 by lbarreto          #+#    #+#             */
/*   Updated: 2025/06/21 20:29:12 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/kitty3d.h"

void	handle_error(int error_type)
{
	if (error_type == WRONG_NAME)
		my_printf_fd(2, "\033[35mKitty3d 😺:\033[1;31m\
Wrong type of file ❌\033[0\n");
	exit(1);
}