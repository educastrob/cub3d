#include "libft.h"
#include "printf_utils.h"

static char	*putnbr_base(unsigned long nbr, int len, const char *base,
				t_element element);
static int	number_len_base(unsigned long nbr, int base_len, t_element element);
static void	select_prefix(char *str_n, int *min_len, t_element element);

int	ft_printf_putnbr_b(unsigned long nbr, const char *base, t_element element)
{
	int		len;
	int		base_len;
	char	*str;

	base_len = ft_strlen(base);
	len = number_len_base(nbr, base_len, element);
	str = putnbr_base(nbr, len, base, element);
	if (str == NULL)
		return (0);
	len = ft_printf_printnbr(str, len, element);
	free(str);
	return (len);
}

static char	*putnbr_base(unsigned long nbr, int len, const char *base,
		t_element element)
{
	int		min_len;
	char	*str_n;
	int		base_len;

	str_n = malloc((len + 1) * sizeof(char));
	if (str_n == NULL)
		return (NULL);
	base_len = ft_strlen(base);
	min_len = 0;
	if ((element.flags & HASH_FLAG_MASK) && nbr != 0)
		select_prefix(str_n, &min_len, element);
	str_n[len] = '\0';
	while (min_len < len)
	{
		str_n[--len] = base[nbr % base_len];
		nbr /= base_len;
	}
	return (str_n);
}

static void	select_prefix(char *str_n, int *min_len, t_element element)
{
	(*min_len)++;
	if (element.type == 'x' || element.type == 'p')
		ft_printf_strcpy(str_n, "0x", ++(*min_len));
	else if (element.type == 'o')
		ft_printf_strcpy(str_n, "0", (*min_len));
	else if (element.type == 'X')
		ft_printf_strcpy(str_n, "0X", ++(*min_len));
}

static int	number_len_base(unsigned long nbr, int base_len, t_element element)
{
	int	len;
	int	prefix_len;

	if (nbr == 0 && element.precision == 0)
		return (0);
	prefix_len = 0;
	if ((element.flags & HASH_FLAG_MASK) && nbr != 0)
		prefix_len += 1 + (element.type != 'o');
	len = 0;
	if (nbr == 0)
		len++;
	while (nbr != 0)
	{
		nbr /= base_len;
		len++;
	}
	if (element.precision >= len)
		return (element.precision + prefix_len);
	if (element.precision == -1 && !(element.flags & MINUS_FLAG_MASK)
		&& (element.flags & ZERO_FLAG_MASK) && element.width > len + prefix_len)
		return (element.width);
	return (len + prefix_len);
}
