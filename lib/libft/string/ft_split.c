#include "libft.h"

char	**ft_split(char const *s, char c)
{
	return (ft_split_size(s, c, NULL));
}
