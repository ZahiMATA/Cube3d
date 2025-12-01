/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:26:55 by ybouroga          #+#    #+#             */
/*   Updated: 2025/05/14 17:46:48 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* @CDOCS void ft_putchar_fd(char c, int fd)
 * @RETURN Écrit le caractère ’c’ sur le descripteur de fichier donné.
 * @IN ft_putchar_fd a 1
 * @OUT a
 */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
#include <stdlib.h>
#include <stdio.h>
static void test1(char *s, int n)
{
	ft_putchar_fd(s[0], n);
}

int     main(int argc, char *argv[])
{
        if (argc == 3) test1(argv[1], atoi(argv[2]));
	else printf("Wrong params!");
}*/
