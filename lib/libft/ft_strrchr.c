/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:36:28 by educastro         #+#    #+#             */
/*   Updated: 2025/03/24 13:36:28 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*finded;

	finded = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			finded = (char *)s;
		s++;
	}
	if ((char)c == 0)
		finded = (char *)s;
	return (finded);
}
