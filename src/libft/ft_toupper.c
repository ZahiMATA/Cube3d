/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:09:44 by ybouroga          #+#    #+#             */
/*   Updated: 2025/05/04 11:11:24 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* @CDOC ft_toupper
 * @RETOUR Si c est une lettre minuscule, toupper() renvoie son équivalent en 
 * majuscules, si une représentation en majuscules existe dans la locale 
 * actuelle.
 * La valeur renvoyée est celle de la lettre convertie, ou c si la conversion 
 * n'a pas été possible.
 * @IN ft_toupper a
 * @OUT A
 */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c + 'A' - 'a');
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(int argc, char *argv[])
{
	char	c;

	c = argv[1][0];
	printf("%c%c", toupper(c), ft_toupper(c));
}*/
