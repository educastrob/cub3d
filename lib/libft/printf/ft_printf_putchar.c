/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:37:35 by educastro         #+#    #+#             */
/*   Updated: 2025/03/24 13:37:35 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_utils.h"

int	ft_printf_putchar(const char c, t_element element)
{
	int	spaces;

	spaces = element.width - 1;
	if (spaces > 0)
	{
		if (!(element.flags & MINUS_FLAG_MASK))
			ft_printf_print_spaces(spaces, ' ', element.fd);
		else if (element.flags & ZERO_FLAG_MASK)
			ft_printf_print_spaces(spaces, '0', element.fd);
		(void)write(element.fd, &c, 1);
		if (element.flags & MINUS_FLAG_MASK)
			ft_printf_print_spaces(spaces, ' ', element.fd);
		return (element.width);
	}
	(void)write(element.fd, &c, 1);
	return (1);
}
