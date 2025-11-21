/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:04:54 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/21 17:05:24 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_print_var_d(char *s, double n)
{
	if (DEBUG)
		printf("[%s][%7f]\n", s, n);
}

void	cub_print_vec(char *s, t_vec3 v)
{
	if (DEBUG)
		printf("[%s][%.2f,%.2f,%.2f]\n", s, v.v[0], v.v[1], v.v[2]);
}

void	cub_print_color(char *s, t_vec3 v)
{
	if (DEBUG)
		printf("[%s][%f,%f,%f]\n", s, \
			v.v[0] * C_255_999, \
			v.v[1] * C_255_999, \
			v.v[2] * C_255_999);
}

void	cub_debug_camera(t_cub *m)
{
	if (DEBUG)
	{
		t_camera	c;
		int			lig;

		c = m->camera;
		cub_print_var_d("width ", m->width);
		cub_print_var_d("height", m->height);
		cub_print_var_d("viewport_h       ", m->viewport_h);
		cub_print_var_d("fov angle        ", c.fov_angle);
		cub_print_var_d("tan fov angle    ", c.tan_fov);
		cub_print_var_d("map width        ", m->map_width);
		cub_print_var_d("map height       ", m->map_height);
		cub_print_var_d("texture w        ", m->texture->w);
		cub_print_var_d("texture h        ", m->texture->h);
		lig = 0;
		while (lig < m->map_height)
			printf("%s\n", m->map[lig++]);
		printf("\n");
	}
}
