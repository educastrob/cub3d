/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:06:16 by educastro         #+#    #+#             */
/*   Updated: 2025/03/24 18:10:44 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static size_t	get_end_empty_lines(t_cub3d *cub3d);
static void		clean_lines(t_cub3d *cub3d, size_t max_width);

void	read_map(t_cub3d *cub3d, char *map_file)
{
	size_t	lines_size;
	int		fd;
	char	*line;

	lines_size = get_file_size(map_file);
	if (lines_size == 0)
		return err_exit(ERR_INVALID_EMPTY_FILE);
	fd = open(map_file, O_RDONLY);
	lines_size -= parse_parameters(cub3d, fd, &line);
	cub3d->map = malloc((lines_size + 1) * sizeof(char *));
	if (cub3d->map == NULL)
		err_exit(ERR_INVALID_MALLOC);
	cub3d->map[lines_size] = NULL;
	cub3d->map_y = lines_size;
	lines_size = 0;
	while (TRUE)
	{
		cub3d->map[lines_size++] = line;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
	}
	close(fd);
}

void	get_player_position(t_cub3d *cub3d, char *line, size_t current_y)
{
	char	*ptr;

	ptr = valid_charset(line, NOT_PLAYER_CHAR_SET);
	if (ptr != NULL)
	{
		cub3d->player.x = (double)(ptr - line) + 0.5;
		cub3d->player.y = (double)(current_y) + 0.5;
		if (*ptr == 'S')
		{
			cub3d->plane.x = -0.66;
			cub3d->dir.y = 1;
		}
		else if (*ptr == 'E' || *ptr == 'W')
		{
			cub3d->plane.x = 0;
			cub3d->plane.y = 0.66;
			cub3d->dir.x = 1;
			cub3d->dir.y = 0;
			if (*ptr == 'W')
				cub3d->plane.y = -0.66;
			if (*ptr == 'W')
				cub3d->dir.x = -1;
		}
		*ptr = '0';
	}
}

void	normalize_map(t_cub3d *cub3d)
{
	size_t	max_width;
	size_t	empty_lines;
	char	**new_map;

	max_width = find_max_map_width(cub3d);
	cub3d->map_x = max_width + 1;
	clean_lines(cub3d, max_width);
	empty_lines = get_end_empty_lines(cub3d);
	if (empty_lines == 0)
	 return ;
	cub3d->map_y -= empty_lines;
	new_map = malloc((cub3d->map_y + 1) * sizeof(char *));
	if (new_map == NULL)
		err_exit(ERR_INVALID_MALLOC);
	new_map[cub3d->map_y] = NULL;
	ft_memcpy(new_map, cub3d->map, cub3d->map_y * sizeof(char *));
	while (empty_lines--)
		free(cub3d->map[cub3d->map_y + empty_lines]);
	free(cub3d->map);
	cub3d->map = new_map;
}

// limpar e alocar linhas
static void	clean_lines(t_cub3d *cub3d, size_t max_width)
{
	size_t	i;
	size_t	j;
	char	*new_line;

	i = 0;
	while (i < cub3d->map_y)
	{
		j = 0;
		while (cub3d->map[i][j] != '\0' && cub3d->map[i][j] != '\n')
			j++;
		new_line = malloc((max_width + 1) * sizeof(char));
		if (new_line == NULL)
			err_exit(ERR_INVALID_MALLOC);
		new_line[max_width] = '\0';
		ft_memset(new_line, ' ', max_width);
		ft_memcpy(new_line, cub3d->map[i], j);
		free(cub3d->map[i]);
		cub3d->map[i] = new_line;
		i++;
	}
}

// retorna o numero de linhas vazias no final do mapa.
static size_t	get_end_empty_lines(t_cub3d *cub3d)
{
	size_t	i;

	i = cub3d->map_y - 1;
	while (i > 0)
	{
		if (!is_empty_line(cub3d->map[i]))
			return (cub3d->map_y - i - 1);
		i--;
	}
	return (0);
}