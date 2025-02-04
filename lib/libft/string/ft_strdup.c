/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:06:33 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/05/03 23:51:20 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	src_len;
	char	*dest;

	src_len = ft_strlen(src);
	dest = malloc((src_len + 1) * sizeof(char));
	if (dest == NULL)
		return (dest);
	ft_strlcpy(dest, src, src_len + 1);
	return (dest);
}
