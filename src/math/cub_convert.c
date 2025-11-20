/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:06:38 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/20 19:06:37 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	degrees_to_radians(double degrees)
{
	return (degrees * PI / 180);
}

t_vec2	fdf_rotate_xy(t_cub *m, t_vec2 p, double angle)
{
	float	cosa;
	float	sina;
	t_vec2	q;

	(void)m;
	cosa = cos(angle);
	sina = sin(angle);
	q.x = (p.x * cosa - p.y * sina);
	q.y = (p.y * cosa + p.x * sina);
	//q.z = p.z;
	return (q);
}
