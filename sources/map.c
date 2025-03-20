/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:06:16 by educastro         #+#    #+#             */
/*   Updated: 2025/03/20 19:44:26 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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