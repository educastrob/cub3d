#include "gnl_utils.h"

char	*ft_gnl_strjoin(char *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str_join;

	s1_len = ft_gnl_strlen(s1);
	s2_len = ft_gnl_strlen(s2);
	str_join = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (str_join == NULL)
		return (NULL);
	if (s1 != NULL)
	{
		ft_gnl_strlcpy(str_join, s1, s1_len + 1);
		free(s1);
	}
	ft_gnl_strlcpy(str_join + s1_len, s2, s2_len + 1);
	return (str_join);
}

size_t	ft_gnl_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_gnl_strchr(const char *s, char c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_gnl_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (dest == NULL || src == NULL)
		return (0);
	if (size == 0)
		return (ft_gnl_strlen(src));
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_gnl_strlen(src));
}

void	free_gnl_memory(int fd)
{
	char	**memory;

	memory = get_memory();
	if (memory[fd] != NULL)
	{
		free(memory[fd]);
		memory[fd] = NULL;
	}
}
