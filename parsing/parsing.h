#ifndef PARSING_H
# define PARSING_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
typedef struct s_info_cub
{
	char *nort_texture;
	char *south_texture;
	char *west_texture;
	char *east_texture;
	int floor_color[3];
	int ceiling_color[3];
	char **map;
	int cmp_info;
}	t_info_cub;

/*main*/
void writer_error(char *str);
int	parsing(char *fichier_cub);
char*get_next_line(int fd);
char *verif_line(char *line, int *who_info, int *index_start);
char	*ft_strdup(const char *s);


/*verif_colo*/
void take_info_color(char *line, int *who_info, int *index_start, t_info_cub *t_info_line);// renvoie le nom du fichier sans espace en trop avant et apres verifie si il souvre
void verif_empty_color(char *line, int *index_start, int *who_info, t_info_cub *t_info_line);

/*verif_file*/
char *ft_strdup_n(char *str, int debut, int fin);
int cut_space(char *str, int *index_start);
char *verif_empty_file(char *line, int *index_start);
void take_info_file(char *line, int *who_info, int *index_start, t_info_cub *t_info_line);// renvoie le nom du fichier sans espace en trop avant et apres verifie si il souvre

void print_struct(t_info_cub *t_info_line);
#endif