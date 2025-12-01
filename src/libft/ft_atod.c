/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:30:51 by ybouroga          #+#    #+#             */
/*   Updated: 2025/12/01 15:07:24 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_isinvalid(const char *str)
{
	return (*str == '\0' || !(*str == '+' || *str == '-' || *str == '.'
			|| ft_isdigit(*str)));
}

size_t	skip_whitespace(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	return (i);
}

static double	parse_mantissa(const char *str, int *negative)
{
	double	result;
	int		i;
	size_t	decimal_digit_count;

	i = 0;
	result = 0.0;
	if (str[i] == '-')
	{
		*negative = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	if (str[i] == '.')
	{
		i++;
		while (str[i] && ft_isdigit(str[i]))
			result = result * 10 + (str[i++] - '0');
		decimal_digit_count = i - 1 - (ft_strchr(str, '.') - str);
		result /= pow(10., decimal_digit_count);
	}
	return (result);
}

double	ft_atod(const char *str)
{
	int			negative;
	double		result;

	negative = 0;
	str += skip_whitespace(str);
	if (ft_isinvalid(str))
		return (NAN);
	result = parse_mantissa(str, &negative);
	if (negative)
		result = -result;
	return (result);
}
