/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:42:41 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/20 19:08:35 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_do_hook_key(t_cub *m, int keycode)
{
	if (keycode == XK_Escape)
		mlx_loop_end(m->mlx);
	if (keycode == XK_a)
		m->player.x -= MOVE_STEP;
	if (keycode == XK_d)
		m->player.x += MOVE_STEP;
	if (keycode == XK_w)
		m->player.y -= MOVE_STEP;
	if (keycode == XK_s)
		m->player.y += MOVE_STEP;
	if (keycode == XK_Left)
		m->player_dir = fdf_rotate_xy(m, m->player_dir, ANGLE_STEP);
	if (keycode == XK_Right)
		m->player_dir = fdf_rotate_xy(m, m->player_dir, -ANGLE_STEP);
	if (keycode == XK_Up)
		m->camera.fov_angle++;
	if (keycode == XK_Down)
		m->camera.fov_angle--;
	if (keycode == XK_i)
		cub_debug_camera(m);



		// if (keycode == XK_z)
	// 	m->t.sx -= ZOOM_STEP;
	// if (keycode == XK_x)
	// 	m->t.sx += ZOOM_STEP;
	// if (keycode == XK_c)
	// 	m->t.sy -= ZOOM_STEP;
	// if (keycode == XK_v)
	// 	m->t.sy += ZOOM_STEP;
	// if (keycode == XK_b)
	// 	m->t.sz -= ZOOM_STEP;
	// if (keycode == XK_n)
	// 	m->t.sz += ZOOM_STEP;
	// if (keycode == XK_1)
	// 	m->t.angle_z -= ANGLE_STEP_PI_20;

}