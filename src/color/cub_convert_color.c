/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_convert_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:16:46 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/13 11:55:15 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec4 int_to_color(int n)
{
	t_vec4	ret;

	ret.v[0] = ((n >> 16) & 0xFF) / C_255;
	ret.v[1] = ((n >> 8) & 0xFF) / C_255;
	ret.v[2] = (n & 0xFF) / C_255;
	ret.v[3] = 0;
	return (ret);
}

int	color_to_int(t_vec4 v)
{
	int	r;
	int	g;
	int	b;
	r = C_255_999 * v.v[0];
	g = C_255_999 * v.v[1];
	b = C_255_999 * v.v[2];
	return ((r << 16) | (g << 8) | b);
}

t_vec4	*vec3_normalise_color(t_color v, t_vec4 *res)
{
	res->v[0] = v.r / C_255;
	res->v[1] = v.g / C_255;
	res->v[2] = v.b / C_255;
	res->v[3] = 0;
	return (res);
}
