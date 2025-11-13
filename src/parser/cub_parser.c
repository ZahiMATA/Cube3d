/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:46:02 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/13 11:56:31 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	manage_tokens_continued(t_cub **m, char **tokens)
{
	if (ft_strcmp(tokens[0], "sp") == 0)
		set_one_sphere(m, tokens);
	else if (ft_strcmp(tokens[0], "pl") == 0)
		set_one_plane(m, tokens);
	else if (ft_strcmp(tokens[0], "cy") == 0)
		set_one_cylinder(m, tokens);
	else if (ft_strcmp(tokens[0], "\n") == 0)
		;
	else
		cub_exit(ERROR_WRONG_OBJECT_ID, *m);
}

void	manage_tokens(t_cub **m, char **tokens)
{
	static bool	ambient_light_setting_captured = false;
	static bool	light_setting_captured = false;
	static bool	camera_setting_captured = false;

	if (ft_strcmp(tokens[0], "A") == 0
		&& ambient_light_setting_captured == false)
	{
		set_ambient_light(m, tokens);
		ambient_light_setting_captured = true;
	}
	else if (ft_strcmp(tokens[0], "C") == 0 && camera_setting_captured == false)
	{
		set_camera(m, tokens);
		camera_setting_captured = true;
	}
	else if (ft_strcmp(tokens[0], "L") == 0 && light_setting_captured == false)
	{
		set_light(m, tokens);
		light_setting_captured = true;
	}
	else
		manage_tokens_continued(m, tokens);
}

static bool	is_rt_file(const char *filepath)
{
	size_t	len;

	len = ft_strlen(filepath);
	if (len < 3 || ft_strncmp(filepath + len - 3, ".rt", 3) != 0)
		return (false);
	return (true);
}

static bool	is_file_empty(const char *filepath)
{
	int		fd;
	char	buffer[1];
	ssize_t	bytes_read;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (true);
	bytes_read = read(fd, buffer, 1);
	close(fd);
	if (bytes_read == 0)
		return (true);
	if (bytes_read == -1)
		return (true);
	return (false);
}

void	cub_parser(t_cub **m, char *filepath)
{
	if (!is_rt_file(filepath))
		cub_exit(ERROR_WRONG_EXT, *m);
	if (access(filepath, F_OK) == -1)
		cub_exit(ERROR_FILE_NOT_FOUND, *m);
	if (is_file_empty(filepath))
		cub_exit(ERROR_EMPTY_FILE, *m);
	(*m)->fd_rt_file = open(filepath, O_RDONLY);
	if ((*m)->fd_rt_file == -1)
		cub_exit(ERROR_OPEN_FILE, *m);
	(*m)->rt_file_line = get_next_line((*m)->fd_rt_file);
	printf("** RT_FILE DATA **************************************\n\n");
	while ((*m)->rt_file_line)
	{
		(*m)->rt_file_line_tokens = ft_split((*m)->rt_file_line, ' ');
		if ((*m)->rt_file_line_tokens == NULL)
			cub_exit(ERROR_MALLOC, *m);
		manage_tokens(m, (*m)->rt_file_line_tokens);
		cub_free_tokens(&(*m)->rt_file_line_tokens);
		cub_free_null((void **)&(*m)->rt_file_line);
		(*m)->rt_file_line = get_next_line((*m)->fd_rt_file);
	}
	printf("\n******************************************************\n\n");
}
