/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:28:04 by educastro         #+#    #+#             */
/*   Updated: 2025/02/10 22:32:53 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
	(void)argc; 
	(void)argv;

	t_cub3d	*cub3d;

	start_params(&cub3d);
	// read_map(&cub3d, valid_args(argc, argv));
	// normalize_map()
	// valid_map()
	initialize(&cub3d);
	free_for_finish(&cub3d);

	return (EXIT_SUCCESS);
}
