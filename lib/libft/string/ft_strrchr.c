#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*finded;

	finded = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			finded = (char *)s;
		s++;
	}
	if ((char)c == 0)
		finded = (char *)s;
	return (finded);
}
