/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilopes <rilopes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 22:32:46 by rilopes           #+#    #+#             */
/*   Updated: 2025/04/22 03:01:26 by rilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	define_step(double num)
{
	if (num < 0)
		return (-1);
	return (1);
}

double	safe_double_div_zero(double ray)
{
	if (ray == 0)
		return (DBL_MAX);
	return (fabs(1 / ray));
}

uint32_t	rgb_to_int(uint8_t *rgb)
{
	return (rgb[0] << 24 | rgb[1] << 16 | rgb[2] << 8 | rgb[3]);
}
