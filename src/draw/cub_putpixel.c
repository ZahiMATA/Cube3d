/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_putpixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:19:56 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/13 11:55:15 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_putpixel(t_cub *m, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && y >= 0 && x < m->width && y < m->height)
	{
		pixel = m->addr + (y * m->size_line + (x * (m->bpp / 8)));
		*(unsigned int *) pixel = color;
	}
}
