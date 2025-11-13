/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:06:42 by ybouroga          #+#    #+#             */
/*   Updated: 2025/05/14 18:56:08 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* @CDOCS void ft_putnbr_fd(int n, int fd);
 * @RETOUR Écrit l’entier ’n’ sur le descripteur de fichier donné.
 * @IN ft_putnbr_fd -1234
 * @OUT 1234
 */

#include <unistd.h>

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	l;

	l = n;
	if (l < 0)
	{
		ft_putchar('-', fd);
		l *= -1;
	}
	if (l > 9)
		ft_putnbr_fd(l / 10, fd);
	ft_putchar((l % 10) + '0', fd);
}
/*
#include <stdlib.h>
#include <stdio.h>
static void test1(int n, int fd)
{
	ft_putnbr_fd(n, fd);
}

int     main(int argc, char *argv[])
{
        if (argc == 3) test1(atoi(argv[1]), atoi(argv[2]));
	else printf("Wrong params!");
}*/
