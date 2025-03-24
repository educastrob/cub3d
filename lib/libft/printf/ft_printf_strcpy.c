#include "printf_utils.h"

void	ft_printf_strcpy(char *dest, char *source, int len)
{
	while (len--)
		dest[len] = source[len];
}
