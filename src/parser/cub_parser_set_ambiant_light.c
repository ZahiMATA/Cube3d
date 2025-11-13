/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser_set_ambiant_light.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:46:02 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/13 11:56:31 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	parse_ambient_ratio(t_cub **m, char **tokens)
{
	(*m)->ambient.ratio = ft_atod(tokens[1]);
	if (is_nan((*m)->ambient.ratio)
		|| (*m)->ambient.ratio < 0.0
		|| (*m)->ambient.ratio > 1.0)
		cub_exit(ERROR_INVALID_AL_DATA, *m);
}

static void	parse_ambient_rgb(t_cub **m, char **tokens)
{
	int	i;

	(*m)->ambient_rgb_tokens = ft_split(tokens[2], ',');
	if ((*m)->ambient_rgb_tokens == NULL)
		cub_exit(ERROR_MALLOC, *m);
	i = 0;
	while ((*m)->ambient_rgb_tokens[i])
		i++;
	if (i != 3)
		cub_exit(ERROR_INVALID_AL_DATA, *m);
	(*m)->ambient.color.r = (unsigned char)ft_atod((*m)->ambient_rgb_tokens[0]);
	(*m)->ambient.color.g = (unsigned char)ft_atod((*m)->ambient_rgb_tokens[1]);
	(*m)->ambient.color.b = (unsigned char)ft_atod((*m)->ambient_rgb_tokens[2]);
	if (is_nan((*m)->ambient.color.r)
		|| is_nan((*m)->ambient.color.g)
		|| is_nan((*m)->ambient.color.b)
		|| (*m)->ambient.color.r < 0 || (*m)->ambient.color.r > 255
		|| (*m)->ambient.color.g < 0 || (*m)->ambient.color.g > 255
		|| (*m)->ambient.color.b < 0 || (*m)->ambient.color.b > 255)
		cub_exit(ERROR_INVALID_AL_DATA, *m);
}

static void	print_ambient_light_debug(t_cub **m, char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		printf(" %s", tokens[i]);
		i++;
	}
	printf("[ambient ratio   ][%0.2f]\n", (*m)->ambient.ratio);
	printf("[ambient color   ][%d,%d,%d]\n\n",
		(*m)->ambient.color.r,
		(*m)->ambient.color.g,
		(*m)->ambient.color.b);
}

void	set_ambient_light(t_cub **m, char **tokens)
{
	validate_token_count(tokens, m, 3, ERROR_INVALID_AL_DATA);
	parse_ambient_ratio(m, tokens);
	parse_ambient_rgb(m, tokens);
	print_ambient_light_debug(m, tokens);
}
