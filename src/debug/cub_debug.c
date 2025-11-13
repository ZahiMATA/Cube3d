/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:04:54 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/13 11:55:15 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_print_var_d(char *s, double n)
{
	if (DEBUG)
		printf("[%s][%f]\n", s, n);
}

void	cub_print_vec(char *s, t_vec4 v)
{
	if (DEBUG)
		printf("[%s][%.2f,%.2f,%.2f,%.2f]\n", s, v.v[0], v.v[1], v.v[2], v.v[3]);
}

void	cub_print_color(char *s, t_vec4 v)
{
	if (DEBUG)
		printf("[%s][%f,%f,%f,%f]\n", s, \
			v.v[0] * C_255_999, \
			v.v[1] * C_255_999, \
			v.v[2] * C_255_999, \
			v.v[3] * C_255_999);
}

void	cub_debug_camera(t_cub *m)
{
	if (DEBUG)
	{
		t_camera	c;

		c = m->camera;
		cub_print_var_d("width ", m->width);
		cub_print_var_d("height", m->height);
		cub_print_var_d("viewport_h       ", m->viewport_h);
		cub_print_var_d("viewport_w       ", m->viewport_w);
		cub_print_vec("center           ", c.center);
		cub_print_vec("axis             ", c.axis);
		cub_print_vec("viewport_u       ", c.viewport_u);
		cub_print_vec("viewport_v       ", c.viewport_v);
		cub_print_vec("upper_left_corner", c.upper_left_corner);
		cub_print_vec("pixel00_loc      ", c.pixel00_loc);
		cub_print_vec("pixel_delta_u    ", c.pixel_delta_u);
		cub_print_vec("pixel_delta_v    ", c.pixel_delta_v);
	}
}
