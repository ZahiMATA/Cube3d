/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:04:54 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/28 13:48:56 by ybouroga         ###   ########.fr       */
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

// void	cub_print_color(char *s, t_vec3 v)
// {
// 	if (DEBUG)
// 		printf("[%s][%f,%f,%f]\n", s, \
// 			v.v[0] * C_255_999, \
// 			v.v[1] * C_255_999, \
// 			v.v[2] * C_255_999);
// }

static void cub_show_map(t_cub *m)
{
	int	col=0;
	int	lig;

	lig = 0;
	while (lig < m->map_height)
	{
		col = 0;
		while (col < m->map_width)
		{
			if ((int)m->player.x == col && (int)m->player.y == lig)
				printf("x");
			else
				printf("%c", m->map[lig][col]);
			col++;
		}
		printf("\n");
		lig++;
	}
}

void	cub_debug_camera(t_cub *m)
{
	t_camera	c;

	if (DEBUG)
	{
		c = m->camera;
		cub_print_var_d("width ", m->width);
		cub_print_var_d("height", m->height);
		cub_print_var_d("fov angle        ", c.fov_angle);
		cub_print_var_d("tan fov angle    ", c.tan_fov);
		cub_print_var_d("map width        ", m->map_width);
		cub_print_var_d("map height       ", m->map_height);
		cub_print_var_d("texture w        ", m->texture->w);
		cub_print_var_d("texture h        ", m->texture->h);
		cub_show_map(m);
		printf("\n");
	}
}
