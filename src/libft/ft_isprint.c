/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:29:29 by ybouroga          #+#    #+#             */
/*   Updated: 2025/05/16 12:45:22 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* @CDOC ft_isprint
 * @RETOUR 
 * Vérifie la présence de tout caractère imprimable, y compris les espaces.
 * @IN ft_isprint A
 * @OUT 0
 */

int	ft_isprint(int c)
{
	return (c > 0x1F && c < 0x7F);
}
/*
#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
int	main(int argc, char *argv[])
{
	char	c;
	int	i;

	c = 0;
	i = 0;
	while (i < 256)
	{
		if ((ft_isprint(i) != 0) == (isprint(i) != 0 ))
		{
			//printf("OK:i=%d(i)=%c\n", i, i);
		}
		else
			printf("KO:i=%d(i)=%c\n", i, i);

		i++;
	}
	c = argv[1][0];
	if((ft_isprint(c) != 0) == (isprint(c) != 0 ))
		printf("OK");
	else
		printf("KO");
}*/
