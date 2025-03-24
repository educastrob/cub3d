#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = malloc(1 * sizeof(t_list));
	if (ptr == NULL)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}
