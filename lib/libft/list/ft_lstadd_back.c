#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (lst != NULL)
	{
		ptr = ft_lstlast(*lst);
		if (ptr != NULL)
			ptr->next = new;
		else
			*lst = new;
	}
}
