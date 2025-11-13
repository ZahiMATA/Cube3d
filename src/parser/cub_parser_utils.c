/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:46:02 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/13 11:56:31 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	is_nan(double x)
{
	return (x != x);
}

void	validate_token_count(char **tokens, t_cub **m, int expected_count,
				char *error_msg)
{
	int	i;

	i = 0;
	while (tokens[i])
		i++;
	if (i != expected_count)
		cub_exit(error_msg, *m);
}
