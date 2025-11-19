#include "parsing.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

void	verif_empty_color(char *line, int *index_start, int *who_info,
						 t_info_cub *t_info_line)
{
	int		i;
	int		start;
	char	*tmp;

	// se placer après les espaces après F ou C
	*index_start = cut_space(line, index_start);
	if (*index_start == -1)
		return;

	i = 0;
	while (i < 3)
	{
		// sauter les espaces avant le nombre
		*index_start = cut_space(line, index_start);
		if (*index_start == -1)
			return;

		// début du nombre
		start = *index_start;

		// avancer tant que c'est un chiffre
		while (line[*index_start] && is_digit(line[*index_start]))
			(*index_start)++;

		// copier le nombre
		tmp = ft_strdup_n(line, start, *index_start);
		if (!tmp)
			return;

		// stocker dans la bonne couleur (F = floor, C = ceiling)
		if (*who_info == 5)
			t_info_line->floor_color[i] = atoi(tmp);
		else
			t_info_line->ceiling_color[i] = atoi(tmp);

		free(tmp);

		// sauter les espaces après le nombre
		*index_start = cut_space(line, index_start);
		if (*index_start == -1)
			break;

		// si il reste une virgule et qu'on n'est pas au dernier nombre, on la saute
		if (line[*index_start] == ',' && i < 2)
		{
			(*index_start)++;
		}
		i++;
	}
}

void	take_info_color(char *line, int *who_info, int *index_start,
						t_info_cub *t_info_line)
{
	// on est sur 'F' ou 'C', on avance de 1
	*index_start = *index_start + 1;
	verif_empty_color(line, index_start, who_info, t_info_line);
}
