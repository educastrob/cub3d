/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:43:03 by educastro         #+#    #+#             */
/*   Updated: 2025/03/24 12:03:52 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// remove caractere "\n" e retorna uma nova string sem esse caractere.
char	*remove_new_line(char *str)
{
	int		i;
	int		size;
	char	*line;

	i = 0;
	size = ft_strlen(str);
	line = malloc(size * sizeof(char));
	if (line == NULL)
		return (NULL);
	while (i < size - 1)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	free(str);
	return (line);
}

int	is_empty_line(char *str)
{
	return (valid_charset(str, " \n") == NULL);
}

size_t	get_file_size(char *map_file)
{
	char	*line;
	int		fd;
	size_t	lines_size;

	lines_size = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		err_exit(ERR_INVALID_MAP_FILE);
	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		lines_size++;
		free(line);
	}
	close(fd);
	return (lines_size);
}

size_t	find_max_map_width(t_cub3d *cub3d)
{
	size_t	i;
	size_t	j;
	size_t	max;

	i = 0;
	max = 0;
	while (i < cub3d->map_y)
	{
		j = 0;
		while (cub3d->map[i][j] != '\0' && cub3d->map[i][j] != '\n')
			j++;
		if (j > max)
			max = j;
		i++;
	}
	return (max);
}

void	free_map_and_texture(t_cub3d *cub3d)
{
	ft_free_split(cub3d->map);
	free_texture(cub3d);
	exit(EXIT_FAILURE);
}
