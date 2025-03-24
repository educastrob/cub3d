#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	if (dest == NULL || src == NULL)
		return (0);
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	j = dest_len;
	if (size <= dest_len)
		return (src_len + size);
	while (src[i] != '\0' && j < size - 1)
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (dest_len + src_len);
}
