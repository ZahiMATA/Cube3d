/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:52:28 by ybouroga          #+#    #+#             */
/*   Updated: 2025/05/16 12:42:06 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* @CDOC ft_isdigit
 * @RETOUR Vérifie la présence d'un chiffre (0 à 9).
 * @IN ft_isdigit 0
 * @OUT 1
 */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
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

	if((ft_isdigit(c) != 0) == (isdigit(c) != 0 ))
		printf("OK");
	else
		printf("KO");
}*/
