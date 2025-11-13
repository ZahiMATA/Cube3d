/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hit_record.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:40:39 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/13 11:55:15 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_face_normal(t_ray ray, t_vec4 outward_normal, t_hit_record *rec)
{
	rec->front_face = vec3_dot(ray.dir, outward_normal) < 0;
	if (rec->front_face)
		rec->normal = outward_normal;
		//rec->normal = vec4_scale(outward_normal, -1);
	else
		rec->normal = vec4_scale(outward_normal, -1);
}

bool	cub_hit(const t_cub *m, const t_ray r, t_interval inter, t_hit_record *rec)
{
	//t_interval		inter_temp;
	bool				hit_anything;
	t_param_sphere_hit	_; // CHANGE TO t_param_hit ?

	hit_anything = false;
	_.ray = r;
	_.inter = inter;
	//cub_print_var_d("max", inter.max);
	_.rec = rec;
	_.i = 0;
	//rec->t = inter.max;
	//rt_print_var_d("t avant", rec->t);
	//cub_print_vec("N avant", rec->normal);
	while (_.i < m->nb_sphere)
	{
		if (cub_sphere_hit(m, &_))
		{
			//printf("ok[%d][%f]\n", _.i, m->rec.t);
			hit_anything = true;
			//_.inter.max = rec->t;
			_.inter.max = _.rec->t;
		}
		//printf("ok[%d][%f]\n", _.i, m->rec.t);
		_.i++;
	}
	_.i = 0;
	while (_.i < m->nb_plane)
	{
		if (cub_plane_hit(m, &_))
		{
			//printf("ok[%d][%f]\n", _.i, m->rec.t);
			hit_anything = true;
			_.inter.max = _.rec->t;
		}
		//printf("ok[%d][%f]\n", _.i, m->rec.t);
		_.i++;
	}

	return (hit_anything);
}
