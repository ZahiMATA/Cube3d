/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:14:58 by ybouroga          #+#    #+#             */
/*   Updated: 2025/05/14 16:17:26 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* @CDOCS char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
 * @RETURN Applique la fonction ’f’ à chaque caractère de la chaîne de 
 * caractères ’s’, passant son index comme premier argument et le caractère 
 * lui-même comme second argument. Une nouvelle chaîne de caractères est créée
 * (avec malloc(3)), résultant des applications successives de ’f’.
 * @IN   ft_strmapi "ABC" (avec f(c-n))
 * @OUT  "AAA"
 */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	l;
	char	*zone;

	i = 0;
	l = ft_strlen(s);
	zone = malloc((l + 1) * sizeof(char));
	if (zone == NULL)
		return (NULL);
	while (i < l)
	{
		zone[i] = f(i, s[i]);
		i++;
	}
	zone[i] = '\0';
	return (zone);
}
/*
#include <stdlib.h>
#include <stdio.h>

static char	up(unsigned int n, char c)
{
	return (c-n);
}


static void test1(char *s)
{
	char	*ret;

	ret = ft_strmapi(s, &up);
	printf("ret:%p:%s\n", ret, ret);
        free(ret);
}

int     main(int argc, char *argv[])
{
        if (argc == 2) test1(argv[1]);
	else printf("Wrong params!");
}*/
