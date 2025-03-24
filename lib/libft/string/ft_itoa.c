#include "libft.h"

static char		*create_n_str(long n);
static size_t	count_size(long n);

char	*ft_itoa(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	return (create_n_str(n));
}

static char	*create_n_str(long n)
{
	char	*n_str;
	size_t	n_size;

	n_size = count_size(n);
	n_str = malloc((n_size + 1) * sizeof(char));
	if (n_str == NULL)
		return (NULL);
	n_str[n_size] = '\0';
	if (n < 0)
	{
		n_str[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		n_str[--n_size] = "0123456789"[n % 10];
		n /= 10;
	}
	return (n_str);
}

static size_t	count_size(long n)
{
	size_t	n_size;

	n_size = 0;
	if (n < 0)
		n_size++;
	while (n != 0)
	{
		n /= 10;
		n_size++;
	}
	return (n_size);
}
