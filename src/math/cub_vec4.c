/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_vec4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:50:17 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/13 11:55:15 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec4	vec4_scale(t_vec4 v, double t)
{
	t_vec4	ret;
	int		i;

	i = 0;
	while (i < 3)
	{
		ret.v[i] = v.v[i] * t;
			i++;
	}
	ret.v[3] = v.v[3];
	return (ret);
}

t_vec4	vec4_add(t_vec4 v1, t_vec4 v2)
{
	t_vec4	ret;
	int		i;

	i = 0;
	while (i < 3)
	{
		ret.v[i] = v1.v[i] + v2.v[i];
		i++;
	}
	ret.v[3] = v1.v[3] || v2.v[3];
	return (ret);
}


t_vec4	vec4_sub(t_vec4 v1, t_vec4 v2)
{
	t_vec4	ret;
	int		i;

	i = 0;
	while (i < 3)
	{
		ret.v[i] = v1.v[i] - v2.v[i];
		i++;
	}
	ret.v[3] = V_POINT;
	return (ret);
}


t_vec4	vec4_init(double x, double y, double z, double w)
{
	t_vec4	ret;
	ret.v[0] = x;
	ret.v[1] = y;
	ret.v[2] = z;
	ret.v[3] = w;
	return (ret);
}

double	vec3_sqr_length(t_vec4 v)
{
	return (v.v[0] * v.v[0] + v.v[1] * v.v[1] + v.v[2] * v.v[2]);
}

t_vec4	vec3_normalize(t_vec4 v)
{
	t_vec4	ret;
	int		i;
	double	inv_len;

	inv_len = 1 / sqrt(vec3_sqr_length(v));
	i = 0;
	while (i < 3)
	{
		ret.v[i] = v.v[i] * inv_len;
		i++;
	}
	ret.v[3] = V_POINT;
	return (ret);
}

double	vec3_dot(t_vec4 v1, t_vec4 v2)
{
	double	ret;
	int	i;

	ret = 0;
	i = 0;
	while (i < 3)
	{
		ret += v1.v[i] * v2.v[i];
		i++;
	}
	return (ret);
}

t_vec4 vec3_hadamard_product(t_vec4 u, t_vec4 v)
{
	t_vec4	ret;
	int	i;

	i = 0;
	while (i < 3)
	{
		ret.v[i] = u.v[i] * v.v[i];
		i++;
	}
	ret.v[3] = V_POINT; // IF ALWAYS A VECTOR ? DO WE KNOW ?
	return (ret);
}

t_vec4 vec3_cross(t_vec4 u, t_vec4 v)
{
	t_vec4 r;
	r.v[0] = u.v[1] * v.v[2] - u.v[2] * v.v[1];
	r.v[1] = u.v[2] * v.v[0] - u.v[0] * v.v[2];
	r.v[2] = u.v[0] * v.v[1] - u.v[1] * v.v[0];
	r.v[3] = V_POINT;
	return (r);
}
