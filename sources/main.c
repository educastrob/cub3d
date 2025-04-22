/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilopes <rilopes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:28:04 by educastro         #+#    #+#             */
/*   Updated: 2025/04/22 03:09:27 by rilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_hook(void *param)
{
	t_cub3d	*cub3d;

	cub3d = param;
	draw_background(cub3d);
	ray_casting(cub3d);
	if (mlx_is_key_down(cub3d->mlx_ptr, MLX_KEY_ESCAPE))
		mlx_close_window(cub3d->mlx_ptr);
	if (mlx_is_key_down(cub3d->mlx_ptr, MLX_KEY_W))
		move_player(cub3d, PLAYER_SPEED, 0);
	if (mlx_is_key_down(cub3d->mlx_ptr, MLX_KEY_S))
		move_player(cub3d, -PLAYER_SPEED, 0);
	if (mlx_is_key_down(cub3d->mlx_ptr, MLX_KEY_A))
		move_player(cub3d, -PLAYER_SPEED, 1);
	if (mlx_is_key_down(cub3d->mlx_ptr, MLX_KEY_D))
		move_player(cub3d, -PLAYER_SPEED, -1);
	if (mlx_is_key_down(cub3d->mlx_ptr, MLX_KEY_RIGHT))
		rotate_player(cub3d, PLAYER_ROTATE_SPEED);
	if (mlx_is_key_down(cub3d->mlx_ptr, MLX_KEY_LEFT))
		rotate_player(cub3d, -PLAYER_ROTATE_SPEED);
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

	start_params(&cub3d);
	read_map(&cub3d, valid_args(argc, argv));
	normalize_map(&cub3d);
	valid_map(&cub3d);
	initialize(&cub3d);
	mlx_loop_hook(cub3d.mlx_ptr, ft_hook, &cub3d);
	mlx_loop(cub3d.mlx_ptr);
	free_for_finish(&cub3d);
	mlx_terminate(cub3d.mlx_ptr);
	return (EXIT_SUCCESS);
}
