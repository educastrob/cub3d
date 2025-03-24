#include "libft.h"
#include "printf_utils.h"

int	ft_printf_atoi(const char **nptr)
{
	int	number;

	number = 0;
	while (ft_isdigit(**nptr))
		number = (number * 10) + (*(*nptr)++ - '0');
	return (number);
}
