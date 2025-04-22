/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilopes <rilopes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 22:32:46 by rilopes           #+#    #+#             */
/*   Updated: 2025/04/22 03:10:15 by rilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calc_distances(t_cub3d *cub3d, t_ray_calc *ray_calc)
{
	ray_calc->delta_dist.x = safe_double_div_zero(ray_calc->ray.x);
	ray_calc->delta_dist.y = safe_double_div_zero(ray_calc->ray.y);
	ray_calc->step.x = define_step(ray_calc->ray.x);
	ray_calc->step.y = define_step(ray_calc->ray.y);
	if (ray_calc->ray.x < 0)
		ray_calc->side_dist.x = (cub3d->player.x - (int) cub3d->player.x)
			* ray_calc->delta_dist.x;
	else
		ray_calc->side_dist.x = ((int) cub3d->player.x + 1.0 - cub3d->player.x)
			* ray_calc->delta_dist.x;
	if (ray_calc->ray.y < 0)
		ray_calc->side_dist.y = (cub3d->player.y - (int) cub3d->player.y)
			* ray_calc->delta_dist.y;
	else
		ray_calc->side_dist.y = ((int) cub3d->player.y + 1.0 - cub3d->player.y)
			* ray_calc->delta_dist.y;
}

static void	calc_ray(t_cub3d *cub3d, t_ray_calc *ray_calc)
{
	calc_distances(cub3d, ray_calc);
	ray_calc->map = (t_vector){(int) cub3d->player.x, (int) cub3d->player.y};
	while (true)
	{
		if (ray_calc->side_dist.x < ray_calc->side_dist.y)
		{
			ray_calc->side_dist.x += ray_calc->delta_dist.x;
			ray_calc->map.x += ray_calc->step.x;
			ray_calc->side = 0;
		}
		else
		{
			ray_calc->side_dist.y += ray_calc->delta_dist.y;
			ray_calc->map.y += ray_calc->step.y;
			ray_calc->side = 1;
		}
		if (cub3d->map[(int) ray_calc->map.y][(int) ray_calc->map.x] != '0')
			break ;
	}
	draw_ray(cub3d, ray_calc);
}

void	ray_casting(t_cub3d *cub3d)
{
	t_ray_calc	ray_calc;
	double		camera_x;

	ray_calc.x = 0;
	while (ray_calc.x < cub3d->mlx_ptr->width)
	{
		camera_x = (2 * ray_calc.x / (double) cub3d->mlx_ptr->width) - 1;
		ray_calc.ray.x = cub3d->dir_player.x + (cub3d->fov.x * camera_x);
		ray_calc.ray.y = cub3d->dir_player.y + (cub3d->fov.y * camera_x);
		calc_ray(cub3d, &ray_calc);
		ray_calc.x++;
	}
}
