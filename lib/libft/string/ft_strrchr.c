/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:05:19 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/05/23 20:39:09 by pdavi-al         ###   ########.fr       */
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
