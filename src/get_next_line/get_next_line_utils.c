/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:09:33 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/13 11:56:31 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	ln;

	ln = 0;
	while (*s)
	{
		ln++;
		s++;
	}
	return (ln);
}

char	*ft_strcpy_gnl(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup_gnl(const char *s)
{
	char	*dest;

	dest = malloc(ft_strlen_gnl(s) + 1);
	if (!dest)
		return (NULL);
	dest = ft_strcpy_gnl(dest, s);
	return (dest);
}

char	*ft_strjoin_gnl(const char *s1, const char *s2)
{
	char	*dest;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	dest = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
