/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:39:43 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/13 11:55:15 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_exit(char *message, t_cub *m)
{
	if (message)
		printf("%s", message);
	cub_free_all(&m);
	exit(EXIT_FAILURE);
}

int	cub_close_window(void *param)
{
	t_cub	*m;

	m = (t_cub *) param;
	if (m->mlx)
		mlx_loop_end(m->mlx);
	return (0);
}
