/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:09:44 by ybouroga          #+#    #+#             */
/*   Updated: 2025/05/04 11:17:46 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* @CDOC ft_tolower
 * @RETOUR Si c est une lettre majuscule, tolower() renvoie son équivalent en 
 * minuscules, si une représentation en minuscules existe dans la locale 
 * actuelle. Sinon, elle renvoie c. 
 * La valeur renvoyée est celle de la lettre convertie, ou c si la conversion 
 * n'a pas été possible.
 * @IN ft_tolower A
 * @OUT a
 */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 'a' - 'A');
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(int argc, char *argv[])
{
	char	c;

	c = argv[1][0];
	printf("%c%c", tolower(c), ft_tolower(c));
}*/
