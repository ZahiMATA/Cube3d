/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:20:50 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/13 15:54:36 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
} t_color;

#endif

t_vec4	ray_color(t_cub *m, const t_ray ray);
int		color_to_int(t_vec4 v);
t_vec4	int_to_color(int n);
t_vec4	*vec3_normalise_color(t_color v, t_vec4 *res);
