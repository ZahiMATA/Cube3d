/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:19:31 by zmata             #+#    #+#             */
/*   Updated: 2025/12/03 14:54:18 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	copy_into(char *res, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
}

char	*ft_strjoin_z(char *s1, char *s2)
{
	int		len;
	char	*res;

	len = ft_strlenn(s1) + ft_strlenn(s2);
	res = malloc(len + 1);
	if (!res)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	copy_into(res, s1, s2);
	free(s1);
	free(s2);
	return (res);
}

int	ft_strlenn(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strdup_until(char *s, int n)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(n + 1);
	if (!res)
		return (NULL);
	while (i < n && s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
