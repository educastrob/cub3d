/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putpointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:37:28 by educastro         #+#    #+#             */
/*   Updated: 2025/03/24 13:37:29 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_utils.h"

int	ft_printf_putpointer(const void *ptr, t_element element)
{
	if (ptr == NULL)
	{
		element.precision = -1;
		return (ft_printf_putstr("(nil)", element));
	}
	element.flags |= HASH_FLAG_MASK;
	return (ft_printf_putnbr_b((unsigned long)ptr, HEX_L_BASE, element));
}
