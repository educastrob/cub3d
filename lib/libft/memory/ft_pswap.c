#include "libft.h"

void	ft_pswap(void **a, void **b)
{
	void	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
