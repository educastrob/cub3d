/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobli <cobli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:57:10 by cobli             #+#    #+#             */
/*   Updated: 2023/10/02 22:20:35 by cobli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstrm(t_list *lst, t_list *rm_element, void (*del)(void *))
{
	t_list	*head;
	t_list	*prev;

	if (lst == rm_element)
	{
		head = lst->next;
		ft_lstdelone(lst, del);
		return (head);
	}
	head = lst;
	while (lst != NULL)
	{
		prev = lst;
		lst = lst->next;
		if (lst == rm_element)
		{
			prev->next = lst->next;
			ft_lstdelone(lst, del);
			break ;
		}
	}
	return (head);
}
