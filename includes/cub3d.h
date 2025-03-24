/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:28:31 by educastro         #+#    #+#             */
/*   Updated: 2025/03/24 17:54:32 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42.h"
# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <float.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>

# define WIDTH 1280
# define HEIGHT 720
# define PLAYER_SPEED 0.1
# define PLAYER_ROTATE_SPEED 0.06666666666666666
# define WALL_OFFSET 0.3

# define GAME_NAME "CUB3D - by: edcastro e rilopes"
# define VALID_CHAR_SET "01NSEW\n "
# define NOT_PLAYER_CHAR_SET "01 "
# define VALID_CHAR_SET_PLAYER "NSEW"
# define VALID_WALLS_CHAR_SET "1 "
# define FILE_EXTENSION ".cub"

# define WEST "WE"
# define NORTH "NO"
# define EAST "EA"
# define SOUTH "SO"
# define FLOOR "F"
# define CEILING "C"

# define ERR_INVALID_CHAR "Error\nInvalid map char '%c'\n"
# define ERR_INVALID_PLAYER "Error\nInvalid number of players '%d'\n"
# define ERR_INVALID_TEXTURE_COLOR "Error\nInvalid map texture or map color\n"
# define ERR_INVALID_PARAMETER "Error\nInvalid parameter\n"
# define ERR_INVALID_COLOR_QUANT "Error\nInvalid number of colors\n"
# define ERR_INVALID_TEXTURE "Error\nInvalid map texture\n"
# define ERR_INVALID_DUPLICATED_COLOR "Error\nInvalid duplicated color\n"
# define ERR_INVALID_COLOR "Error\nInvalid color\n"
# define ERR_INVALID_DUPLICATED_TEXTURE "Error\nInvalid duplicated texture\n"
# define ERR_INVALID_MAP_FILE "Error\nInvalid map file\n"
# define ERR_INVALID_EMPTY_FILE "Error\nEmpty file\n"
# define ERR_INVALID_MALLOC "Error\nMalloc error\n"
# define ERR_INVALID_OPEN_MAP "Error\nOpen map\n"
# define ERR_INVALID_ARG_NUM "Error\nInvalid number of arguments\n"
# define ERR_INVALID_FILE_NAME "Error\nInvalid filename\n"
# define ERR_MISSING_PARAMS "Error\nMissing parameters\n"
# define ERR_MAP_NOT_FOUND "Error\nMap not found\n"

# define FALSE 0
# define TRUE 1

// structs
typedef struct	s_vector
{
	double		x;
	double		y;
}	t_vector;

typedef struct	s_cub3d
{
	mlx_t			*mlx_ptr;
	mlx_image_t		*image;
	char			**map;
	size_t			map_x;
	size_t			map_y;
	mlx_texture_t	*west_texture;
	mlx_texture_t	*north_texture;
	mlx_texture_t	*east_texture;
	mlx_texture_t	*south_texture;
	int64_t			floor_color;
	int64_t			ceiling_color;
	t_vector		player;
	t_vector		dir;
	t_vector		plane;
}	t_cub3d;

// init.c
void				initialize(t_cub3d *cub3d);
void				start_params(t_cub3d *cub3d);

// finish.c
void	free_texture(t_cub3d *cub3d);
void	free_for_finish(t_cub3d *cub3d);
void	err_exit(char *str);
void	close_err_exit(int fd, char *str);
void	close_free_err_exit(int fd, char **arr, char *err_message);

// validation.c
char	*valid_args(int argc, char **argv);
char	*valid_charset(char *str, char *set);
void	valid_map(t_cub3d *cub3d);

// map.c
void	read_map(t_cub3d *cub3d, char *map_file);
void	normalize_map(t_cub3d *cub3d);
void	get_player_position(t_cub3d *cub3d, char *line, size_t current_y);

// load_param.c
void	load_texture(t_cub3d *cub3d, mlx_texture_t **texture, int fd, char **words);
void	load_color(t_cub3d *cub3d, int64_t *color, int fd, char **words);

// read_param.c
size_t	parse_parameters(t_cub3d *cub3d, int fd, char **map_line);

// player.c
int		valid_player(char *line);

// utils.c
size_t	get_file_size(char *map_file);
int		is_empty_line(char *str);
char	*remove_new_line(char *str);
void	free_map_and_texture(t_cub3d *cub3d);
size_t	find_max_map_width(t_cub3d *cub3d);

#endif