/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:20:22 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/13 12:05:22 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_basic_init(t_cub **m)
{
	(void) m;
}

void	cub_init(t_cub **m, char *filepath)
{
	*m = ft_calloc(1, sizeof(t_cub));
	if (*m == NULL)
		cub_exit(ERROR_MALLOC, *m);
	cub_basic_init(m);
	cub_parser(m, filepath);
	vec3_normalise_color((*m)->ambient.color, &(*m)->ambient.colorN);
}
