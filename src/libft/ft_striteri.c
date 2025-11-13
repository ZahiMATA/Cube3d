/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:13:10 by ybouroga          #+#    #+#             */
/*   Updated: 2025/05/14 17:24:43 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* @CDOCS void ft_striteri(char *s, void (*f)(unsigned int,char*));
 * @RETURN Applique la fonction ’f’ à chaque caractère de la chaîne de 
 * caractères transmise comme argument, et en passant son index comme premier 
 * argument. Chaque caractère est transmis par adresse à ’f’ afin d’être 
 * modifié si nécessaire.
 * @IN ft_striteri abcdef
 * @OUT            acegik
 */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;
	size_t	l;

	l = ft_strlen(s);
	i = 0;
	while (i < l)
	{
		f(i, &s[i]);
		i++;
	}
	s[i] = '\0';
	i = 0;
}
/*
#include <stdio.h>
static void	decale(unsigned int n, char *s)
{
	s[0] += n;
}


static void test1(char *s)
{
	char	*s1 = ft_strdup(s);
	char	*s2 = ft_strdup(s);

	decale(1,s1);
	ft_striteri(s2, &decale);

	printf("ret:%p:%s\n", s1, s1);
	printf("ret:%p:%s\n", s2, s2);
        //free(s);
}

int     main(int argc, char *argv[])
{
        if (argc == 2) test1(argv[1]);
	else printf("Wrong params!");
}*/
