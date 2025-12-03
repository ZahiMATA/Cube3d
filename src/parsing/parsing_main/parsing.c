/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:00:57 by zmata             #+#    #+#             */
/*   Updated: 2025/12/03 16:44:43 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	parsing(char *fichier_cub, t_info_cub	*t_info_line)
{
	init_t_info_line(t_info_line);
	t_info_line->fd = open(fichier_cub, O_RDONLY);
	if (t_info_line->fd == -1 \
			|| (fichier_cub[ft_strlen_z(fichier_cub) -1] != 'b'
			|| fichier_cub[ft_strlen_z(fichier_cub) -2] != 'u'
			|| fichier_cub[ft_strlen_z(fichier_cub) -3] != 'c'
			|| fichier_cub[ft_strlen_z(fichier_cub) -4] != '.'
			|| ft_strlen_z(fichier_cub) <= 4))
	{
		writer_error(MSG_001);
		close(t_info_line->fd);
		exit(EXIT_FAILURE);
	}
	parsing_loop(t_info_line->fd, t_info_line);
	close(t_info_line->fd);
	take_in_table(&t_info_line->liste_map, t_info_line);
	last_verif(t_info_line);
	check_map_closed(t_info_line);
}
