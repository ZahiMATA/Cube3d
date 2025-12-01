/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:42:18 by ybouroga          #+#    #+#             */
/*   Updated: 2025/05/04 16:22:48 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* @CDOC ft_strrchr
 * @RETOUR Renvoie un pointeur sur la dernière occurrence du caractère c de 
 * la chaîne s.
 * Renvoit un pointeur sur le caractère correspondant ou NULL si le caractère
 * n'est pas trouvé.  L'octet nul de terminaison est considéré comme faisant 
 * partie de la chaîne, de sorte que si c est spécifié comme '\0', cette 
 * fonction renvoit un pointeur sur le terminateur.
 * @IN  ft_strrchr "Hello world" l
 * @OUT ld
 */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
/*
#include <stdio.h>
void	test1()
{
	char	*s1;
	char	*s2;

	s1 = "Hello world";
	s2 = ft_strrchr(s1, 'r');
	printf("%p:%s\n%p:%s", s1, s1, s2, s2);
}

void	test2(char *s, char c)
{
	printf("%p:%s\n%p:%s\n", s, s, ft_strrchr(s, c), ft_strrchr(s, c));
}

int	main (int argc, char *argv[])
{
	if(argc == 1) test1();
	if(argc == 2) test2(argv[1], '\0');
	if(argc == 3) test2(argv[1], argv[2][0]);
}
*/
