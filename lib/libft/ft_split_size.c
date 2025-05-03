/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:37:11 by educastro         #+#    #+#             */
/*   Updated: 2025/03/24 13:37:11 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c);
static char		**split_words(char **words, size_t words_len, char const *s,
					char c);
static size_t	count_letters(char const *s, char c);

char	**ft_split_size(char const *s, char c, size_t *size)
{
	char	**words;
	size_t	words_len;

	words_len = count_words(s, c);
	words = malloc((words_len + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	if (size != NULL)
		*size = words_len;
	return (split_words(words, words_len, s, c));
}

static size_t	count_letters(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char	**split_words(char **words, size_t words_len, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	current_char;

	i = 0;
	current_char = 0;
	while (i < words_len)
	{
		j = 0;
		while (s[current_char] == c)
			current_char++;
		words[i] = malloc((count_letters((s + current_char), c) + 1)
				* sizeof(char));
		if (words[i] == NULL)
			return (NULL);
		while (s[current_char] != c && s[current_char] != '\0')
			words[i][j++] = s[current_char++];
		words[i][j] = '\0';
		i++;
	}
	words[words_len] = NULL;
	return (words);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s[i] != c && s[i] != '\0')
		count++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}
