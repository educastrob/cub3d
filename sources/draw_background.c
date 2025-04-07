/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilopes <rilopes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 22:39:16 by rilopes           #+#    #+#             */
/*   Updated: 2025/04/07 01:34:06 by rilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_background(t_cub3d *cub3d)
{
	t_vector	vector;

	vector.y = -1;
	while (++vector.y < cub3d->mlx_ptr->height / 2)
	{
		vector.x = -1;
		while (++vector.x < cub3d->mlx_ptr->width)
			mlx_put_pixel(cub3d->image, vector.x, vector.y, cub3d->ceiling_color);
	}
	while (++vector.y < cub3d->mlx_ptr->height)
	{
		vector.x = -1;
		while (++vector.x < cub3d->mlx_ptr->width)
			mlx_put_pixel(cub3d->image, vector.x, vector.y, cub3d->floor_color);
	}
}

