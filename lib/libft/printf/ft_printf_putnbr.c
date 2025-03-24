#include "printf_utils.h"

static void	putnbr(int n, int len, char *str_n, t_element element);
static int	number_len(int n, t_element element);

int	ft_printf_putnbr(int n, t_element element)
{
	int		len;
	char	*str;

	len = number_len(n, element);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	putnbr(n, len, str, element);
	len = ft_printf_printnbr(str, len, element);
	free(str);
	return (len);
}

static void	putnbr(int n, int len, char *str_n, t_element element)
{
	long	nbr;
	int		min_len;

	nbr = n;
	min_len = (nbr < 0 || element.flags & (PLUS_FLAG_MASK | SPACE_FLAG_MASK));
	if (nbr < 0)
	{
		str_n[0] = '-';
		nbr *= -1;
	}
	else if (element.flags & PLUS_FLAG_MASK)
		str_n[0] = '+';
	else if (element.flags & SPACE_FLAG_MASK)
		str_n[0] = ' ';
	str_n[len] = '\0';
	while (min_len < len)
	{
		str_n[--len] = "0123456789"[nbr % 10];
		nbr /= 10;
	}
}

static int	number_len(int n, t_element element)
{
	int	len;
	int	is_neg;

	if (n == 0 && element.precision == 0)
		return (0);
	len = 0;
	is_neg = n < 0;
	if (is_neg || element.flags & (SPACE_FLAG_MASK | PLUS_FLAG_MASK))
		len++;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	if (element.precision >= len)
		return (element.precision + (is_neg
				|| element.flags & (SPACE_FLAG_MASK & PLUS_FLAG_MASK)));
	if (element.precision == -1 && !(element.flags & MINUS_FLAG_MASK)
		&& (element.flags & ZERO_FLAG_MASK) && element.width > len)
		return (element.width);
	return (len);
}
