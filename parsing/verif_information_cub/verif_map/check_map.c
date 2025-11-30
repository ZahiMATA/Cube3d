/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmata <zmata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:01:46 by zmata             #+#    #+#             */
/*   Updated: 2025/11/26 10:21:31 by zmata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing_main/parsing.h"

int	check_map(char *line, t_node **list_map)
{
	int	i;

	i = 0;
	i = cut_space(line, &i);
	if (*list_map == NULL)
	{
		while (line[i] && (line[i] == ' ' || line[i] == '\t'
				|| line[i] == '1' || line[i] == '0'
				|| line[i] == 'N' || line[i] == 'S'
				|| line[i] == 'E' || line[i] == 'W'))
			i++;
		if (line[i] != '\0')
			return (-1);
	}
	else
	{
		while (line[i] && (line[i] == '1' || line[i] == '0'
				|| line[i] == 'N' || line[i] == 'S'
				|| line[i] == 'E' || line[i] == 'W'
				|| line[i] == ' ' || line[i] == '\t'))
			i++;
		if (line[i] != '\0')
			return (-1);
	}
	return (0);
}
