/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:38:21 by ybouroga          #+#    #+#             */
/*   Updated: 2025/05/02 16:02:43 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* @CDOC size_t ft_strlcpy(char *dst, const char *src, size_t siz)
 * @RETOUR Copie une chaîne de caractères. Copie src dans la chaîne dst de 
 * taille siz. Au plus siz-1 caractères seront copiés. Se termine toujours par 
 * NULL (sauf si siz == 0).
 * Retourne La fonction strlcpy() retourne strlen(src). 
 * Si retval >= siz, une troncature a eu lieu.
 * @IN "ABCDEFGHIJ" "abcdefghij" 5
 * @OUT "abcd\0FGHIJ"
 * @IN "ABCDEFGHIJ" "123456789" 0
 * @OUT "ABCDEFGHIJ"
 */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;

	i = 0;
	while (siz > 1 && src[i] && i < siz - 1)
	{
		dst[i] = ((char *)src)[i];
		i++;
	}
	if (siz > 0)
	{
		dst[i] = '\0';
	}	
	i = 0;
	while (src[i])
		i++;
	return (i);
}
/*
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void aff(char *s, int n)
{
	int i = 0;
	while (i < n)
	{
		printf("[%c:%d]", s[i], s[i]);
		i++;
	}
	printf("%c", '\n');
}
void	afficher(char *str, size_t n)
{
	int i = 0;
	while (str[i] && i < n)
		printf("%c", str[i++]);
	printf("\n");
}
void	init_inc(char *str, char c, size_t n)
{
	int i = 0;
	while (i < n-1)
	{
		str[i] = i + c;
		i++;
	}
	str[i] = '\0';
}

void	test1(char car1, char car2, int n)
{
	char	c1;
	char	c2;
	char	s1[11];
	char	s2[11];
	size_t	i;

	c1 = car1;//argv[1][0];
	c2 = car2;//argv[2][0];
	init_inc(s1, c1, sizeof(s1));
	init_inc(s2, c2, sizeof(s2));
        printf("[s1=%s:len=%lu]\n",s1, sizeof(s1));
        printf("[s2=%s:len=%lu]\n",s2, sizeof(s2));
	ft_strlcpy(s1, s2, n);
        printf("[s1=%s:len=%lu]\n",s1, sizeof(s1));
        printf("[s2=%s:len=%lu]\n",s2, sizeof(s2));
	afficher(s1, sizeof(s1));
        afficher(s2, sizeof(s2));
        aff(s1, sizeof(s1));
        aff(s2, sizeof(s2));
	//i = strlcpy(s2, s1, 5);
}

void	test2(char *s1, char *s2, int n)
{
	ft_strlcpy(s1, s2, n);
        printf("[s1=%s:len=%lu]\n",s1, strlen(s1));
        printf("[s2=%s:len=%lu]\n",s2, strlen(s2));
	aff(s1, sizeof(s1));
        aff(s2, sizeof(s2));

}


int     main(int argc, char *argv[])
{
	int i = 2;
	if (i==1) test1(argv[1][0], argv[2][0], atoi(argv[3]));
	if (i==2) test2(argv[1], argv[2], atoi(argv[3]));
}*/
