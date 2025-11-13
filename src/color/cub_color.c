/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:30:50 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/13 11:55:15 by ybouroga         ###   ########.fr       */
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

// TODO rendre obligatoire le ambiant ... dans .rt
t_vec4		ray_color(t_cub *m, const t_ray ray, int depth)
{
	t_vec4	color;
	int i = 1;
	t_hit_record	rec;

	if (depth <= 0)
		return (vec4_init(0, 0, 0, 0));
	m->inter.min = VERY_LITTLE;
	m->inter.max = INFINITY;
	if (cub_hit(m, ray, m->inter, &rec))
	{
		if (i == 0)
		{
			t_vec4 N = rec.normal;
			t_vec4 N2 = vec4_init(N.v[0] + 1, N.v[1] + 1, N.v[2] + 1, 0);
			//cub_print_vec("normal", N);
			color = vec4_scale(N2, 0.5);
		}
		if (i == 1)
		{

			//cub_print_var_d("ambiant", m->ambient.ratio);
			//cub_print_vec("ambiant", m->ambient.colorN);
			//cub_print_var_d("brightness", m->light.brightness);
			t_vec4 ambient = vec4_scale( \
				vec3_hadamard_product(rec.colorN, m->ambient.colorN), \
				m->ambient.ratio);
			t_vec4 light_dir = vec4_sub(m->light.point, rec.p);
			light_dir = vec3_normalize(light_dir);

		t_ray shadow_ray;
		shadow_ray.origin = rec.p;
		shadow_ray.dir = light_dir;
		double light_distance = sqrt(vec3_sqr_length(light_dir));
		t_hit_record tmp_rec;
		int in_shadow = cub_hit(m, shadow_ray, (t_interval){.min=VERY_LITTLE, .max=light_distance}, &tmp_rec);
		t_vec4 diffuse = vec4_init(0, 0, 0, 0);
		if (!in_shadow)
		{
				double diff = vec3_dot(rec.normal, light_dir);
			if (diff < 0)
				diff = 0.0;
			t_vec4 light_color =  vec4_init(.85, .85, .85, 0); //TODO
				diffuse = vec4_scale( \
				vec3_hadamard_product(rec.colorN, light_color),
				diff * m->light.brightness);
		}

		t_vec4 final_color = vec4_add(ambient, diffuse);
		//gamma2 pour eclaircir
		final_color.v[0] = sqrt(final_color.v[0]);
		final_color.v[1] = sqrt(final_color.v[1]);
		final_color.v[2] = sqrt(final_color.v[2]);
		return final_color;
		}
		else {
			t_ray ray2;
			ray2.origin = rec.p;
			ray2.dir = vec4_add(rec.normal, random_on_hemisphere(m, rec.normal));
			//cub_print_vec("r", ray.dir);
			color = vec4_scale(ray_color(m, ray2, depth - 1), 0.5);
		}
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

