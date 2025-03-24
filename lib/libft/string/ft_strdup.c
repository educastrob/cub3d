#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	src_len;
	char	*dest;

	src_len = ft_strlen(src);
	dest = malloc((src_len + 1) * sizeof(char));
	if (dest == NULL)
		return (dest);
	ft_strlcpy(dest, src, src_len + 1);
	return (dest);
}
