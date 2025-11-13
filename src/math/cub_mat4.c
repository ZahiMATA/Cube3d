/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mat4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:50:17 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/13 11:55:15 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// rx = (m00 * vx) + (m01 * vy) + (m02 * vz) + (m03 *vw)
t_vec4	mat4_mult_vec4(t_mat4 m, t_vec4 v)
{
	t_vec4	ret;
	int		l;
	int		c;

	l = 0;
	while (l < 4)
	{
		ret.v[l] = 0;
		c = 0;
		while (c < 4)
		{
				ret.v[l] += m.m[l][c] * v.v[c];
				c++;
		}
		l++;
	}
	return (ret);
}
