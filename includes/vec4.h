/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:40:11 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/13 11:40:11 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC4_H
# define VEC4_H

typedef struct s_cub t_cub;

// 4th component
// 0 = vector
// 1 = point
typedef struct s_vec4
{
	double	v[4];
} t_vec4;

t_vec4	vec4_scale(t_vec4 v, double t);
t_vec4	vec4_add(t_vec4 v1, t_vec4 v2);
t_vec4	vec4_sub(t_vec4 v1, t_vec4 v2);
t_vec4	vec4_init(double x, double y, double z, double w);
double	vec3_sqr_length(t_vec4 v);
t_vec4	vec3_normalize(t_vec4 v);
double	vec3_dot(t_vec4 v1, t_vec4 v2);
t_vec4	vec4_rnd_dbl(t_cub *m);
t_vec4	vec4_rnd_dbl_rng(t_cub *m, double min, double max);
t_vec4	vec4_rnd_unit(t_cub *m);
t_vec4 random_on_hemisphere(t_cub *m, const t_vec4 normal);
t_vec4 vec3_hadamard_product(t_vec4 u, t_vec4 v);
t_vec4 vec3_cross(t_vec4 u, t_vec4 v);

#endif
