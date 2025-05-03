/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilopes <rilopes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 22:39:16 by rilopes           #+#    #+#             */
/*   Updated: 2025/04/24 22:23:03 by rilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_tex_wall(t_cub3d *cub, t_ray_calc *ray_calc,
	t_draw_wall *draw_wall, mlx_texture_t *texture)
{
	int	y;

	y = draw_wall->draw_start;
	while (y < draw_wall->draw_end)
	{
		draw_wall->tex_y = (int) draw_wall->tex_pos;
		draw_wall->tex_pos += draw_wall->step;
		draw_wall->color = rgb_to_int(&texture->pixels[(texture->height
					* draw_wall->tex_y + draw_wall->tex_x)
				* texture->bytes_per_pixel]);
		mlx_put_pixel(cub->image, ray_calc->x, y, draw_wall->color);
		y++;
	}
}

static void	draw_center_vertical_line(t_cub3d *cub, t_ray_calc *ray_calc,
	mlx_texture_t *texture)
{
	t_draw_wall	draw_wall;

	if (ray_calc->side == 0)
		draw_wall.wall_x = cub->player.y + ray_calc->perp_wall_dist
			* ray_calc->ray.y;
	else
		draw_wall.wall_x = cub->player.x + ray_calc->perp_wall_dist
			* ray_calc->ray.x;
	draw_wall.wall_x -= floor(draw_wall.wall_x);
	draw_wall.tex_x = (int)(draw_wall.wall_x * texture->width);
	draw_wall.line_height = (int)(cub->mlx_ptr->height
			/ ray_calc->perp_wall_dist);
	draw_wall.draw_start = -draw_wall.line_height / 2 + cub->mlx_ptr->height
		/ 2;
	if (draw_wall.draw_start < 0)
		draw_wall.draw_start = 0;
	draw_wall.draw_end = draw_wall.line_height / 2 + cub->mlx_ptr->height / 2;
	if (draw_wall.draw_end >= cub->mlx_ptr->height)
		draw_wall.draw_end = cub->mlx_ptr->height - 1;
	draw_wall.step = (double) texture->height / draw_wall.line_height;
	draw_wall.tex_pos = (draw_wall.draw_start - cub->mlx_ptr->height / 2
			+ draw_wall.line_height / 2) * draw_wall.step;
	draw_tex_wall(cub, ray_calc, &draw_wall, texture);
}

void	draw_ray(t_cub3d *cub, t_ray_calc *ray_calc)
{
	mlx_texture_t	*texture;

	ray_calc->side_dist.x -= ray_calc->delta_dist.x;
	ray_calc->side_dist.y -= ray_calc->delta_dist.y;
	if (ray_calc->side == 0)
		ray_calc->perp_wall_dist = ray_calc->side_dist.x;
	else
		ray_calc->perp_wall_dist = ray_calc->side_dist.y;
	if (ray_calc->side == 0)
	{
		if (ray_calc->ray.x > 0)
			texture = cub->east_texture;
		else
			texture = cub->west_texture;
	}
	else
	{
		if (ray_calc->ray.y > 0)
			texture = cub->south_texture;
		else
			texture = cub->north_texture;
	}
	draw_center_vertical_line(cub, ray_calc, texture);
}

void	draw_background(t_cub3d *cub)
{
	t_vector	vector;

	vector.y = -1;
	while (++vector.y < cub->mlx_ptr->height / 2)
	{
		vector.x = -1;
		while (++vector.x < cub->mlx_ptr->width)
			mlx_put_pixel(cub->image, vector.x, vector.y, cub->ceiling_color);
	}
	while (++vector.y < cub->mlx_ptr->height)
	{
		vector.x = -1;
		while (++vector.x < cub->mlx_ptr->width)
			mlx_put_pixel(cub->image, vector.x, vector.y, cub->floor_color);
	}
}
