/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yathayde <yathayde@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:00:48 by yathayde          #+#    #+#             */
/*   Updated: 2025/07/09 16:51:04 by yathayde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_map.h"    /* já inclui mlx.h e kitty3d.h */
#include <stdlib.h>         /* exit() */
 

extern void  render_frame(t_map *m);
extern int   key_press(int key, t_map *m);
extern int   close_window_stub(t_map *m);

/* ——— Wrapper que casa a assinatura esperada pela mlx_loop_hook ——— */
static int  render_loop(void *param)
{
    render_frame((t_map *)param);
    return (0);
}

void  init_engine(t_map *m)
{
    m->mlx = mlx_init();
    if (!m->mlx)
        exit_with_error("mlx_init falhou", m);

    m->win = mlx_new_window(
        m->mlx, m->screen_w, m->screen_h, "Kitty3D");
    if (!m->win)
        exit_with_error("mlx_new_window falhou", m);

    m->img.img = mlx_new_image(
        m->mlx, m->screen_w, m->screen_h);
    if (!m->img.img)
        exit_with_error("mlx_new_image falhou", m);

    m->img.addr = mlx_get_data_addr(
        m->img.img,
        &m->img.bpp,
        &m->img.line,
        &m->img.endian);

    /* agora usa o wrapper, que retorna int e aceita void* */
    mlx_loop_hook(m->mlx, render_loop, m);
    mlx_hook(m->win, 2, 1L<<0, key_press, m);
    mlx_hook(m->win, 17, 0, close_window_stub, m);
    mlx_loop(m->mlx);
}