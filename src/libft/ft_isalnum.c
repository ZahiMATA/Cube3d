/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:29:29 by ybouroga          #+#    #+#             */
/*   Updated: 2025/05/16 12:41:19 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* @CDOC ft_isalnum
 * @RETOUR Vérifie la présence d'un caractère alphanumérique ; elle est 
 * équivalente à (isalpha(c) || isdigit(c)).
 * @IN ft_isalnum A
 * @OUT 1
 */

int	ft_isalnum(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'));
}
/*
#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
int	main(int argc, char *argv[])
{
	char	c;

	c = argv[1][0];

	if((ft_isalnum(c) != 0) == (isalnum(c) != 0 ))
		printf("OK");
	else
		printf("KO");
}*/
