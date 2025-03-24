#include "libft.h"

void	ft_strcpy(char *dest, char *source, int len)
{
	while (*dest != '\0' && *source != '\0' && len--)
		*(dest++) = *(source++);
	if (*source == '\0')
		*dest = '\0';
}
