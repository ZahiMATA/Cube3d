/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:53:25 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/20 19:41:04 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*static*/ unsigned int get_texture_pixel(t_img *t, int x, int y)
{
	char	*pixel;

	if (x < 0)
		x = 0;
	else if (x >= t->w)
		x = t->w - 1;
	if (y < 0)
		y = 0;
	else if (y >= t->h)
		y = t->h - 1;
	pixel = t->addr + (y * t->size_line + (x * (t->bpp / 8)));
	return (*(unsigned int *) pixel);
}
// static int	get_texture_color(t_cub *m)
// {
// 	int color =  0xff00ff;
// 	if (m->rec.face == FACE_NORTH)
// 		color = 0xff0000;
// 	if (m->rec.face == FACE_EAST)
// 		color = 0x008000;
// 	if (m->rec.face == FACE_WEST)
// 		color = 0x000080;
// 	return (color);
// }
static int	get_texture_color(t_cub *m)
{
	int 	color;
	double	step;
	t_img	*texture;
	double	texture_position;
	int		y;

	texture = &m->texture[m->rec.face];
	step = (double)texture->h / m->rec.line_height;
	texture_position = (m->rec.draw_begin - m->height / 2 + m->rec.line_height / 2) * step;
	y = m->rec.draw_begin;
	while (y <= m->rec.draw_end)
	{
		texture_position += step;
		color = get_texture_pixel(texture, m->rec.p.x, texture_position);
		// cub_print_var_d("tex", texture_position);
		// cub_print_var_d("?", step);
		y++;
	}
	 //color = 0xff00ff;
	return (color);
}

static	void	cub_draw_v_wall(t_cub *m, int x)
{
	//int	line_height;
	// int	draw_begin;
	// int	draw_end;
	int	y;

	m->rec.line_height = /*(int)*/(m->height / m->rec.t); // peut etre a 0 a proteger
	m->rec.draw_begin = (m->height - m->rec.line_height) / 2;
	m->rec.draw_end = (m->height + m->rec.line_height) / 2;

	y = 0;
	while (y < m->rec.draw_begin)
		cub_putpixel(m, x, y++, m->color_ceiling);
	while (y < m->rec.draw_end)
		 cub_putpixel(m, x, y++, get_texture_color(m));
	while (y < m->height)
		cub_putpixel(m, x, y++, m->color_floor);
}

void	cub_render(t_cub *m)
{
	int		x;

	x = 0;
	while (x < m->width)
	{
		cub_init_camera(m, x);
		// cub_print_var_d("x",x);
		// cub_print_vec("o",m->ray.origin);
		// cub_print_vec("d", m->ray.dir);
		if (cub_hit_grid(m, m->ray, &m->rec))
			cub_draw_v_wall(m, x);
		x++;
		cub_putpixel(m, x, x, 0xff00ff);
	}
	// printf("Press enter...");
    //  getchar();
    // printf("[%u] go !\n", m->seed);
	//if (DEBUG) exit(0);
}
