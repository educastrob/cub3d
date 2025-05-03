/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:37:01 by educastro         #+#    #+#             */
/*   Updated: 2025/03/24 13:37:02 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcpy(char *dest, char *source, int len)
{
	while (*dest != '\0' && *source != '\0' && len--)
		*(dest++) = *(source++);
	if (*source == '\0')
		*dest = '\0';
}
