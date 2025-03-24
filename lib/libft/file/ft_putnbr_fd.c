#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar_fd('-', fd);
	}
	if (nbr / 10 > 0)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd("0123456789"[nbr % 10], fd);
}
