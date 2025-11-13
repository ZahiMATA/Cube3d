/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:41:29 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/13 11:56:31 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT4_H
# define MAT4_H

typedef struct s_mat4
{
	double m[4][4];
} t_mat4;

t_vec4	mat4_mult_vec4(t_mat4 m, t_vec4 v);
double	degrees_to_radians(double degrees);

#endif
