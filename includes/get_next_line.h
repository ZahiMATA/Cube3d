/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:09:53 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/13 11:56:31 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> // for read(), close(), ssize_t
# include <stdlib.h> // for malloc(), free()
# include <fcntl.h> // for open()
# include <stddef.h> // for size_t

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define GNL_OK 1
# define GNL_EOF 0
# define GNL_ERR -1

char	*get_next_line(int fd);

size_t	ft_strlen_gnl(const char *s);
char	*ft_strcpy_gnl(char *dest, const char *src);
char	*ft_strdup_gnl(const char *s);
char	*ft_strjoin_gnl(const char *s1, const char *s2);
char	*ft_strchr_gnl(const char *s, int c);

char	*ft_substr_gnl(const char *s, unsigned int start, size_t len);
char	*split_line(const char *str, char **after_nl);

#endif