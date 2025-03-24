#include "printf_utils.h"

int	ft_printf_printnbr(char *str_n, int len, t_element element)
{
	int	spaces;

	spaces = element.width - len;
	if (spaces > 0)
	{
		if (!(element.flags & MINUS_FLAG_MASK))
			ft_printf_print_spaces(spaces, ' ', element.fd);
		while (*str_n != '\0')
			(void)write(element.fd, str_n++, 1);
		if (element.flags & MINUS_FLAG_MASK)
			ft_printf_print_spaces(spaces, ' ', element.fd);
		return (element.width);
	}
	while (*str_n != '\0')
		(void)write(element.fd, str_n++, 1);
	return (len);
}
