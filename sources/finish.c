/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilopes <rilopes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:47:43 by educastro         #+#    #+#             */
/*   Updated: 2025/04/22 03:10:32 by rilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_texture(t_cub3d *cub3d)
{
	if (cub3d->south_texture != NULL)
		mlx_delete_texture(cub3d->south_texture);
	if (cub3d->north_texture != NULL)
		mlx_delete_texture(cub3d->north_texture);
	if (cub3d->west_texture != NULL)
		mlx_delete_texture(cub3d->west_texture);
	if (cub3d->east_texture != NULL)
		mlx_delete_texture(cub3d->east_texture);
}

void	free_for_finish(t_cub3d *cub3d)
{
	free_texture(cub3d);
	ft_free_split(cub3d->map);
	mlx_delete_image(cub3d->mlx_ptr, cub3d->image);
}

void	err_exit(char *str)
{
	ft_fprintf(STDERR_FILENO, str);
	exit(EXIT_FAILURE);
}

void	close_err_exit(int fd, char *str)
{
	close(fd);
	ft_fprintf(STDERR_FILENO, str);
	exit(EXIT_FAILURE);
}

void	close_free_err_exit(int fd, char **arr, char *err_message)
{
	ft_free_split(arr);
	close_err_exit(fd, err_message);
}
