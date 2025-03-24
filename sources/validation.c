/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:31:47 by educastro         #+#    #+#             */
/*   Updated: 2025/03/24 18:10:47 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	valid_open_wall(t_cub3d *cub3d, size_t x, size_t y);

// valida as paredes superiores e inferiores do mapa, em seguida valida a parte interna do mapa.
void	valid_walls(t_cub3d *cub3d)
{
	size_t	x;
	size_t	y;

	if (valid_charset(cub3d->map[0], VALID_WALLS_CHAR_SET) != NULL
		|| valid_charset(cub3d->map[cub3d->map_y - 1],
			VALID_WALLS_CHAR_SET) != NULL)
	{
		free_texture(cub3d);
		ft_free_split(cub3d->map);
		err_exit(ERR_INVALID_OPEN_MAP);
	}
	y = 1;
	while (y < (cub3d->map_y - 1))
	{
		x = 0;
		while (cub3d->map[y][x] != '\0')
		{
			valid_open_wall(cub3d, x, y);
			x++;
		}
		y++;
	}
}

char	*valid_args(int argc, char **argv)
{
	size_t	filename_size;
	size_t	extension_size;

	if (argc != 2)
		err_exit(ERR_INVALID_ARG_NUM);
	filename_size = ft_strlen(argv[1]);
	extension_size = ft_strlen(FILE_EXTENSION);
	if (filename_size < extension_size)
		err_exit(ERR_INVALID_FILE_NAME);
	while (extension_size--)
	{
		if (argv[1][--filename_size] != FILE_EXTENSION[extension_size])
			err_exit(ERR_INVALID_FILE_NAME);
	}
	return (argv[1]);
}

void	valid_map(t_cub3d *cub3d)
{
	size_t	player_count;
	size_t	y;
	char	*invalid_char;

	player_count = 0;
	y = 0;
	while (y < cub3d->map_y)
	{
		invalid_char = valid_charset(cub3d->map[y], VALID_CHAR_SET);
		if (invalid_char == NULL)
		{
			ft_fprintf(STDERR_FILENO, ERR_INVALID_CHAR, *invalid_char);
			free_map_and_texture(cub3d);
		}
		player_count += valid_player(cub3d->map[y++]);
		get_player_position(cub3d, cub3d->map[y - 1], y - 1);
	}
	if (player_count != -1)
	{
		ft_fprintf(STDERR_FILENO, ERR_INVALID_PLAYER, player_count);
		free_map_and_texture(cub3d);
	}
	valid_walls(cub3d);
}

// retorna o ponteiro do caractere inválido, caso contrário retorna NULL
char	*valid_charset(char *str, char *set)
{
	size_t	index;

	while (*str != '\0')
	{
		index = 0;
		while (set[index] != '\0')
		{
			if (set[index] == *str)
				break ;
			index++;
		}
		if (set[index] == '\0')
			break ;
		str++;
	}
	if (*str == '\0')
		return (NULL);
	return (str);
}

// valida espaços sem parede (charset: 0).
static void	valid_open_wall(t_cub3d *cub3d, size_t x, size_t y)
{
	if (cub3d->map[y][x] == '0')
	{
		if (x == 0 || cub3d->map[y][x + 1] == '\0')
		{
			ft_free_split(cub3d->map);
			free_texture(cub3d);
			err_exit(ERR_INVALID_OPEN_MAP);
		}
		if (cub3d->map[y + 1][x] == ' ' || cub3d->map[y - 1][x] == ' '
			|| cub3d->map[y][x + 1] == ' ' || cub3d->map[y][x - 1] == ' ')
		{
			ft_free_split(cub3d->map);
			free_texture(cub3d);
			err_exit(ERR_INVALID_OPEN_MAP);
		}
	}
}
