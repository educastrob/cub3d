/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:37:51 by educastro         #+#    #+#             */
/*   Updated: 2025/03/24 13:37:52 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_ptr;
	const char	*src_ptr;

	dest_ptr = (char *)dest;
	src_ptr = (const char *)src;
	if (dest_ptr == src_ptr)
		return (dest);
	if (src_ptr < dest_ptr && dest_ptr < src_ptr + (sizeof(char) * n))
	{
		src_ptr += (sizeof(char) * n);
		dest_ptr += (sizeof(char) * n);
		while (n--)
			*--dest_ptr = *--src_ptr;
	}
	else
		while (n--)
			*dest_ptr++ = *src_ptr++;
	return (dest);
}
