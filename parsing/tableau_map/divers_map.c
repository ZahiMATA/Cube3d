/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divers_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmata <zmata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:01:10 by zmata             #+#    #+#             */
/*   Updated: 2025/11/25 10:27:39 by zmata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_main/parsing.h"

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	printf("\n");
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
