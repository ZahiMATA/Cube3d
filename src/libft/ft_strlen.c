/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:05:08 by ybouroga          #+#    #+#             */
/*   Updated: 2025/05/02 10:51:26 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* @CDOC
 * @RETOUR La fonction strlen() renvoie le nombre d'octets de la chaîne de 
 * caractères pointée par s.
 * @IN ft_strlen.c ABC
 * @OUT 3
 */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char *s;

	s = "hello";
	printf("%lu:%zu", strlen(s), ft_strlen(s));
}*/
