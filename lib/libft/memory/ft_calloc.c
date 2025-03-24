#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	if ((nmemb * size != 0) && ((nmemb * size) / size != nmemb))
		return (NULL);
	arr = malloc(nmemb * size);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, nmemb * size);
	return (arr);
}
