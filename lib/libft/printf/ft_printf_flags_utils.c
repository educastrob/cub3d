/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobli <cobli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:44:50 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/09/29 01:11:05 by cobli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf_utils.h"

int	ft_printf_isvalid(char c)
{
	return (ft_printf_istype(c) || ft_isdigit(c) || ft_printf_isflag(c));
}

int	ft_printf_isflag(char c)
{
	if (c == '-' || c == '0' || c == '*' || c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

int	ft_printf_istype(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u' || c == 'x'
		|| c == 'X' || c == 'p' || c == '%')
		return (1);
	return (0);
}

unsigned char	ft_printf_get_flag(char c)
{
	if (c == '-')
		return (MINUS_FLAG_MASK);
	if (c == '0')
		return (ZERO_FLAG_MASK);
	if (c == ' ')
		return (SPACE_FLAG_MASK);
	if (c == '+')
		return (PLUS_FLAG_MASK);
	return (HASH_FLAG_MASK);
}

void	ft_printf_print_spaces(int spaces, char c, int fd)
{
	while (spaces--)
		(void)write(fd, &c, 1);
}
