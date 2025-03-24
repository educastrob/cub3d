#include "printf_utils.h"

int	ft_printf_putpointer(const void *ptr, t_element element)
{
	if (ptr == NULL)
	{
		element.precision = -1;
		return (ft_printf_putstr("(nil)", element));
	}
	element.flags |= HASH_FLAG_MASK;
	return (ft_printf_putnbr_b((unsigned long)ptr, HEX_L_BASE, element));
}
