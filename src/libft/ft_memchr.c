/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:42:18 by ybouroga          #+#    #+#             */
/*   Updated: 2025/05/04 15:29:42 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* @CDOC ft_memchr
 * @RETOUR  Parcourt les n octets initiaux de la zone de mémoire indiquée 
 * par s à la recherche de la première instance de c. Tant c que les octets de
 * la zone de mémoire indiquée par s sont interprétés comme des caractères 
 * non signés.
 * Renvoit un pointeur sur l'octet correspondant ou NULL si le caractère
 * ne se trouve pas dans la zone de mémoire donnée.
 * @IN ft_memchr hi i 2
 * @OUT i
 */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)((unsigned char *)s + i));
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <stdlib.h>
void	test1(char c)
{
	char	*s1;
	char	*s2;

	s1 = "Hello world";
	s2 = ft_memchr(s1, c, 20);
	printf("%p:%s\n%p:%s\n", s1, s1, s2, s2);
}

void 	test2(char *s, char c, int n)
{
	void	*p = ft_memchr(s, c, n);
        printf("%p:%s\n%p:%s\n", s, s, p, (unsigned char *)p);

}

int     main(int argc, char *argv[])
{
	if (argc == 2) test1(argv[1][0]);
	if (argc == 3) test2(argv[1], '\0', atoi(argv[2]));
	if (argc == 4) test2(argv[1], argv[2][0], atoi(argv[3]));
}
*/
