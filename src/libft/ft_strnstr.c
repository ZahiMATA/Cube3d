/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:55:33 by ybouroga          #+#    #+#             */
/*   Updated: 2025/07/17 14:56:51 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* @CDOC char *ft_strnstr(const char *big, const char *little, size_t len)
 * @RETOUR Recherche la première occurrence de la chaîne à terminaison nulle
 * little dans la chaîne big , en ne recherchant pas plus de len caractères.
 * Les caractères qui apparaissent après le caractère  “\0” ne sont pas
 * recherchés.
 * VALEURS RENVOYÉES Si little est une chaîne vide, big est renvoyé ;
 * si little n'apparaît nulle part dans big, NULL est re tourné ;
 * sinon, un pointeur sur le premier caractère de la première occurrence de
 * little est re tourné.
 * @IN ft_strnstr "hello world" "wo" 9
 * @OUT "word"
 * @IN ft_strnstr "hello world" "wo" 8
 * @OUT NULL
 * @IN ft_strnstr "hello world" "" 10
 * @OUT "hello world"
 * @IN ft_strnstr "abcd" "bc" 2
 * @OUT NULL
 * @IN ft_strnstr "abcd" "bc" 3
 * @OUT "bcd"
 */
#include "libft.h"

static int	is_start_contain(const char *big, const char *little, size_t n)
{
	size_t	i;

	i = 0;
	while (big[n + i] && little[i] && big[n + i] == little[i])
		i++;
	if (little[i] == '\0')
		return (1);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l;

	if (little[0] == '\0')
		return (((char *)big));
	if (len <= 0)
		return (NULL);
	l = 0;
	while (little[l])
		l++;
	i = 0;
	while (big[i] && i < len - l + 1)
	{
		if (is_start_contain(big, little, i))
		{
			return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void test(char *big, char *little, int n)
{
	char *s = ft_strnstr(big, little, n);
	printf("big=%p:%s\nlit=%p:%s\ns  =%p:%s\n", big, big, little, little, s, s);
}

void aff(size_t n)
{
	size_t i=2;
	printf("a=%lub=%lu\n",sizeof(size_t), sizeof(long) );
	while (i<n)
	{
		printf("%zu:%lu:%lu\n", i, i, n);
		i*=i;
	}
}
int	main(int argc, char *argv[])
{
	//aff(1844674407370955161);
	if (argc == 3) test(NULL, argv[1], atoi(argv[2]));
	else if (argc == 4) test(argv[1], argv[2], atoi(argv[3]));
	else (printf("Wrong args"));
}
*/
