/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 04:05:39 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/07/23 15:55:26 by pdavi-al         ###   ########.fr       */
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
