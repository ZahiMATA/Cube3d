/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:29:29 by ybouroga          #+#    #+#             */
/*   Updated: 2025/05/16 12:42:54 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* @CDOC ft_isalpha
 *
 * @RETOUR
 * Vérifie la présence d'un caractère alphabétique ; dans la locale "C" 
 * standard, elle est équivalente à (isupper(c) || islower(c)).
 * Dans certaines locales, il peut y avoir des caractères supplémentaires pour 
 * lesquels isalpha() est vrai - des lettres qui ne sont ni majuscules ni 
 * minuscules.
 *
 * @IN ft_isalpha A 
 * @OUT 1
 */
int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
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

	c = argv[1][0];

	if((ft_isalpha(c) != 0) == (isalpha(c) != 0 ))
		printf("OK:%d\n", ft_isalpha(c));
	else
		printf("KO:%d\n", ft_isalpha(c));
}*/
