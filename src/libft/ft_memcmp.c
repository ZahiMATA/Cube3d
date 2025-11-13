/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:42:18 by ybouroga          #+#    #+#             */
/*   Updated: 2025/05/04 15:58:23 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* @CDOC ft_memcmp
 * @RETOUR Compare les n premiers octets (chacun interprété comme un caractère 
 * non signé) des zones de mémoire s1 et s2.
 * Renvoie un nombre entier inférieur, égal ou supérieur à zéro 
 * si les  n premiers octets de s1 sont inférieurs, égaux ou supérieurs aux
 * n premiers octets de s2.
 * @IN ft_memcmp hk hi 2
 * @OUT 2
 * @IN ft_memcmp hk hi 0
 * @OUT 0
 */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i] && i < n - 1)
	{
		i++;
	}
	return ((((unsigned char *)s1)[i]) - (((unsigned char *)s2)[i]));
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void	test(char *s1, char *s2, int n)
{
	int	i1;
	int	i2;

	i1 = memcmp(s1, s2, n);
	i2 = ft_memcmp(s1, s2, n);
	printf("memcmp=%d\nft=%d\n", i1, i2);
}

int     main(int argc, char *argv[])
{
	if (argc == 2) test("\200", "\0", atoi(argv[1]));
	if (argc == 4) test(argv[1], argv[2], atoi(argv[3]));
}
*/
