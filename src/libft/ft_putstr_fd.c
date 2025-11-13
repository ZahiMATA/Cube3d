/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:26:55 by ybouroga          #+#    #+#             */
/*   Updated: 2025/05/14 17:56:26 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* @CDOCS void ft_putstr_fd(char *s, int fd);
 * @RETURN Écrit la chaîne de caractères ’s’ sur le descripteur de fichier donné.
 * @IN ft_putchar_fd azer 1
 * @OUT azer
 */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}
/*
#include <stdlib.h>
#include <stdio.h>
static void test1(char *s, int n)
{
	ft_putstr_fd(s, n);
}

int     main(int argc, char *argv[])
{
        if (argc == 3) test1(argv[1], atoi(argv[2]));
	else printf("Wrong params!");
}*/
