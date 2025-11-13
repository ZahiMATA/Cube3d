/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:21:44 by ybouroga          #+#    #+#             */
/*   Updated: 2025/05/07 17:50:54 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* CDOC char *ft_substr(char const *s, unsigned int start, size_t len)
 * RETOUR Alloue (avec malloc) et retourne une chaîne de caractères issue de 
 * la chaîne ’s’.Cette nouvelle chaîne commence à l’index ’start’ et a pour 
 * taille maximale ’len’
 * @IN ft_substr abcd 1 2
 * @OUT ab
 */

#include <stdlib.h>
#include "libft.h"

static char	*ft_strndup(const char *s, size_t n)
{
	char	*zone;
	size_t	len;
	size_t	i;

	len = 0;
	while (s[len] && len < n)
		len++;
	zone = malloc((len + 1) * sizeof(char));
	if (zone == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		zone[i] = s[i];
		i++;
	}
	zone[i] = '\0';
	return (zone);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;

	if (start > ft_strlen(s) || !s[0])
		return (ft_strndup("", 0));
	i = 0;
	while (i < start && *s++)
		i++;
	ret = ft_strndup(s, len);
	if (ret == NULL)
		return (NULL);
	return (ret);
}
/*
#include <stdio.h>
#include <stdlib.h>

void test1(char *s, int n)
{
	int i = 0;
	while (i < n)
	{
		printf("%c:%d\n", s[i], i);
		i++;
	}
}
void test4(char *s, int start, int len)
{
        char *sdup = ft_strdup(s);
	char *ret  = ft_substr(sdup, start, len);
	printf("str:%p:%s\n", s, s);
	printf("str:%p:%s\n", sdup, sdup);
	printf("ret:%p:%s\n", ret, ret);
	free(ret);
}

int	main(int argc, char *argv[])
{
	if (argc == 1) test1("A\0B", 20);
	else if (argc == 4) test4(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]));
	else printf("Wrong params!");
}*/
