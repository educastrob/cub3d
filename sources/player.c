/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilopes <rilopes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:43:47 by educastro         #+#    #+#             */
/*   Updated: 2025/04/22 03:14:00 by rilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	valid_player(char *line)
{
	int	index;
	int	num;

	num = 0;
	while (*line != '\0')
	{
		index = 0;
		while (VALID_CHAR_SET_PLAYER[index] != '\0')
		{
			if (*line == VALID_CHAR_SET_PLAYER[index])
			{
				num++;
				break ;
			}
			index++;
		}
		line++;
	}
	return (num);
}

void	rotate_player(t_cub3d *cub, double angle)
{
	double	old_x;

	old_x = cub->dir_player.x;
	cub->dir_player.x = cub->dir_player.x * cos(angle)
		- cub->dir_player.y * sin(angle);
	cub->dir_player.y = old_x * sin(angle)
		+ cub->dir_player.y * cos(angle);
	old_x = cub->fov.x;
	cub->fov.x = cub->fov.x * cos(angle) - cub->fov.y * sin(angle);
	cub->fov.y = old_x * sin(angle) + cub->fov.y * cos(angle);
}

void	move_player(t_cub3d *cub, double speed, int signal)
{
	double	x_speed;
	double	y_speed;

	if (signal == 0)
	{
		x_speed = cub->dir_player.x * speed;
		y_speed = cub->dir_player.y * speed;
	}
	else
	{
		x_speed = -signal * cub->dir_player.y * speed;
		y_speed = signal * cub->dir_player.x * speed;
	}
	if ((cub->player.x + x_speed + define_step(x_speed)) > WALL_OFFSET
		&& (cub->player.x + x_speed + define_step(x_speed)) < (cub->map_x - 1
			- WALL_OFFSET))
		cub->player.x += x_speed;
	if ((cub->player.y + y_speed + define_step(y_speed)) > WALL_OFFSET
		&& (cub->player.y + y_speed + define_step(y_speed)) < (cub->map_y
			- WALL_OFFSET))
		cub->player.y += y_speed;
}
