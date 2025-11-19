#include "parsing.h"

char *ft_strdup_n(char *str, int debut, int fin)
{
	int i = 0;
	char *result;
	result = malloc((fin - debut + 1) * sizeof(char));
	if(!result)
		return(NULL);
	while(debut < fin && str[debut])
	{
		result[i] = str[debut];
		i++;
		debut++;
	}
	result[i] = '\0';
	return(result);
}
int cut_space(char *str, int *index_start)
{
	while(str[*index_start] && (str[*index_start] == ' ' || str[*index_start] == '\t'))
		(*index_start)++;
	return(*index_start);
}

char *verif_empty_file(char *line, int *index_start)
{
	int index_start_temp = 0;
	char *line_temp = NULL;
	int fd = 0;

	*index_start = cut_space(line, index_start);
	if(*index_start == -1)
		return(NULL);
	index_start_temp = *index_start;
	while(line[*index_start] && (line[*index_start] != ' ' && line[*index_start] != '\t'))
	{
		(*index_start)++;
	}
	line_temp = ft_strdup_n(line, index_start_temp, *index_start);
	fd = open(line_temp, O_RDONLY);
	if(fd == -1)
	{
		writer_error("impossible d ouvrir une des textures.");
		free(line_temp);
		return(NULL);
	}
	close(fd);
	return(line_temp);
}


void take_info_file(char *line, int *who_info, int *index_start, t_info_cub *t_info_line)// renvoie le nom du fichier sans espace en trop avant et apres verifie si il souvre
{
	*index_start = *index_start + 2;// +2= NO SO ect
		line = verif_empty_file(line, index_start); // verif si vide et bon chemin et si peux ouvrir
	if(!line)
		return;
	if(*who_info == 1)
			t_info_line->nort_texture = ft_strdup(line);
	else if(*who_info == 2)
			t_info_line->south_texture = ft_strdup(line);
	else if(*who_info == 3)
			t_info_line->west_texture = ft_strdup(line);
	else if(*who_info == 4)
			t_info_line->east_texture = ft_strdup(line);
	free(line);
	return;
}