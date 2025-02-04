/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:26:19 by cobli             #+#    #+#             */
/*   Updated: 2023/10/22 00:23:23 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*select_content(void *content);

void	*ft_lst_to_array(t_list *lst)
{
	return (ft_lst_to_array_choice(lst, select_content));
}

void	*ft_lst_to_array_choice(t_list *lst, void *(*selection)(void *))
{
	size_t	size;
	void	**array;

	if (lst == NULL)
		return (NULL);
	size = ft_lstsize(lst);
	array = ft_calloc(size + 1, sizeof(void *));
	size = 0;
	while (lst != NULL)
	{
		array[size] = selection(lst->content);
		size++;
		lst = lst->next;
	}
	return (array);
}

static void	*select_content(void *content)
{
	return (content);
}
