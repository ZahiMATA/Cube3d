/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:37:16 by ybouroga          #+#    #+#             */
/*   Updated: 2025/05/16 12:45:44 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* @CDOC ft_isascii
 * @RETOUR Vérifie si c est une valeur char non signée de 7 bits 
 * qui correspond au jeu de caractères ASCII.
 * @IN ft_isascii A
 * @OUT 1
 */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
int	main(int argc, char *argv[])
{
	int	i;
	char	c;

	i = 0;
	while (i < 256)
	{
		if((ft_isascii(i) != 0) != (isascii(i) != 0 ))
                	printf("KO:i=%d(i)=%c\n", i, i);
		i++;
	}
	c = argv[1][0];
	if((ft_isascii(c) != 0) == (isascii(c) != 0 ))
		printf("OK");
	else
		printf("KO");
}*/
