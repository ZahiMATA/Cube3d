/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:35:45 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/13 11:55:15 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_free_null(void **ptr)
{
	if (ptr == NULL || *ptr == NULL)
		return ;
	free(*ptr);
	*ptr = NULL;
}

// free only m->mlx nothing else
static void	cub_free_image_window_mlx(t_cub *m)
{
	if (m->mlx && m->image)
		mlx_destroy_image(m->mlx, m->image);
	if (m->mlx && m->window)
		mlx_destroy_window(m->mlx, m->window);
	if (m->mlx)
	{
		mlx_destroy_display(m->mlx);
		free(m->mlx);
	}
}

// static void	cub_free_array(char	***tab)
// {
// 	int	i;

// 	i = 0;
// 	if (tab == NULL || *tab == NULL)
// 		return ;
// 	while ((*tab)[i])
// 		cub_free_null(&(*tab)[i++]);
// 	free(*tab);
// 	*tab = NULL;
// }


/* Same as :
  free((*m)->map);
  (*m)->map = NULL;
  free(*m);
  (*m) = NULL;
*/

void	cub_free_tokens(char ***tokens_ptr)
{
	char **tokens = *tokens_ptr;
	int	i;

	if (tokens == NULL)
		return ;
	i = 0;
	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		tokens[i] = NULL;
		i++;
	}
	free(tokens);
	*tokens_ptr = NULL;
}

void	cub_free_all(t_cub **m)
{
	if (m == NULL || *m == NULL)
		return ;

	cub_free_tokens(&(*m)->ambient_rgb_tokens);
	cub_free_tokens(&(*m)->camera_center_xyz_tokens);
	cub_free_tokens(&(*m)->camera_axis_xyz_tokens);
	cub_free_tokens(&(*m)->light_xyz_tokens);
	cub_free_tokens(&(*m)->sphere_xyz_tokens);
	cub_free_tokens(&(*m)->sphere_rgb_tokens);
	cub_free_tokens(&(*m)->plane_xyz_tokens);
	cub_free_tokens(&(*m)->plane_normal_tokens);
	cub_free_tokens(&(*m)->plane_rgb_tokens);
	cub_free_tokens(&(*m)->cylinder_xyz_tokens);
	cub_free_tokens(&(*m)->cylinder_axis_tokens);
	cub_free_tokens(&(*m)->cylinder_rgb_tokens);
	cub_free_tokens(&(*m)->rt_file_line_tokens);
	get_next_line(FREE_STASH);
	cub_free_null((void **)&(*m)->rt_file_line);
	close((*m)->fd_rt_file);
	cub_free_null((void **)&(*m)->sphere);
	cub_free_null((void **)&(*m)->plane);
	cub_free_null((void **)&(*m)->cylinder);
	cub_free_image_window_mlx(*m);
	// TODO cub_free_null((void **) &((*m)->points));
	cub_free_null((void **) m);
}

void	cub_free_mat(char **mat, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(mat[i++]);
	free(mat);
}
