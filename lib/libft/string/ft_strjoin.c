/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:32:13 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/05/03 23:51:27 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str_join;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str_join = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (str_join == NULL)
		return (NULL);
	ft_strlcpy(str_join, s1, s1_len + s2_len + 1);
	ft_strlcat(str_join, s2, s1_len + s2_len + 1);
	return (str_join);
}
