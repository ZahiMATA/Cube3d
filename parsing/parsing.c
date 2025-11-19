#include "parsing.h"
void print_struct(t_info_cub *t_info_line)
{
	printf("%s\n", t_info_line->nort_texture);
	printf("%s\n", t_info_line->south_texture);
	printf("%s\n", t_info_line->east_texture);
	printf("%s\n", t_info_line->west_texture);
	printf("%d,", t_info_line->floor_color[0]);
	printf("%d,", t_info_line->floor_color[1]);
	printf("%d\n", t_info_line->floor_color[2]);
	printf("%d,", t_info_line->ceiling_color[0]);
	printf("%d,", t_info_line->ceiling_color[1]);
	printf("%d\n", t_info_line->ceiling_color[2]);
	printf("ca marche !!!\n");
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*tab;

	i = 0;
	while (s[i])
		i++;
	tab = malloc((i + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	i = 0;
	while (s[i])
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char *remove_backslash_n(char *line)
{
	int len;
	char *result = NULL;

	len = 0;

	while(line[len] &&line[len] != '\n')
		len++;
	result = malloc((len + 1) * sizeof(char));
	if(!result)
		return(NULL);
	len = 0;
	while(line[len] &&line[len] != '\n')
	{
		result[len] = line[len];
		len++;
	}
	result[len] = '\0';
	free(line);
	return(result);
}

void writer_error(char *str)
{
	printf("Error: %s\n", str);
}

int	parsing(char *fichier_cub)
{
	int fd;
	int who_info = 0;
	int	index_start = 0;
	char *line = NULL;
	char *line_tmp = NULL;
	t_info_cub t_info_line;
	t_info_line = (t_info_cub){0};

	fd = open(fichier_cub, O_RDONLY);
	if(fd == -1)
	{
		writer_error("impossible ouvrir le fichier");
		return(1);
	}
	while((line = (get_next_line(fd))))
	{
		index_start = 0;
		who_info = 0;
		line = remove_backslash_n(line);
		line_tmp = verif_line(line, &who_info, &index_start); //verif si ligne valable et quelle type info return line a null si echoue
		if(!line_tmp)
		{
			free(line);
			continue;
		}
		line = line_tmp;
		if(who_info <= 4)
		{
			take_info_file(line, &who_info, &index_start, &t_info_line); // prends que les bonne utile et verifie si vide ou non
					t_info_line.cmp_info++;
		}
		else if(who_info  == 5 || who_info  == 6)
		{
			take_info_color(line, &who_info, &index_start, &t_info_line); // prends que les bonne utile et verifie si vide ou non
					t_info_line.cmp_info++;
		}
		else if(who_info == 7)
		{
				//printf("map/n");
				t_info_line.cmp_info++;
		}
		free(line);
	}
	if(t_info_line.cmp_info < 7)
	{
		writer_error("nombre de fichier inssufisant pour construire la map.");
		return(1);
	}
	close(fd);
	print_struct(&t_info_line);
	return(0);
}

int main(int argc, char **argv)
{
	(void)argc;
	if (argc != 2)
		return(0);
	parsing(argv[1]);
	return(0);
}


/*
	TODO :
-si open echoue
-si stdup echoue
-si gnl echoue
! -gere doule tableau de la map
! -gerer le tableau en liste chaine puis le mettre en double tableau
!+ rendre le code propre
!= changer le nom des struct et fonction
si pas .xpm dois erreur
*/