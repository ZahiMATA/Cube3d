/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:54:58 by ybouroga          #+#    #+#             */
/*   Updated: 2025/05/04 17:45:48 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* @CDOC void *ft_memmove(void *dest, const void *src, size_t n)
 * @RETOUR Copie n octets de la zone mémoire src vers la zone mémoire 
 * zone de mémoire dest.  Les zones de mémoire peuvent se chevaucher : la copie 
 * s'effectue comme si les octets dans src sont d'abord copiés dans un tableau 
 * temporaire qui ne chevauche ni src ni dest, et les octets sont ensuite 
 * copiés dans un tableau temporaire qui ne chevauche ni src ni dest. 
 * Les octets de src sont d'abord copiés dans un tableau temporaire qui ne 
 * chevauche ni src ni dest, et les octets sont ensuite copiés du tableau 
 * temporaire vers dest.
 * VALEUR DE RETOUR La fonction memmove() renvoie un pointeur sur dest.
 * @IN ft_memmove abcdefghij ABCDEFGHIJ 5
 * @OUT ABCDEfghij
 */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src == NULL && dest == NULL && n > 0)
		return (NULL);
	if (src - dest >= 0)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n)
		{
			((unsigned char *)dest)[n - 1]
				= ((const unsigned char *)src)[n - 1];
			n--;
		}
	}
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void	afficher(char *str, size_t n)
{
	int i = 0;
	while (i < n)
		printf("%c", str[i++]);
	printf("\n");
}
void	init_inc(char *str, char c, size_t n)
{
	int i = 0;
	while (i < n)
	{
		str[i] = i + c;
		i++;
	}
}

void test1(char c)
{
        char    c1;
        char    c2;
        char    s1[10];
        int     i;

        c1 = c; //argv[1][0];        
        // ok
        init_inc(s1, c1, 10);
        memcpy(s1 , s1 + 2, 5);
        afficher(s1, sizeof(s1));

        i = 0;
        init_inc(s1, c1, 10);
        memmove(s1 , s1 + 2, 5);
        afficher(s1, sizeof(s1));
        
        init_inc(s1, c1, 10);
        ft_memmove(s1, s1 + 2, 5);
        afficher(s1, sizeof(s1));
        // ko
        init_inc(s1, c1, 10);
        memcpy(s1 + 2, s1, 5);
        afficher(s1, sizeof(s1));

        i = 0;
        init_inc(s1, c1, 10);
        memmove(s1 + 2, s1, 5);
        afficher(s1, sizeof(s1));

        init_inc(s1, c1, 10);
        ft_memmove(s1 + 2, s1, 5);
        afficher(s1, sizeof(s1));
}

void test2(char *s1, char *s2, int n)
{
	ft_memmove(s1, s2, n);
	afficher(s1, strlen(s1));
	afficher(s2, strlen(s2));
}

int	main(int argc, char *argv[])
{
	int i = 2;
	if (i==1) test1(argv[1][0]);
	if (i==2) test2(argv[1], argv[2], atoi(argv[3]));
}*/
