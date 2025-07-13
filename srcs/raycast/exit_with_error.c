/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yathayde <yathayde@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:26:16 by yathayde          #+#    #+#             */
/*   Updated: 2025/07/09 17:26:17 by yathayde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* srcs/exit_with_error.c */
#include "kitty3d.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*
 * Imprime "Error\n<msg>\n" no stderr, libera m (se não NULL) e sai com EXIT_FAILURE.
 */
void exit_with_error(char *msg, t_map *m)
{
    if (msg)
    {
        write(2, "Error\n", 6);
        write(2, msg, strlen(msg));
        write(2, "\n", 1);
    }
    if (m)
        free(m);
    exit(EXIT_FAILURE);
}
