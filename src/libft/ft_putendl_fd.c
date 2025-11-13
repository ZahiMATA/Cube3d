/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:58:02 by ybouroga          #+#    #+#             */
/*   Updated: 2025/05/14 18:04:37 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* @CDOCS void ft_putendl_fd(char *s, int fd)
 * @RETOUR Écrit La chaîne de caractères ’s’ sur le descripteur de fichier 
 * donné suivie d’un retour à la ligne.
 * @IN ft_putchar_fd azer 1
 * @OUT azer
 */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}
/*
#include <stdlib.h>
#include <stdio.h>
static void test1(char *s, int n)
{
	ft_putendl_fd(s, n);
}

int     main(int argc, char *argv[])
{
        if (argc == 3) test1(argv[1], atoi(argv[2]));
	else printf("Wrong params!");
}*/
