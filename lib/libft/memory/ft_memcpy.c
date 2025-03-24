#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*ptr_dest;
	const char	*ptr_src;

	ptr_dest = (char *)dest;
	ptr_src = (char *)src;
	while (n--)
		*ptr_dest++ = *ptr_src++;
	return ((void *)dest);
}
