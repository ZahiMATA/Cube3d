/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:57:47 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/13 11:40:11 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vec4.h"
# include "interval.h"

typedef struct s_cub t_cub;

typedef struct	s_ray
{
	t_vec4 origin;
	t_vec4 dir;
} t_ray;

// p : the contact point between ray and the object
typedef struct	s_hit_record
{
	t_vec4		p;
	t_vec4		normal;
	double		t;
	int			front_face;
	t_vec4		colorN;
	// t_interval	inter;
} t_hit_record;

t_vec4	ray_at(t_ray ray,  double t);
void	set_face_normal(t_ray ray, t_vec4 outward_normal, t_hit_record *rec);

#endif
