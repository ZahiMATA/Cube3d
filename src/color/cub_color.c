/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:30:50 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/13 16:02:46 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_vec4	learp(float x, t_vec4 v0, t_vec4 v1) // WHY learp AND NOT lerp ?
{		// IS IT FOR “linear extrapolation” — I.E., USING X OUTSIDE [0, 1] RANGE?
	return (
		vec4_add(
			vec4_scale(v0, 1 - x),
			vec4_scale(v1, x)
		)
	);
}

static	t_vec4	get_bckgnd_color(t_ray ray) // BACKROUND COLOR GRADIANT WITH Y AXIS
{
	t_vec4	vect_unit;
	double	a;
	t_vec4	color_start;
	t_vec4	color_end;

	color_start = int_to_color(COLOR_BCKGND_BOTTOM);
	//cub_print_vec("v0", color_start);
	color_end = int_to_color(COLOR_BCKGND_TOP);
	//cub_print_vec("v1", color_end);
	vect_unit = vec3_normalize(ray.dir);
	//cub_print_vec("vect_unit", vect_unit);
	a = 0.5 * (vect_unit.v[1] + 1.0); // NORMALIZED VALUE BETWEEN [0.0,1.0]
	//cub_print_var_d("a", a);
	return (learp(a, color_start, color_end));
}

// TODO si ray non modifie supprimer le parametre t_ray ray
t_vec4		ray_color(t_cub *m, const t_ray ray)
{
	t_vec4	color;
	t_hit_record	rec;
	double shade;


	if (cub_hit_grid(m, ray, &rec))
	{
		shade = 1.0 / (1 + rec.t * SHADE_RATIO);
		color = vec4_init(shade, shade, shade, 0);
		return (color);
	}
	else
	{
		color = get_bckgnd_color(m->ray);
		// cub_print_vec("color", color);
		// cub_print_color("color=", color);
	}
	return (color);
}

// t_vec4	ray_color(t_cub *m, t_ray ray, int depth)
// {
// 	t_hit_record rec;
// 	t_vec4	color;

// 	if (depth <= 0)
// 		return vec4_init(0, 0, 0, 0); // noir : plus de rebonds

// 	if (cub_hit(m, ray, &rec))
// 	{
// 		t_vec4 target_dir = random_on_hemisphere(m, rec.normal);
// 		t_ray scattered = ray_new(rec.p, target_dir);
// 		color = vec4_scale(ray_color(m, scattered, depth - 1), 0.5);
// 	}
// 	else
// 		color = get_ray_color(ray);

// 	return color;
// }

