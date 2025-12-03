/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:00:57 by zmata             #+#    #+#             */
/*   Updated: 2025/12/03 14:51:01 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	parsing(char *fichier_cub, t_info_cub	*t_info_line)
{
	int			fd;

	init_t_info_line(t_info_line);
	fd = open(fichier_cub, O_RDONLY);
	if (fd == -1 || (fichier_cub[ft_strlen_z(fichier_cub) -1] != 'b'
			|| fichier_cub[ft_strlen_z(fichier_cub) -2] != 'u'
			|| fichier_cub[ft_strlen_z(fichier_cub) -3] != 'c'
			|| fichier_cub[ft_strlen_z(fichier_cub) -4] != '.'
			|| ft_strlen_z(fichier_cub) <= 4))
	{
		writer_error("impossible ouvrir le fichier/ou extension incorrecte");
		exit(EXIT_FAILURE);
	}
	parsing_loop(fd, t_info_line);
	close(fd);
	take_in_table(&t_info_line->liste_map, t_info_line);
	last_verif(t_info_line);
	check_map_closed(t_info_line);
}
