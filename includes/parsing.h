/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:01:04 by zmata             #+#    #+#             */
/*   Updated: 2025/12/03 17:01:09 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include "vec3.h"

# define MSG_001 "Unable to open the file/incorrect extension"
# define MSG_002 "incorrect information - last verification"
# define MSG_003 "Incorrect number or order of information"
# define MSG_004 "Non-compliant map"
# define MSG_005 "Unable to find any information or incorrect information"
# define MSG_006 "One line on the map is empty"
# define MSG_007 "Malloc failed"
# define MSG_008 "Map is not closed"
# define MSG_009 "Invalid number of players"
# define MSG_010 "Double array malloc problem"
# define MSG_011 "A duplicate with an incorrect color or value"
# define MSG_012 "RGB value out of range"
# define MSG_013 "duplicate or file name problem"

typedef struct s_gnl_state
{
	char	buffer[1];
	int		nbr_octect_lu;
	int		index_buffer;
}	t_gnl_state;

typedef struct s_node
{
	char			*line;
	struct s_node	*next;
}	t_node;

typedef struct s_info_cub
{
	char	*nort_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color[3];
	int		ceiling_color[3];
	t_node	*liste_map;
	char	**map;
	int		cmp_info;
	int		nbr_line_tab;
	t_vec3	player;
	int		fd;
}	t_info_cub;

/* parsing / main */
void	writer_error(char *str);
void	parsing(char *fichier_cub, t_info_cub	*t_info_line);
char	*verif_line(char *line, int *who_info, int *index_start);
char	*verif_start(char *str);
char	*ft_strdup_z(char *s);
void	init_t_info_line(t_info_cub *t_info_line);
void	last_verif(t_info_cub *t_info_line);

/* parsing_loop */
void	handle_map_line(char *line, t_info_cub *info);
void	handle_info_line(char *line, \
		int who_info, int *index_start, t_info_cub *info);
void	process_non_empty(char *line, t_info_cub *info);
void	process_line(char *line, t_info_cub *info);
void	parsing_loop(int fd, t_info_cub *info);

/* verif_color */
void	take_info_color(char *line, int *who_info, int *index_start, \
			t_info_cub *t_info_line);
void	verif_empty_color(char *line, int *index_start, int *who_info, \
			t_info_cub *t_info_line);
int		is_digit(char c);
int		is_valid(char *str, int *i);
int		has_only_space(char *str);
void	color_error(char *line, char *tmp, t_info_cub *info);

/* verif_file */
int		cut_space(char *str, int *index_start);
char	*verif_empty_file(char *line, int *index_start);
void	take_info_file(char **line, int *who_info, int *index_start, \
				t_info_cub *t_info_line);
void	set_texture(char **texture, char *path, \
			char **line, t_info_cub *t_info_line);

/* verif_map */
int		check_map(char *line, t_node **list_map);

/* liste chainee */
int		len_line_i(t_node **list_map, int which_line);
void	new_value(char *new_line, t_node **list_map);
void	printf_liste(t_node **list_map);
char	*return_line_i_to_liste(t_node **list_map, int which_line);
void	free_list(t_node *lst);

/* tableau de map */
void	take_in_table(t_node **liste_map, t_info_cub *t_info_line);

/* flood_fill map */
int		check_map_closed(t_info_cub *info);
void	flood_step(t_info_cub *info, int y, int x, int **vis);

/* exit / gestion mémoire globale */
void	exit_prog(char *str, t_info_cub *t_info_line);

/* divers utils */
void	print_struct(t_info_cub *t_info_line);
int		ft_strlen_z(char *str);
char	*ft_strdup_n(char *str, int debut, int fin);
char	*get_next_linee(int fd);
char	*ft_strdup_until(char *s, int n);
int		ft_strlenn(char *s);
char	*ft_strjoin_z(char *s1, char *s2);
char	*remove_backslash_n(char *line);

/* divers map */
void	print_tab(char **tab);
void	free_tab(char **tab);

void	free_all(t_info_cub *t_info_line);

#endif
