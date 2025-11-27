/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_collision_mur_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:04:58 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/27 14:22:10 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	test_collision_mur(t_cub *m, t_vec2 *q, t_vec2 dir)
{
	(void)dir;
	// double radius = EPSILON;

	// int cx = (int)(q.x + (dir.x * radius));
	// int cy = (int)(q.y + (dir.y * radius));

	// if (m->map[(int)p->y][cx] == CHAR_1) return;
	// if (m->map[cy][(int)p->x] == CHAR_1) return;
	if(m->map[(int)q->y][(int)q->x] == CHAR_1)
		return (true);
	return (false);


}