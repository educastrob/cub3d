/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:37:41 by educastro         #+#    #+#             */
/*   Updated: 2025/03/24 13:37:42 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf_utils.h"

int	ft_printf_atoi(const char **nptr)
{
	int	number;

	number = 0;
	while (ft_isdigit(**nptr))
		number = (number * 10) + (*(*nptr)++ - '0');
	return (number);
}
