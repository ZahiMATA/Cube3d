/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_random.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:36:10 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/13 11:55:15 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	random_double(t_cub *m)
{
	m->seed = (1103515245 * m->seed + 12345) % 0x7fffffff;
	m->seed *= 2;
	return (m->seed / (double)0x7fffffff);
}

// #include <time.h>     // pour time()
// double	random_double(t_cub *m)
// {
//     //srand(time(NULL));
//     double n = rand() / (double)RAND_MAX;
// 	m->seed =n;
// 	//printf("[%f]\n", n);
// 	return n;
// }

double	random_double_range(t_cub *m, double min, double max)
{
	return (random_double(m) * (max - min) + min);
}
