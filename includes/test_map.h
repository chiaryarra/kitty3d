/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yathayde <yathayde@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:55:39 by yathayde          #+#    #+#             */
/*   Updated: 2025/07/09 17:31:36 by yathayde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MAP_H
# define TEST_MAP_H

# include "kitty3d.h"
# include "mlx.h" 

t_map  *create_stub_map(void);
void  init_engine(t_map *m);
int   close_window_stub(t_map *m);
void  cast_rays(t_map *m);
int can_move(t_map *m, double x, double y);

#endif